#include "home_window.h"
#include "ui_createbug.h"
#include <QMessageBox>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include "../Senior_Tester/s_tester.h"
#include <QCloseEvent>

CreateItem::CreateItem(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreateItem)
    , manager(new QNetworkAccessManager(this))
{
    ui->setupUi(this);
    fetchItemTypes();
    connect(ui->pushButton_3, &QPushButton::clicked, this, &CreateItem::handleDescription);

    QPushButton *quitButton = new QPushButton("Quit", this);
    ui->verticalLayout->addWidget(quitButton);
    connect(quitButton, &QPushButton::clicked, qApp, &QCoreApplication::quit, Qt::QueuedConnection);
    
}

CreateItem::~CreateItem()
{
    delete ui;
}

void CreateItem::fetchItemTypes() {
    QUrl url("http://172.30.1.56:18080/api/item-types");
    QNetworkRequest request(url);

    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, this, [this, reply]()
    {
        if (reply->error() == QNetworkReply::NoError) 
        {
            QJsonDocument jsonDoc = QJsonDocument::fromJson(reply->readAll());
            if (jsonDoc.isObject()) {
                QJsonObject jsonObj = jsonDoc.object();
                QJsonArray typesArray = jsonObj["types"].toArray();
                ui->comboBox_itemType->clear();
                for (const QJsonValue &val : typesArray) 
                {
                    ui->comboBox_itemType->addItem(val.toString());
                }
            }
        } 
        else 
        { 
            qDebug() << "Error fetching item types:" << reply->errorString();         
        }
        
        reply->deleteLater();
    
    });
}


void CreateItem::handleDescription() {
   
    QString itemType = ui->comboBox_itemType->currentText();
    QString itemStatus = ui->comboBox_itemStatus->currentText();
    QString description = ui->lineEdit_description->text();
    QString featureType = ui->comboBox_featureType->currentText();  // Assuming this exists

    if (description.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation Error", "Description cannot be empty.");
        return;
    }
    
    QJsonObject json;
    json["item_type"] = itemType;
    json["item_status"] = itemStatus;
    json["description"] = description;
    json["feature_type"] = featureType;

    QUrl url("http://localhost:18080/api/description");
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply  = manager->post(request,QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [this, reply]() 
    {

        if (reply->error() == QNetworkReply::NoError) 
        {
            QMessageBox::information(nullptr, "Success", "Description submitted successfully!");
            auto *EditWindow = new SeniorTesterWindow();
            EditWindow->setAttribute(Qt::WA_DeleteOnClose);
            EditWindow->show();
            this->close();  
        } 
        else {

            qDebug() << "Failed to submit description:" << reply->errorString();
                qDebug() << "Server response:" << reply->readAll();  // 🔥 THIS IS IMPORTANT

        }
        reply->deleteLater();
    });
}

void CreateItem::closeEvent(QCloseEvent *event) {
    auto *activity = new SeniorTesterWindow();
    activity->setAttribute(Qt::WA_DeleteOnClose);
    activity->show();
    event->accept();
}