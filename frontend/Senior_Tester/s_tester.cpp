#include <QMessageBox>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QAbstractItemModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <QUrlQuery>
#include <QStandardItemModel>
#include <QStandardItem>
#include "../Senior_Tester/s_tester.h"
#include "ui_feature_dialogue.h"
#include "ui_s_tester.h"
#include "ui_assign_dialogue.h"
#include "../Home/home_window.h"


SeniorTesterWindow::SeniorTesterWindow(QWidget *parent, int user_id)
    : QMainWindow(parent),
      ui(new Ui::SeniorTesterWindow),
      seniorTesterId(user_id)
{
    qDebug() << "Senior Tester ID set to:" << seniorTesterId;
    ui->setupUi(this);

    manager = new QNetworkAccessManager(this);
    connect(ui->pushButton_assign, &QPushButton::clicked, this, &SeniorTesterWindow::assignBugs); //assign
    connect(ui->pushButton_addFeature, &QPushButton::clicked, this, &SeniorTesterWindow::addFeature); //update
    connect(ui->deleteButton, &QPushButton::clicked,this,&SeniorTesterWindow::DeleteBug);     //delete
    connect(ui->pushButton_2, &QPushButton::clicked, this, &SeniorTesterWindow::fetchBugs);  //Ok
    connect(ui->pushButton_create, &QPushButton::clicked,this,&SeniorTesterWindow::CreateBug);

    QPushButton *quitButton = new QPushButton("Quit", this);
    ui->verticalLayout->addWidget(quitButton);
    connect(quitButton, &QPushButton::clicked, qApp, &QCoreApplication::quit, Qt::QueuedConnection);

    
}
SeniorTesterWindow :: ~SeniorTesterWindow()
{
    delete ui;
}

