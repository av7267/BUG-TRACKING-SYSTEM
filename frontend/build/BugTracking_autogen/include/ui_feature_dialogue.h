/********************************************************************************
** Form generated from reading UI file 'feature_dialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATURE_DIALOGUE_H
#define UI_FEATURE_DIALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_FeatureDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_type;
    QLineEdit *lineEdit_type;
    QLabel *label_feature_type;
    QComboBox *comboBox_featureType;
    QLabel *label_item_status;
    QComboBox *comboBox_itemStatus;
    QLabel *label_description;
    QTextEdit *lineEdit_description;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *FeatureDialog)
    {
        if (FeatureDialog->objectName().isEmpty())
            FeatureDialog->setObjectName("FeatureDialog");
        FeatureDialog->resize(500, 300);
        verticalLayout = new QVBoxLayout(FeatureDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_type = new QLabel(FeatureDialog);
        label_type->setObjectName("label_type");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_type);

        lineEdit_type = new QLineEdit(FeatureDialog);
        lineEdit_type->setObjectName("lineEdit_type");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_type);

        label_feature_type = new QLabel(FeatureDialog);
        label_feature_type->setObjectName("label_feature_type");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label_feature_type);

        comboBox_featureType = new QComboBox(FeatureDialog);
        comboBox_featureType->addItem(QString());
        comboBox_featureType->addItem(QString());
        comboBox_featureType->addItem(QString());
        comboBox_featureType->addItem(QString());
        comboBox_featureType->addItem(QString());
        comboBox_featureType->setObjectName("comboBox_featureType");
        comboBox_featureType->setMinimumWidth(200);

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, comboBox_featureType);

        label_item_status = new QLabel(FeatureDialog);
        label_item_status->setObjectName("label_item_status");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_item_status);

        comboBox_itemStatus = new QComboBox(FeatureDialog);
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->setObjectName("comboBox_itemStatus");
        comboBox_itemStatus->setMinimumWidth(200);

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, comboBox_itemStatus);

        label_description = new QLabel(FeatureDialog);
        label_description->setObjectName("label_description");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_description);

        lineEdit_description = new QTextEdit(FeatureDialog);
        lineEdit_description->setObjectName("lineEdit_description");
        lineEdit_description->setMinimumSize(QSize(400, 100));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEdit_description);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(FeatureDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(FeatureDialog);

        QMetaObject::connectSlotsByName(FeatureDialog);
    } // setupUi

    void retranslateUi(QDialog *FeatureDialog)
    {
        FeatureDialog->setWindowTitle(QCoreApplication::translate("FeatureDialog", "Add Feature", nullptr));
        label_type->setText(QCoreApplication::translate("FeatureDialog", "Item Type:", nullptr));
        label_feature_type->setText(QCoreApplication::translate("FeatureDialog", "Feature Type:", nullptr));
        comboBox_featureType->setItemText(0, QCoreApplication::translate("FeatureDialog", "UI", nullptr));
        comboBox_featureType->setItemText(1, QCoreApplication::translate("FeatureDialog", "Logic", nullptr));
        comboBox_featureType->setItemText(2, QCoreApplication::translate("FeatureDialog", "Performance", nullptr));
        comboBox_featureType->setItemText(3, QCoreApplication::translate("FeatureDialog", "Security", nullptr));
        comboBox_featureType->setItemText(4, QCoreApplication::translate("FeatureDialog", "Other", nullptr));

        label_item_status->setText(QCoreApplication::translate("FeatureDialog", "Item Status:", nullptr));
        comboBox_itemStatus->setItemText(0, QCoreApplication::translate("FeatureDialog", "yet-to-start", nullptr));
        comboBox_itemStatus->setItemText(1, QCoreApplication::translate("FeatureDialog", "in progress", nullptr));
        comboBox_itemStatus->setItemText(2, QCoreApplication::translate("FeatureDialog", "completed", nullptr));
        comboBox_itemStatus->setItemText(3, QCoreApplication::translate("FeatureDialog", "committed", nullptr));
        comboBox_itemStatus->setItemText(4, QCoreApplication::translate("FeatureDialog", "to test", nullptr));
        comboBox_itemStatus->setItemText(5, QCoreApplication::translate("FeatureDialog", "reopen", nullptr));
        comboBox_itemStatus->setItemText(6, QCoreApplication::translate("FeatureDialog", "close", nullptr));

        label_description->setText(QCoreApplication::translate("FeatureDialog", "Description:", nullptr));
        lineEdit_description->setPlaceholderText(QCoreApplication::translate("FeatureDialog", "Add Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FeatureDialog: public Ui_FeatureDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATURE_DIALOGUE_H
