#ifndef REGISTRATION_WINDOW_H
#define REGISTRATION_WINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>

namespace Ui { 
    class registrationwindow; 
}

class registrationwindow : public QMainWindow {
    Q_OBJECT

public:
    registrationwindow(QWidget *parent = nullptr);
    ~registrationwindow();

private slots:
    void handleregister();
    void loginreroute();

private:
    Ui::registrationwindow *ui;
    QNetworkAccessManager *manager;
};

#endif 