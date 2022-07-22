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
		//����ͣ�ã���Ϊ����Ĵ���  
		if (QEvent::WindowDeactivate == event->type())
		{
			//  
			//DEBUGP( "eventFilter" ) ;  
			// hide();  //���߹رմ���,�����Լ��Ĳ���.  
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
