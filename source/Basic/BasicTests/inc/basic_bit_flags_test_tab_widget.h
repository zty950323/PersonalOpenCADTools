///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#ifndef _BASIC_BIT_FLASGS_TEST_TAB_H_
#define _BASIC_BIT_FLASGS_TEST_TAB_H_

#include <QtWidgets/QWidget>

class QTextEdit;
class QProgressBar;

class TzBitFlagsTestTab : public QWidget {
  Q_OBJECT
 public:
  TzBitFlagsTestTab(QWidget* parent = nullptr);
  ~TzBitFlagsTestTab();

  void start();
  void end();

  void setEdit(QTextEdit* edit);
  void setPrograssBar(QProgressBar* bar);

 private:
  QTextEdit* m_edit = Q_NULLPTR;
  QProgressBar* m_prograssBar = Q_NULLPTR;
};

#endif