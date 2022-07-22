///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "BasicTests.h"
#include <QtWidgets/QMessageBox>

BasicTests::BasicTests(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.ArrayTestTab->setEdit(ui.Array_textEdit);
	ui.ArrayTestTab->setPrograssBar(ui.ArrayTestProgressBar);
	QMenu* menu = new QMenu();
	menu->addAction(new QAction("This is a test action one"));
	menu->addAction(new QAction("This is a test action two"));
	menu->addAction(new QAction("This is a test action three"));
	menu->addAction(new QAction("This is a test action four"));
	ui.toolButton_test->setMenu(menu);
}

void BasicTests::on_Array_start_pushButton_clicked(bool checked)
{
	QMessageBox::information(this, QStringLiteral("开始测试"), QStringLiteral("这是一个针对Array和TzArray的简单测试"), QMessageBox::Yes);
	ui.ArrayTestTab->start();
}

void BasicTests::on_Array_end_pushButton_clicked(bool checked)
{
	QMessageBox::information(this, QStringLiteral("结束测试"), QStringLiteral("这是一个针对Array和TzArray的简单测试"), QMessageBox::Yes);
	ui.ArrayTestTab->end();
}
