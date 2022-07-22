#include "mainwindow.h"
#include "testtablewidget.h"
#include <QApplication>
#include <QFile>
#include <QDebug>

void Foo(char str[100]) 
{
    qDebug() << sizeof(str);
    int i = 0, cnt = 0, sum = 0;
    for (int i = 0; i < 6; i++)
    {
        cnt += sum;
        sum += 2 * (i % 2) - i / 2;
    }
    qDebug() << cnt << sum;
    qDebug() << __FILE__ << __LINE__ << __FUNCTION__;
}

int main(int argc, char *argv[])
{
    char str[] = "www.zwcad.com";
    char* p = str;
    int n = 10;
    qDebug() << sizeof(str) << sizeof(p) << sizeof(n);
    Foo(str);
    QApplication a(argc, argv);
    QFile qss(":/style/res/style/MaterialDark.qss");
    if( qss.open(QFile::ReadOnly))
    {
       qDebug("open success");
       QString style = QLatin1String(qss.readAll());
       a.setStyleSheet(style);
       qss.close();
    }
    else
    {
      qDebug("Open failed");
    }
    MainWindow w;
    w.show();
    w.choseToHide(SenderControls::BUTTONS);
    w.choseToHide(SenderControls::COMBOBOX);
    w.messageBoxUse();
    QList<QPointF> coordinates;
        coordinates << QPointF(0.0, 0.9)
                    << QPointF(0.2, 11.0)
                    << QPointF(0.4, 15.4)
                    << QPointF(0.6, 12.9)
                    << QPointF(0.8, 8.5)
                    << QPointF(1.0, 7.1)
                    << QPointF(1.2, 4.0)
                    << QPointF(1.4, 13.6)
                    << QPointF(1.6, 22.2)
                    << QPointF(1.8, 22.2);
    TestTableWidget coordinateSetter(&coordinates);
    coordinateSetter.addRow();
    coordinateSetter.addRow();
    coordinateSetter.addRow();
    coordinateSetter.addRow();
    coordinateSetter.addRowAuto();
    coordinateSetter.addRowAuto();
    coordinateSetter.addRowAuto();
    coordinateSetter.addRowAuto();
    coordinateSetter.show();
    coordinateSetter.readData();
    coordinateSetter.testCellWidget(1,0);
    coordinateSetter.testCellWidget(2,1);
    return a.exec();
}
