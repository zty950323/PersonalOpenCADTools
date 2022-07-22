///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2020, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <QtWidgets/QMainWindow>
#include "ui_gui_tests.h"

class GuiTests : public QMainWindow
{
	Q_OBJECT

public:
	GuiTests(QWidget *parent = Q_NULLPTR);

private:
	Ui::GuiTestsClass ui;
};
