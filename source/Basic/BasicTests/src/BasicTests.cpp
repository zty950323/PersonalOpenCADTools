/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#include "BasicTests.h"

#include <QtGui/QMouseEvent>
#include <QtWidgets/QMessageBox>

#include "Widgets/widgets_keep_menu.h"

BasicTests::BasicTests(QWidget *parent) : QMainWindow(parent) {
  ui.setupUi(this);
  ui.ArrayTestTab->setEdit(ui.Array_textEdit);
  ui.ArrayTestTab->setPrograssBar(ui.ArrayTestProgressBar);
  TzSoft::TzKeepMenu *menu = new TzSoft::TzKeepMenu();
  auto act1 = new QAction(tr("Icon View"));
  act1->setCheckable(true);
  menu->addAction(act1);
  menu->addAction(
      QApplication::style()->standardIcon(QStyle::SP_MessageBoxQuestion),
      tr("Detil Viwe"));
  menu->addAction(
      QApplication::style()->standardIcon(QStyle::SP_MessageBoxInformation),
      tr("Information View"));
  menu->addAction(
      QApplication::style()->standardIcon(QStyle::SP_MessageBoxWarning),
      tr("Warning View"));
  ui.toolButton_test->setMinimumSize(30, 30);
  ui.toolButton_test->setIcon(
      QApplication::style()->standardIcon(QStyle::SP_ComputerIcon));
  ui.toolButton_test->setPopupMode(QToolButton::InstantPopup);
  ui.toolButton_test->setMenu(menu);
}

void BasicTests::on_Array_start_pushButton_clicked(bool) {
  QMessageBox::information(this, QStringLiteral("Start Test"),
                           QStringLiteral("Simple Test For Array."),
                           QMessageBox::Yes);
  ui.ArrayTestTab->start();
}

void BasicTests::on_Array_end_pushButton_clicked(bool) {
  QMessageBox::information(this, QStringLiteral("End Test"),
                           QStringLiteral("Simple Test For Array."),
                           QMessageBox::Yes);
  ui.ArrayTestTab->end();
}
