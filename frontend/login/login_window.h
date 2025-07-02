#ifndef LOGIN_WINDOW_H
#define LOGIN_WINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>

QT_BEGIN_NAMESPACE
namespace Ui {
    class LoginWindow;
}

QT_END_NAMESPACE

class LoginWindow : public QMainWindow 
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void handleLogin();
    void reroute();

private:
    Ui::LoginWindow *ui;
    QNetworkAccessManager *manager;
};

#endif 