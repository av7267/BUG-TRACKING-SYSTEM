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
    // TODO: Implement API call or database fetch logic
    qDebug() << "fetchItemTypes() called, but not yet implemented.";
}

void CreateItem::handleDescription() {
   
    QString itemType = ui->comboBox_itemType->currentText();
    QString itemStatus = ui->comboBox_itemStatus->currentText();
    QString description = ui->lineEdit_description->text();
    QString featureType = ui->comboBox_featureType->currentText();
    QString level = ui->comboBox_level->currentText();

    if (description.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation Error", "Description cannot be empty.");
        return;
    }
    
    QJsonObject json;
    json["item_type"] = itemType;
    json["item_status"] = itemStatus;
    json["description"] = description;
    json["feature_type"] = featureType;
    json["level"] = level;

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
            if (parentWidget()) parentWidget()->show();
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
    if (parentWidget()) parentWidget()->show();
    event->accept();
}

