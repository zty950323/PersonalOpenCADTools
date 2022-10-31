///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_TESTS_H_
#define _BASIC_TESTS_H_

#include <QtWidgets/QMainWindow>

#include "ui_BasicTests.h"

class BasicTests : public QMainWindow
{
    Q_OBJECT

public:
    BasicTests(QWidget* parent = Q_NULLPTR);

public slots:
    void on_Add_tree_item_button_clicked(bool checked);
    void on_Array_start_pushButton_clicked(bool checked);
    void on_Array_end_pushButton_clicked(bool checked);

private:
    Ui::BasicTestsClass ui;
};

#endif  // _BASIC_TESTS_H_