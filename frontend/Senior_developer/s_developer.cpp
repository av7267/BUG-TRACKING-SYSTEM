#include <QStandardItemModel>
#include <QUrlQuery>
#include "s_developer.h"
#include <QMessageBox>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QAbstractItemModel>
#include <QJsonDocument>
#include <QJsonArray>
#include "ui_s_developer.h"
#include "ui_dialogue.h"


ActivityWindow::ActivityWindow(int developerId, QWidget *parent)
    : QMainWindow(parent),
        ui(new Ui::ActivityWindow),
        developerId(developerId)
{
    ui -> setupUi(this);
    manager = new QNetworkAccessManager(this);
    connect(ui->pushButton_edit, &QPushButton::clicked, this, &ActivityWindow::handleedit);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &ActivityWindow::fetchItems);
    connect(ui->assign_developers, &QPushButton::clicked, this, &ActivityWindow::assignDevelopers);

    QPushButton *quitButton = new QPushButton("Quit", this);
    ui->verticalLayout->addWidget(quitButton);
    connect(quitButton, &QPushButton::clicked, qApp, &QCoreApplication::quit, Qt::QueuedConnection);

}

ActivityWindow::~ActivityWindow()

{  
    delete ui;
}



void ActivityWindow::assignDevelopers() 
{
    QModelIndex index = ui->tableView->currentIndex();
    if(!index.isValid()) {
        QMessageBox::warning(this,"Error","select a row to assign");
        return;
    }

    QAbstractItemModel *model = ui->tableView->model();
    int row = index.row();

    QString id = model->index(row,0).data().toString();

    if(id.isEmpty() || id=="0") {
        QMessageBox::warning(this,"Error","Invalid ID");
        return;
    }
    
}


void ActivityWindow::handleedit()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Error", "Select a row to edit.");
        return;
    } 

    QAbstractItemModel *model = ui->tableView->model();
    int row = index.row();
    QString id = model->index(row, 0).data().toString();

    if (id.isEmpty() || id == "0") {
        QMessageBox::warning(this, "Error", "Invalid or missing ID. Cannot update.");
        return;
    }

    QString item_status = model->index(row, 2).data().toString();

    QDialog dialog(this);
    Ui::EditDialog editui;
    editui.setupUi(&dialog);

    editui.comboBox_itemStatus->setCurrentText(item_status);

    connect(editui.buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(editui.buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject json;
        json["description_id"] = id.toInt();
        json["item_status"] = editui.comboBox_itemStatus->currentText();

        QNetworkRequest request(QUrl("http://localhost:18080/api/edit"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QNetworkReply *reply = manager->post(request, QJsonDocument(json).toJson());

        connect(reply, &QNetworkReply::finished, [this, reply]() {
            if (reply->error() == QNetworkReply::NoError) {
                QMessageBox::information(this, "Success", "Item status updated successfully.");
                fetchItems();
            } else {
                QMessageBox::warning(this, "Error", "Update failed: " + reply->errorString());
            }
            reply->deleteLater();
        });
    }
}

void ActivityWindow::fetchItems()
{
    QUrl url("http://localhost:18080/api/assigned-to");
    QUrlQuery query;
    query.addQueryItem("id", QString::number(this->developerId));  // developerId must be a member variable
    url.setQuery(query);

    qDebug() << "Fetching from URL: " << url.toString();

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply]() 
    {
        if (reply->error() == QNetworkReply::NoError)
        {
            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            qDebug() << "Response JSON:" << doc.toJson(QJsonDocument::Indented);

            QJsonArray arr = doc.object()["assigned_bugs"].toArray();

            QStandardItemModel *model = new QStandardItemModel(arr.size(), 4, this);
            model->setHorizontalHeaderLabels({"ID", "Item Type", "Item Status", "Description"});

            for (int i = 0; i < arr.size(); ++i)
            {
                QJsonObject obj = arr[i].toObject();
                model->setItem(i, 0, new QStandardItem(QString::number(obj["description_id"].toInt())));
                model->setItem(i, 1, new QStandardItem(obj["item_type"].toString()));
                model->setItem(i, 2, new QStandardItem(obj["item_status"].toString())); 
                model->setItem(i, 3, new QStandardItem(obj["description"].toString()));
            }

            ui->tableView->setModel(model);
            ui->tableView->setColumnHidden(0, true);
            ui->tableView->resizeRowsToContents();
            ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch); 
        }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to fetch: " + reply->errorString());
        }

        reply->deleteLater();
    });
}
