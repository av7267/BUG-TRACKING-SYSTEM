/********************************************************************************
** Form generated from reading UI file 's_tester.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S_TESTER_H
#define UI_S_TESTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SeniorTesterWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox_itemStatus;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QHBoxLayout *buttonRowLayout;
    QPushButton *pushButton_create;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_addFeature;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_assign;
    QSpacerItem *horizontalSpacer_21;
    QPushButton *deleteButton;

    void setupUi(QMainWindow *SeniorTester)
    {
        if (SeniorTester->objectName().isEmpty())
            SeniorTester->setObjectName("SeniorTester");
        SeniorTester->resize(600, 600);
        SeniorTester->setMinimumSize(QSize(600, 600));
        SeniorTester->setMaximumSize(QSize(600, 600));
        centralwidget = new QWidget(SeniorTester);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        comboBox_itemStatus = new QComboBox(centralwidget);
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->addItem(QString());
        comboBox_itemStatus->setObjectName("comboBox_itemStatus");
        comboBox_itemStatus->setStyleSheet(QString::fromUtf8("QComboBox { font-size: 10px; }"));

        verticalLayout->addWidget(comboBox_itemStatus);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setMinimumSize(QSize(80, 30));

        verticalLayout->addWidget(pushButton_2);

        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");

        verticalLayout->addWidget(tableView);

        buttonRowLayout = new QHBoxLayout();
        buttonRowLayout->setObjectName("buttonRowLayout");
        pushButton_create = new QPushButton(centralwidget);
        pushButton_create->setObjectName("pushButton_create");
        pushButton_create->setMinimumSize(QSize(80, 30));

        buttonRowLayout->addWidget(pushButton_create);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonRowLayout->addItem(horizontalSpacer);

        pushButton_addFeature = new QPushButton(centralwidget);
        pushButton_addFeature->setObjectName("pushButton_addFeature");
        pushButton_addFeature->setMinimumSize(QSize(80, 30));

        buttonRowLayout->addWidget(pushButton_addFeature);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonRowLayout->addItem(horizontalSpacer_2);

        pushButton_assign = new QPushButton(centralwidget);
        pushButton_assign->setObjectName("pushButton_assign");
        pushButton_assign->setMinimumSize(QSize(80, 30));

        buttonRowLayout->addWidget(pushButton_assign);

        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonRowLayout->addItem(horizontalSpacer_21);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setMinimumSize(QSize(80, 30));

        buttonRowLayout->addWidget(deleteButton);


        verticalLayout->addLayout(buttonRowLayout);

        SeniorTester->setCentralWidget(centralwidget);

        retranslateUi(SeniorTester);

        QMetaObject::connectSlotsByName(SeniorTester);
    } // setupUi

    void retranslateUi(QMainWindow *SeniorTester)
    {
        SeniorTester->setWindowTitle(QCoreApplication::translate("SeniorTesterWindow", "Senior Tester", nullptr));
        label->setText(QCoreApplication::translate("SeniorTesterWindow", "Edit the Bugs", nullptr));
        comboBox_itemStatus->setItemText(0, QCoreApplication::translate("SeniorTesterWindow", "yet-to-start", nullptr));
        comboBox_itemStatus->setItemText(1, QCoreApplication::translate("SeniorTesterWindow", "in progress", nullptr));
        comboBox_itemStatus->setItemText(2, QCoreApplication::translate("SeniorTesterWindow", "completed", nullptr));
        comboBox_itemStatus->setItemText(3, QCoreApplication::translate("SeniorTesterWindow", "committed", nullptr));
        comboBox_itemStatus->setItemText(4, QCoreApplication::translate("SeniorTesterWindow", "to test", nullptr));
        comboBox_itemStatus->setItemText(5, QCoreApplication::translate("SeniorTesterWindow", "reopen", nullptr));
        comboBox_itemStatus->setItemText(6, QCoreApplication::translate("SeniorTesterWindow", "close", nullptr));

        pushButton_2->setText(QCoreApplication::translate("SeniorTesterWindow", "ok", nullptr));
        pushButton_create->setText(QCoreApplication::translate("SeniorTesterWindow", "Create", nullptr));
        pushButton_addFeature->setText(QCoreApplication::translate("SeniorTesterWindow", "Update", nullptr));
        pushButton_assign->setText(QCoreApplication::translate("SeniorTesterWindow", "Assign", nullptr));
        deleteButton->setText(QCoreApplication::translate("SeniorTesterWindow", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SeniorTesterWindow: public Ui_SeniorTesterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S_TESTER_H
