///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_array_test_tab_widget.h"

#include <QtWidgets/QProgressBar>
#include <QtWidgets/QTextEdit>

TzArrayTestTab::TzArrayTestTab(QWidget* parent /* = nullptr */)
    : QWidget(parent) {}

TzArrayTestTab::~TzArrayTestTab() {}

void TzArrayTestTab::start() {
  m_arrayTests.startAllTest();
  m_openArrayTests.startAllTest();
  // m_edit->append(QStringLiteral("Now there is the TzArray test data : "));
  // m_edit->append(QString::fromStdString(m_arrayTests.printRetString()));
  // m_edit->append(QStringLiteral("Now there is the open array test data : "));
  // m_edit->append(QString::fromStdString(m_openArrayTests.printRetString()));
}

void TzArrayTestTab::end() {
  // TODO
  m_edit->clear();
}

void TzArrayTestTab::setEdit(QTextEdit* edit) {
  if (nullptr != edit) {
    m_edit = edit;
    m_arrayTests.setEdit(edit);
    m_openArrayTests.setEdit(edit);
  }
}

void TzArrayTestTab::setPrograssBar(QProgressBar* bar) {
  if (nullptr != bar) {
    m_prograssBar = bar;
    m_arrayTests.setProgressBar(bar);
    m_openArrayTests.setProgressBar(bar);
  }
}