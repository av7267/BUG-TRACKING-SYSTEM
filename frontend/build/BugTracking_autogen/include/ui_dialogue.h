/********************************************************************************
** Form generated from reading UI file 'dialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGUE_H
#define UI_DIALOGUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_status;
    QComboBox *comboBox_itemStatus;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName("EditDialog");
        EditDialog->resize(400, 150);
        verticalLayout = new QVBoxLayout(EditDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_status = new QLabel(EditDialog);
        label_status->setObjectName("label_status");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_status);

        comboBox_itemStatus = new QComboBox(EditDialog);
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->setObjectName("comboBox_itemStatus");
        comboBox_itemStatus->setMinimumWidth(200);

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboBox_itemStatus);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(EditDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(EditDialog);

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QCoreApplication::translate("EditDialog", "Edit Item", nullptr));
        label_status->setText(QCoreApplication::translate("EditDialog", "Item Status:", nullptr));
        comboBox_itemStatus->setItemText(0, QCoreApplication::translate("EditDialog", "yet-to-start", nullptr));
        comboBox_itemStatus->setItemText(1, QCoreApplication::translate("EditDialog", "in progress", nullptr));
        comboBox_itemStatus->setItemText(2, QCoreApplication::translate("EditDialog", "completed", nullptr));
        comboBox_itemStatus->setItemText(3, QCoreApplication::translate("EditDialog", "committed", nullptr));
        comboBox_itemStatus->setItemText(4, QCoreApplication::translate("EditDialog", "to test", nullptr));
        comboBox_itemStatus->setItemText(5, QCoreApplication::translate("EditDialog", "reopen", nullptr));
        comboBox_itemStatus->setItemText(6, QCoreApplication::translate("EditDialog", "close", nullptr));

    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGUE_H
