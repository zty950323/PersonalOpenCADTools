#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file(":/styles/styles.qss");
    if(file.open(QFile::ReadOnly))
    {
        qApp->setStyleSheet(file.readAll());
        file.close();
        qDebug() << "Open File Successfully!!!";
    }
    else
        QMessageBox::about(NULL, "Test", "Open File Failed");

    MainWindow w;
    w.show();
    return a.exec();
}
