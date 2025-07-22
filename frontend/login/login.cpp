#include "login_window.h"   
#include "ui_login.h"   
#include "../register/registration_window.h"    
#include <QMessageBox>  
#include <QNetworkRequest>  
#include <QNetworkReply>    
#include <QJsonObject>  
#include <QJsonDocument>
#include "../Senior_Tester/s_tester.h"
#include "../Senior_developer/s_developer.h"

LoginWindow :: LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui -> setupUi(this);
    manager = new QNetworkAccessManager(this);

    connect(ui -> pushButton, &QPushButton::clicked,this,&LoginWindow::handleLogin);
    connect(ui->label_loginlink, &QLabel::linkActivated, this, &LoginWindow::reroute);
}

LoginWindow :: ~LoginWindow() {
    delete ui;
};

void LoginWindow::handleLogin() {
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString selectedRole = ui->comboBox_role->currentText();

    if (username.isEmpty() || password.isEmpty()) {
        QMessageBox::warning(this, "Login Failed", "Username or Password cannot be empty.");
        return;
    }
    if(password.length() < 6) {
        QMessageBox::warning(this,"Login Failed","Password must be at least 6 characters.");
        return;
    }

    QJsonObject jsonObject;
    jsonObject["username"] = username;
    jsonObject["password"] = password;

    QUrl url("http://localhost:18080/login");
    QNetworkRequest request;
    request.setUrl(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");

    QNetworkReply *reply = manager->post(request, QJsonDocument(jsonObject).toJson());
    connect(reply, &QNetworkReply::finished, this, [this, reply, selectedRole]() {
        QByteArray responseData = reply->readAll();
        qDebug() << "Raw response:" << responseData;
        QJsonDocument doc = QJsonDocument::fromJson(responseData);

        if (!doc.isObject()) {
            QMessageBox::warning(this, "Login Failed", "Invalid response from server.");
            reply->deleteLater();
            return;
        }

        QJsonObject obj = doc.object();

        if (!obj.contains("message") || obj["message"].toString() != "Login successful") {
            QMessageBox::warning(this, "Login Failed", obj["message"].toString());
            reply->deleteLater();
            return;
        }

        int user_id = obj["user_id"].toInt();
        QString role = obj["role"].toString();

        if (selectedRole != role) {
            QMessageBox::warning(this, "Login Failed", "You are not authorized for the selected role.");
            reply->deleteLater();
            return;
        }

        QWidget *homePage = nullptr;
        if (role == "Senior Tester") {
            homePage = new SeniorTesterWindow();
        } else if (role == "Senior Developer") {
            homePage = new ActivityWindow(user_id);
        }

        if (homePage) {
            homePage->setAttribute(Qt::WA_DeleteOnClose);
            homePage->show();
            this->close();
        }
        reply->deleteLater();
    });
}

void LoginWindow :: reroute() {
    auto *regWindow = new registrationwindow();
    regWindow->setAttribute(Qt::WA_DeleteOnClose);
    regWindow->show();
    this -> close();
}
