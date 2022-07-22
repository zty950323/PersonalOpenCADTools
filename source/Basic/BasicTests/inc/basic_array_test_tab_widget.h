///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_ARRAY_TEST_TAB_H_
#define _BASIC_ARRAY_TEST_TAB_H_

#include <QtWidgets/QWidget>

#include "basic_array_tests.h"

class QTextEdit;
class QProgressBar;

class TzArrayTestTab : public QWidget {
  Q_OBJECT
 public:
  TzArrayTestTab(QWidget* parent = nullptr);
  ~TzArrayTestTab();

  void start();
  void end();

  void setEdit(QTextEdit* edit);
  void setPrograssBar(QProgressBar* bar);

 private:
  TzSoftTest::TzArrayTests m_arrayTests;
  TzSoftTest::TzOpenArrayTests m_openArrayTests;
  QTextEdit* m_edit = Q_NULLPTR;
  QProgressBar* m_prograssBar = Q_NULLPTR;
};

#endif