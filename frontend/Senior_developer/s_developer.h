#ifndef ACTIVITY_WINDOW_H
#define ACTIVITY_WINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QStandardItem>
#include <QNetworkReply>

namespace Ui {
    class ActivityWindow;
}

class ActivityWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ActivityWindow(int developerId, QWidget *parent = nullptr);
    ~ActivityWindow();

private slots:
    void fetchItems();
    void assignDevelopers();
    void handleedit();
private:
    int developerId;
    Ui::ActivityWindow *ui;
    QNetworkAccessManager *manager;
};

#endif