#include "gui_tests.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	GuiTests w;
	w.show();
	return a.exec();
}
