///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include <QtCore/QEvent>
#include "activate_window.h"

ActivateWindow::ActivateWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	installEventFilter(this);
}

bool ActivateWindow::eventFilter(QObject * watched, QEvent * event)
{
	if (watched == this)
	{
		//窗口停用，变为不活动的窗口  
		if (QEvent::WindowDeactivate == event->type())
		{
			//  
			//DEBUGP( "eventFilter" ) ;  
			// hide();  //或者关闭窗口,加入自己的操作.  
			setStyleSheet("QWidget { background-color : red; }");
			return true;
		}
		else
		{
			// setStyleSheet("QWidget { background-color : blue; }");
			return false;
		}
	}
	return false;
}
