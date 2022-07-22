#include "qpainterpathusecases.h"
#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QPainterPathUseCases w;
    QFile qss(":/QPainterPathUseCases/res/MaterialDark.qss");
    if (qss.open(QFile::ReadOnly))
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
    w.show();
    return a.exec();
}
