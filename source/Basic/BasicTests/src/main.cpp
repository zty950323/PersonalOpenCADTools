#include <QtCore/QFile>
#include <QtWidgets/QApplication>

#include "BasicTests.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QFile qss(QStringLiteral(":/style/MaterialDark.qss"));
  if (qss.open(QFile::ReadOnly)) {
    qDebug("open success");
    QString style = QLatin1String(qss.readAll());
    a.setStyleSheet(style);
    qss.close();
  } else {
    qDebug("Open failed");
  }
  BasicTests w;
  w.show();
  return a.exec();
}