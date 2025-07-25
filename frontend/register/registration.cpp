#include "registration_window.h"
#include <QMessageBox>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QLabel>
#include <QPushButton>
#include "../login/login_window.h"
#include "../Home/home_window.h"
#include "ui_registration.h"
#include "../Senior_Tester/s_tester.h"
#include "../Senior_developer/s_developer.h"




registrationwindow::registrationwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::registrationwindow)
{
    ui->setupUi(this);
    manager = new QNetworkAccessManager(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &registrationwindow::handleregister);
    connect(ui->label_loginlink, &QLabel::linkActivated, this, &registrationwindow::loginreroute);
}

registrationwindow::~registrationwindow() {
    delete ui;
}

void registrationwindow::handleregister() {
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString role = ui->comboBox->currentText();

    if (username.isEmpty() || password.isEmpty() || role.isEmpty()) {
        QMessageBox::warning(this, "Registration Failed", "All fields are required.");
        return;
    }

    QJsonObject json;
    json["username"] = username;
    json["password"] = password;
    json["role"] = role;

    
    QUrl url("http://localhost:18080/register");
    QNetworkRequest request;

    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *reply = manager->post(request, QJsonDocument(json).toJson());

    connect(reply, &QNetworkReply::finished, this, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray responseData = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(responseData);
            QJsonObject obj = jsonResponse.object();
            int user_id = obj["user_id"].toInt();
            QMessageBox::information(this, "Success", obj["message"].toString());

            QWidget *homeWindow = nullptr;
            if (role == "Senior Tester") {
                homeWindow = new SeniorTesterWindow(nullptr, user_id);
            } else if (role == "Senior Developer") {
                homeWindow = new ActivityWindow(user_id);
            }

            if (homeWindow) {
                homeWindow->setAttribute(Qt::WA_DeleteOnClose);
                homeWindow->show();
                this->close();
            }
        } else {
            QMessageBox::critical(this, "Error", reply->errorString());
        }

        reply->deleteLater();
    });
}

void registrationwindow::loginreroute() {
    auto *logwindow = new LoginWindow();
    logwindow->setAttribute(Qt::WA_DeleteOnClose);
    logwindow->show();
    this ->close();

}