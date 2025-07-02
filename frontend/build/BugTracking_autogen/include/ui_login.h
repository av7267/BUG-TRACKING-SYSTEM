/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QFormLayout *formLayout;
    QLabel *label_username;
    QLineEdit *lineEdit_username;
    QLabel *label_password;
    QLineEdit *lineEdit_password;
    QLabel *label_role;
    QComboBox *comboBox_role;
    QPushButton *pushButton;
    QLabel *label_loginlink;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(360, 320);
        MainWindow->setMinimumSize(QSize(600, 600));
        MainWindow->setMaximumSize(QSize(600, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit {\n"
"    min-height: 32px;\n"
"    border-radius: 2px;\n"
"    border-style: solid;\n"
"    border-width: 1px;\n"
"    border-color: rgba(0, 0, 0, 64);\n"
"    margin-top: 4px;\n"
"    margin-bottom: 4px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border-color: rgba(0, 147, 196, 217);\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border-color: rgba(0, 0, 0, 102);\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    border-color: rgba(0, 0, 0, 64);\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"    color: rgba(0, 0, 0, 128);\n"
"}\n"
"     "));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label_title = new QLabel(centralwidget);
        label_title->setObjectName("label_title");
        label_title->setAlignment(Qt::AlignCenter);
        label_title->setStyleSheet(QString::fromUtf8("QLabel { font-size:20px; font-weight:bold; }"));

        verticalLayout->addWidget(label_title);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_username = new QLabel(centralwidget);
        label_username->setObjectName("label_username");
        label_username->setStyleSheet(QString::fromUtf8("QLabel { font-size:18px; }"));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_username);

        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_username);

        label_password = new QLabel(centralwidget);
        label_password->setObjectName("label_password");
        label_password->setStyleSheet(QString::fromUtf8("QLabel { font-size:18px; }"));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_password);

        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_password);

        label_role = new QLabel(centralwidget);
        label_role->setObjectName("label_role");
        label_role->setStyleSheet(QString::fromUtf8("QLabel { font-size:18px; }"));

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_role);

        comboBox_role = new QComboBox(centralwidget);
        comboBox_role->addItem(QString());
        comboBox_role->addItem(QString());
        comboBox_role->addItem(QString());
        comboBox_role->addItem(QString());
        comboBox_role->setObjectName("comboBox_role");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboBox_role);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(80, 28));
        pushButton->setMaximumSize(QSize(120, 35));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton { font-size:15px; }"));

        verticalLayout->addWidget(pushButton, 0, Qt::AlignHCenter);

        label_loginlink = new QLabel(centralwidget);
        label_loginlink->setObjectName("label_loginlink");
        label_loginlink->setTextFormat(Qt::RichText);
        label_loginlink->setTextInteractionFlags(Qt::TextBrowserInteraction);
        label_loginlink->setOpenExternalLinks(false);

        verticalLayout->addWidget(label_loginlink, 0, Qt::AlignHCenter);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        label_title->setText(QCoreApplication::translate("LoginWindow", "Login User", nullptr));
        label_username->setText(QCoreApplication::translate("LoginWindow", "Username", nullptr));
        label_password->setText(QCoreApplication::translate("LoginWindow", "Password", nullptr));
        label_role->setText(QCoreApplication::translate("LoginWindow", "Role", nullptr));
        comboBox_role->setItemText(0, QCoreApplication::translate("LoginWindow", "Senior Tester", nullptr));
        comboBox_role->setItemText(1, QCoreApplication::translate("LoginWindow", "Developer", nullptr));
        comboBox_role->setItemText(2, QCoreApplication::translate("LoginWindow", "Senior Developer", nullptr));
        comboBox_role->setItemText(3, QCoreApplication::translate("LoginWindow", "Tester", nullptr));

        pushButton->setText(QCoreApplication::translate("LoginWindow", "Login", nullptr));
        label_loginlink->setText(QCoreApplication::translate("LoginWindow", "Don't have an account? <a href=\"register\">Click here</a>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
