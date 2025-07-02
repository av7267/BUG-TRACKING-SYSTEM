/********************************************************************************
** Form generated from reading UI file 'assign_dialogue.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGN_DIALOGUE_H
#define UI_ASSIGN_DIALOGUE_H

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

class Ui_AssignDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_tester;
    QComboBox *comboBox_developer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AssignDialog)
    {
        if (AssignDialog->objectName().isEmpty())
            AssignDialog->setObjectName("AssignDialog");
        AssignDialog->resize(500, 300);
        verticalLayout = new QVBoxLayout(AssignDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_tester = new QLabel(AssignDialog);
        label_tester->setObjectName("label_tester");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_tester);

        comboBox_developer = new QComboBox(AssignDialog);
        comboBox_developer->setObjectName("comboBox_developer");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, comboBox_developer);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(AssignDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AssignDialog);

        QMetaObject::connectSlotsByName(AssignDialog);
    } // setupUi

    void retranslateUi(QDialog *AssignDialog)
    {
        AssignDialog->setWindowTitle(QCoreApplication::translate("AssignDialog", "Assign Bugs", nullptr));
        label_tester->setText(QCoreApplication::translate("AssignDialog", "Select Senior Developer:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AssignDialog: public Ui_AssignDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGN_DIALOGUE_H
