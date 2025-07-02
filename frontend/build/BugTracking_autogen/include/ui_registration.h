/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_registrationwindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_title;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLabel *label_loginlink;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *registrationwindow)
    {
        if (registrationwindow->objectName().isEmpty())
            registrationwindow->setObjectName("registrationwindow");
        registrationwindow->resize(600, 600);
        registrationwindow->setMinimumSize(QSize(600, 600));
        registrationwindow->setMaximumSize(QSize(600, 600));
        centralwidget = new QWidget(registrationwindow);
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
"QLineEdit:focus {\n"
"    border-color: rgba(0, 147, 196, 217);\n"
"}\n"
"QLineEdit:hover {\n"
"    border-color: rgba(0, 0, 0, 102);\n"
"}\n"
"QLineEdit:disabled {\n"
"    border-color: rgba(0, 0, 0, 64);\n"
"    background-color: rgba(255, 255, 255, 128);\n"
"    color: rgba(0, 0, 0, 128);\n"
"}\n"
"    "));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label_title = new QLabel(centralwidget);
        label_title->setObjectName("label_title");
        label_title->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size:18px;\n"
"font-weight:bold;\n"
"}\n"
""));
        label_title->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_title);

        formLayout = new QFormLayout();
        formLayout->setSpacing(12);
        formLayout->setObjectName("formLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("QLabel { font-size:16px; }"));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label);

        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("QLabel { font-size:16px; }"));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_2);

        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_3);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboBox);


        verticalLayout->addLayout(formLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"font-size:15px\n"
"}"));

        verticalLayout->addWidget(pushButton, 0, Qt::AlignHCenter);

        label_loginlink = new QLabel(centralwidget);
        label_loginlink->setObjectName("label_loginlink");
        label_loginlink->setTextFormat(Qt::RichText);
        label_loginlink->setTextInteractionFlags(Qt::TextBrowserInteraction);
        label_loginlink->setOpenExternalLinks(false);

        verticalLayout->addWidget(label_loginlink);

        registrationwindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(registrationwindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 37));
        registrationwindow->setMenuBar(menubar);
        statusbar = new QStatusBar(registrationwindow);
        statusbar->setObjectName("statusbar");
        registrationwindow->setStatusBar(statusbar);

        retranslateUi(registrationwindow);

        QMetaObject::connectSlotsByName(registrationwindow);
    } // setupUi

    void retranslateUi(QMainWindow *registrationwindow)
    {
        registrationwindow->setWindowTitle(QCoreApplication::translate("registrationwindow", "Register", nullptr));
        label_title->setText(QCoreApplication::translate("registrationwindow", "Register User", nullptr));
        label->setText(QCoreApplication::translate("registrationwindow", "Username", nullptr));
        label_2->setText(QCoreApplication::translate("registrationwindow", "Password", nullptr));
        label_3->setText(QCoreApplication::translate("registrationwindow", "Role", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("registrationwindow", "Senior Developer", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("registrationwindow", "Developer", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("registrationwindow", "Senior Tester", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("registrationwindow", "Tester", nullptr));

        pushButton->setText(QCoreApplication::translate("registrationwindow", "Register", nullptr));
        label_loginlink->setText(QCoreApplication::translate("registrationwindow", "Already have an account? <a href=\"login\">Login</a>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class registrationwindow: public Ui_registrationwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
