/********************************************************************************
** Form generated from reading UI file 's_developer.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_S_DEVELOPER_H
#define UI_S_DEVELOPER_H

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

class Ui_ActivityWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *comboBox_itemStatus;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QHBoxLayout *buttonRowLayout;
    QPushButton *pushButton_edit;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *assign_developers;

    void setupUi(QMainWindow *activity)
    {
        if (activity->objectName().isEmpty())
            activity->setObjectName("activity");
        activity->resize(600, 600);
        activity->setMinimumSize(QSize(600, 600));
        activity->setMaximumSize(QSize(600, 600));
        centralwidget = new QWidget(activity);
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
        pushButton_edit = new QPushButton(centralwidget);
        pushButton_edit->setObjectName("pushButton_edit");
        pushButton_edit->setMinimumSize(QSize(100, 35));

        buttonRowLayout->addWidget(pushButton_edit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonRowLayout->addItem(horizontalSpacer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonRowLayout->addItem(horizontalSpacer_2);

        assign_developers = new QPushButton(centralwidget);
        assign_developers->setObjectName("assign_developers");
        assign_developers->setMinimumSize(QSize(100, 35));

        buttonRowLayout->addWidget(assign_developers);


        verticalLayout->addLayout(buttonRowLayout);

        activity->setCentralWidget(centralwidget);

        retranslateUi(activity);

        QMetaObject::connectSlotsByName(activity);
    } // setupUi

    void retranslateUi(QMainWindow *activity)
    {
        activity->setWindowTitle(QCoreApplication::translate("ActivityWindow", "Senior Developer", nullptr));
        label->setText(QCoreApplication::translate("ActivityWindow", "Edit the Bugs", nullptr));
        comboBox_itemStatus->setItemText(0, QCoreApplication::translate("ActivityWindow", "in progress", nullptr));
        comboBox_itemStatus->setItemText(1, QCoreApplication::translate("ActivityWindow", "completed", nullptr));
        comboBox_itemStatus->setItemText(2, QCoreApplication::translate("ActivityWindow", "committed", nullptr));

        pushButton_2->setText(QCoreApplication::translate("ActivityWindow", "ok", nullptr));
        pushButton_edit->setText(QCoreApplication::translate("ActivityWindow", "Update", nullptr));
        assign_developers->setText(QCoreApplication::translate("ActivityWindow", "Assign", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActivityWindow: public Ui_ActivityWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_S_DEVELOPER_H