void SeniorTesterWindow::addFeature()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Error", "Select a row to edit");
        return;
    }

    QAbstractItemModel *model = ui->tableView->model();
    int row = index.row();

    QString id = model->index(row, 0).data().toString();
    if (id.isEmpty() || id == "0") {
        QMessageBox::warning(this, "Error", "Invalid or missing ID. Cannot update.");
        return;
    }

    QString item_type = model->index(row, 1).data().toString();
    QString item_status = model->index(row, 2).data().toString();
    QString feature_type = model->index(row, 3).data().toString();
    QString description = model->index(row, 4).data().toString();

    QDialog dialog(this);
    dialog.setWindowTitle("Edit Bug Details");

    Ui::FeatureDialog editui;
    editui.setupUi(&dialog);

    editui.lineEdit_type->setText(item_type);
    editui.comboBox_featureType->setCurrentText(feature_type);
    editui.comboBox_itemStatus->setCurrentText(item_status);
    editui.lineEdit_description->setText(description);

    connect(editui.buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(editui.buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() == QDialog::Accepted) {
        QJsonObject json;
        json["description_id"] = id.toInt();
        json["feature_type"] = editui.comboBox_featureType->currentText();
        json["item_type"] = editui.lineEdit_type->text();
        json["item_status"] = editui.comboBox_itemStatus->currentText();
        json["description"] = editui.lineEdit_description->toPlainText();

        qDebug() << "Sending Id:" << id;
        qDebug() << QJsonDocument(json).toJson(QJsonDocument::Indented);

        QNetworkRequest request(QUrl("http://localhost:18080/api/edit"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QNetworkReply *reply = manager->post(request, QJsonDocument(json).toJson());

        connect(reply, &QNetworkReply::finished, [this, reply]() {
            qDebug() << reply->readAll();

            if (reply->error() == QNetworkReply::NoError) {
                QMessageBox::information(this, "Success", "Item updated successfully.");
                fetchBugs();
            } else {
                QMessageBox::warning(this, "Error", "Update failed: " + reply->errorString());
            }
            reply->deleteLater();
        });
    }
}
    
void SeniorTesterWindow:: DeleteBug(){
    int row = ui->tableView->currentIndex().row();
    QAbstractItemModel *model = ui->tableView->model();
    QString id = model-> index(row,0).data().toString();

    QJsonObject json;
    json["description_id"] = id.toInt();

    QNetworkRequest request(QUrl("http://localhost:18080/api/delete"));
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    QNetworkReply *reply=manager->post(request,QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished,[this,reply]() {
        if(reply->error() == QNetworkReply::NoError)
        {
            QMessageBox::information(this,"Success","Item deleted successfully");
            fetchBugs();
        }
        else{
            QMessageBox::warning(this,"Error","delete failed: " + reply->errorString());
        }
        reply->deleteLater();
    });

}

void SeniorTesterWindow::fetchBugs()
{
    
    QString selectedStatus = ui->comboBox_itemStatus->currentText();

    QUrl url("http://localhost:18080/api/description/by-status");
    QUrlQuery query;
    query.addQueryItem("status", selectedStatus);
    url.setQuery(query);

    qDebug() << "Fetching from URL: " << url.toString();

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, this, [this, reply, selectedStatus]() 
    {
        
        if (reply->error() == QNetworkReply::NoError)
        {
            QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
            qDebug()<<"Response JSON:" << doc.toJson(QJsonDocument::Indented);

            QJsonArray arr = doc.object()["items"].toArray();

            QStandardItemModel *model = new QStandardItemModel(arr.size(), 5, this);
            model->setHorizontalHeaderLabels({"ID", "Item Type", "Item Status", "Feature Type", "Description"});

            for (int i = 0; i < arr.size(); ++i)
            {
                QJsonObject obj = arr[i].toObject();
                model->setItem(i, 0, new QStandardItem(QString::number(obj["description_id"].toInt())));
                model->setItem(i, 1, new QStandardItem(obj["item_type"].toString()));
                model->setItem(i, 2, new QStandardItem(obj["item_status"].toString()));
                model->setItem(i, 3, new QStandardItem(obj["feature_type"].toString()));
                model->setItem(i, 4, new QStandardItem(obj["description"].toString()));
            }

            
            ui->tableView->setModel(model);
            disconnect(ui->tableView->selectionModel(), nullptr, this, nullptr);
            connect(ui->tableView->selectionModel(), &QItemSelectionModel::currentChanged,
                    this, &SeniorTesterWindow::handleselection);
            ui->pushButton_assign->setVisible(false);
            ui->tableView->setColumnHidden(0, true);
            ui->tableView->setColumnHidden(1, !selectedStatus.isEmpty());
            ui->tableView->resizeRowsToContents();
            ui->tableView->horizontalHeader() -> setSectionResizeMode(QHeaderView::Stretch); 
        }
        else
        {
            QMessageBox::warning(this, "Error", "Failed to fetch: " + reply->errorString());
        }

        reply->deleteLater();
    });

};

void SeniorTesterWindow::assignBugs()
{
    QModelIndex index = ui->tableView->currentIndex();
    if (!index.isValid()) {
        QMessageBox::warning(this, "Error", "Select a row to assign");
        return;
    }

    QAbstractItemModel *model = ui->tableView->model();
    int row = index.row();
    QString id = model->index(row, 0).data().toString();

    if (id.isEmpty() || id == "0") {
        QMessageBox::warning(this, "Error", "Invalid ID");
        return;
    }

    QDialog dialog(this);
    Ui::AssignDialog assignUi;
    assignUi.setupUi(&dialog);

    QUrl url("http://localhost:18080/api/seniordevelopers");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *reply = manager->get(request);

    connect(assignUi.buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(assignUi.buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();

    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::warning(this, "Error", "Failed to fetch Senior developers: " + reply->errorString());
        reply->deleteLater();
        return;
    }

    QByteArray responseData = reply->readAll();
    reply->deleteLater();

    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    QJsonArray developersArray = doc.object()["developers"].toArray();

    assignUi.comboBox_developer->clear();
    for (const auto &developerVal : developersArray) {
        QJsonObject developerObj = developerVal.toObject();
        QString developerName = developerObj["username"].toString();
        int developerId = developerObj["id"].toInt();
        assignUi.comboBox_developer->addItem(developerName, developerId);
    }

    if (dialog.exec() == QDialog::Accepted) {
        int selectedDeveloperId = assignUi.comboBox_developer->currentData().toInt();
        if (selectedDeveloperId == 0) {
            QMessageBox::warning(this, "Error", "Selected developer is invalid.");
            return;
        }

        int descriptionId = id.toInt();  

        QJsonObject json;
        json["description_id"] = descriptionId;
        json["assigned_to"] = selectedDeveloperId;
        json["assigned_by"] = this->seniorTesterId;

        QNetworkRequest assignRequest(QUrl("http://localhost:18080/api/assign"));
        assignRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QNetworkReply *assignReply = manager->post(assignRequest, QJsonDocument(json).toJson());

        connect(assignReply, &QNetworkReply::finished, [this, assignReply, descriptionId]() {
            if (assignReply->error() == QNetworkReply::NoError) {
                QMessageBox::information(this, "Success", "Bug assigned successfully.");

                // Now update status to "Committed"
                QJsonObject updateStatus;
                updateStatus["description_id"] = descriptionId;
                updateStatus["new_status"] = "Committed";

                QNetworkRequest statusRequest(QUrl("http://localhost:18080/api/update-status"));
                statusRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

                QNetworkReply *statusReply = manager->post(statusRequest, QJsonDocument(updateStatus).toJson());

                connect(statusReply, &QNetworkReply::finished, [statusReply]() {
                    if (statusReply->error() == QNetworkReply::NoError) {
                        qDebug() << "Status updated to Committed.";
                    } else {
                        qDebug() << "Failed to update status: " << statusReply->errorString();
                    }
                    statusReply->deleteLater();
                });

                fetchBugs();
            } else {
                QMessageBox::warning(this, "Error", "Assignment failed: " + assignReply->errorString());
            }
            assignReply->deleteLater();
        });
    }
}

void SeniorTesterWindow::handleselection(const QModelIndex &current,const QModelIndex &previous)
{
    Q_UNUSED(previous);

    if(!current.isValid())
    {
        ui->pushButton_assign ->setVisible(false);
        return;

    }
    QAbstractItemModel *model = ui->tableView->model();
    int row = current.row();

    QString status = model -> index(row,2).data().toString();
    ui->pushButton_assign->setVisible(status == "in progress");

}

void SeniorTesterWindow::CreateBug()
{
    auto *createwindow = new CreateItem();
    createwindow->setAttribute(Qt::WA_DeleteOnClose);
    createwindow->show();
    this->close();

}