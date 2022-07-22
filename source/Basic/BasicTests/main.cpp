#include "BasicTests.h"

#include <QtWidgets/QApplication>
#include <QtCore/QFile>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QFile qss(":/style/res/MaterialDark.qss");
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
	BasicTests w;
	w.show();
	return a.exec();
}
