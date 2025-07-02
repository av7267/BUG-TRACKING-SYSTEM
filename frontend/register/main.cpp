#include <QApplication>
#include "registration_window.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    registrationwindow w;
    w.show();
    QObject::connect(&a, &QApplication::aboutToQuit, &w, [&w]() {
        qDebug() << "Application is quitting. Perform cleanup if needed.";
    });
    return a.exec();
}
