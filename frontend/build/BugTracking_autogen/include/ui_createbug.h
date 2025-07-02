/********************************************************************************
** Form generated from reading UI file 'createbug.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEBUG_H
#define UI_CREATEBUG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateItem
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_itemType;
    QComboBox *comboBox_itemType;
    QLabel *label_itemStatus;
    QComboBox *comboBox_itemStatus;
    QLabel *label_itemStatus_feature;
    QComboBox *comboBox_featureType;
    QLabel *label_description;
    QLineEdit *lineEdit_description;
    QHBoxLayout *horizontalLayout_buttons;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_3;
    QLabel *label_message;

    void setupUi(QMainWindow *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName("home");
        home->resize(600, 600);
        home->setMinimumSize(QSize(600, 600));
        home->setMaximumSize(QSize(600, 600));
        centralwidget = new QWidget(home);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);

        verticalLayout->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_itemType = new QLabel(centralwidget);
        label_itemType->setObjectName("label_itemType");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_itemType);

        comboBox_itemType = new QComboBox(centralwidget);
        comboBox_itemType->setObjectName("comboBox_itemType");
        comboBox_itemType->setMinimumWidth(200);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboBox_itemType);

        label_itemStatus = new QLabel(centralwidget);
        label_itemStatus->setObjectName("label_itemStatus");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_itemStatus);

        comboBox_itemStatus = new QComboBox(centralwidget);
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->setObjectName("comboBox_itemStatus");
        comboBox_itemStatus->setMinimumWidth(200);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboBox_itemStatus);

        label_itemStatus_feature = new QLabel(centralwidget);
        label_itemStatus_feature->setObjectName("label_itemStatus_feature");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_itemStatus_feature);

        comboBox_featureType = new QComboBox(centralwidget);
        comboBox_featureType->addItem(QString());
        comboBox_featureType->addItem(QString());
        comboBox_featureType->addItem(QString());
        comboBox_featureType->addItem(QString());
        comboBox_featureType->addItem(QString());
        comboBox_featureType->setObjectName("comboBox_featureType");
        comboBox_featureType->setMinimumWidth(200);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboBox_featureType);

        label_description = new QLabel(centralwidget);
        label_description->setObjectName("label_description");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_description);

        lineEdit_description = new QLineEdit(centralwidget);
        lineEdit_description->setObjectName("lineEdit_description");
        lineEdit_description->setMinimumSize(QSize(400, 100));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEdit_description);


        verticalLayout->addLayout(formLayout);

        horizontalLayout_buttons = new QHBoxLayout();
        horizontalLayout_buttons->setObjectName("horizontalLayout_buttons");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_buttons->addItem(horizontalSpacer);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_buttons->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_buttons);

        label_message = new QLabel(centralwidget);
        label_message->setObjectName("label_message");
        label_message->setAlignment(Qt::AlignCenter);
        label_message->setStyleSheet(QString::fromUtf8("color: green; font-weight: bold;"));

        verticalLayout->addWidget(label_message);

        home->setCentralWidget(centralwidget);

        retranslateUi(home);

        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QMainWindow *home)
    {
        home->setWindowTitle(QCoreApplication::translate("CreateItem", "Home Page", nullptr));
        label->setText(QCoreApplication::translate("CreateItem", "Bug Creation", nullptr));
        label_itemType->setText(QCoreApplication::translate("CreateItem", "Item Type:", nullptr));
        label_itemStatus->setText(QCoreApplication::translate("CreateItem", "Item Status:", nullptr));
        comboBox_itemStatus->setItemText(0, QCoreApplication::translate("CreateItem", "yet-to-start", nullptr));
        comboBox_itemStatus->setItemText(1, QCoreApplication::translate("CreateItem", "in progress", nullptr));
        comboBox_itemStatus->setItemText(2, QCoreApplication::translate("CreateItem", "completed", nullptr));
        comboBox_itemStatus->setItemText(3, QCoreApplication::translate("CreateItem", "committed", nullptr));
        comboBox_itemStatus->setItemText(4, QCoreApplication::translate("CreateItem", "to test", nullptr));
        comboBox_itemStatus->setItemText(5, QCoreApplication::translate("CreateItem", "reopen", nullptr));
        comboBox_itemStatus->setItemText(6, QCoreApplication::translate("CreateItem", "close", nullptr));

        label_itemStatus_feature->setText(QCoreApplication::translate("CreateItem", "Feature:", nullptr));
        comboBox_featureType->setItemText(0, QCoreApplication::translate("CreateItem", "UI", nullptr));
        comboBox_featureType->setItemText(1, QCoreApplication::translate("CreateItem", "Logic", nullptr));
        comboBox_featureType->setItemText(2, QCoreApplication::translate("CreateItem", "Performance", nullptr));
        comboBox_featureType->setItemText(3, QCoreApplication::translate("CreateItem", "Security", nullptr));
        comboBox_featureType->setItemText(4, QCoreApplication::translate("CreateItem", "Other", nullptr));

        label_description->setText(QCoreApplication::translate("CreateItem", "Description:", nullptr));
        lineEdit_description->setPlaceholderText(QCoreApplication::translate("CreateItem", "Add Description", nullptr));
        pushButton_3->setText(QCoreApplication::translate("CreateItem", "Create", nullptr));
        label_message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CreateItem: public Ui_CreateItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEBUG_H
