#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>


QT_BEGIN_NAMESPACE
namespace Ui {
    class CreateItem;
}

QT_END_NAMESPACE

class CreateItem : public  QMainWindow 
{
    Q_OBJECT

public:
    CreateItem(QWidget *parent = nullptr);
    ~CreateItem();

private slots:
    void fetchItemTypes();
    void handleDescription();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::CreateItem *ui;
    QNetworkAccessManager *manager;
};

#endif
