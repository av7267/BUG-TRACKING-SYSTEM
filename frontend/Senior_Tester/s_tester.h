#ifndef SENIOR_TESTER_WINDOW_H
#define SENIOR_TESTER_WINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
    class SeniorTesterWindow;
}

class SeniorTesterWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit SeniorTesterWindow(QWidget *parent = nullptr, int user_id = 0);
    ~SeniorTesterWindow();

private slots:
    void addFeature();
    void DeleteBug();
    void fetchBugs();
    void assignBugs();
    void handleselection(const QModelIndex &current, const QModelIndex &previous);
    void CreateBug();

private:
    Ui::SeniorTesterWindow *ui;
    QNetworkAccessManager *manager;
    int seniorTesterId;
};

#endif