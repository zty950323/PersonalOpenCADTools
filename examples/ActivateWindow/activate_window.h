///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _ACTIVATE_WINDOW_H_H_
#define _ACTIVATE_WINDOW_H_H_



#include <QtWidgets/QMainWindow>
#include "ui_activate_window.h"

class ActivateWindow : public QMainWindow
{
	Q_OBJECT

public:
	ActivateWindow(QWidget *parent = Q_NULLPTR);

protected:
	bool eventFilter(QObject *watched, QEvent *event) override;

private:
	Ui::ActivateWindowClass ui;
};

#endif // !_ACTIVATE_WINDOW_H_H_