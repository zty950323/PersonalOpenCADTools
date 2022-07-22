///////////////////////////////////////////////////////////////////////////////////////////
// Copyright (c)2021, Tom Zhao personal. ("TZOpenTools")
// This software is a personal tools project by Tom Zhao.
// Description:
///////////////////////////////////////////////////////////////////////////////////////////

#include "basic_bit_flags_test_tab_widget.h"

TzBitFlagsTestTab::TzBitFlagsTestTab(QWidget* parent) : QWidget(parent) {}

TzBitFlagsTestTab::~TzBitFlagsTestTab() {}

void TzBitFlagsTestTab::start() {}

void TzBitFlagsTestTab::end() {}

void TzBitFlagsTestTab::setEdit(QTextEdit* edit) {
  if (nullptr != edit) {
    m_edit = edit;
  }
}

void TzBitFlagsTestTab::setPrograssBar(QProgressBar* bar) {
  if (nullptr != bar) {
    m_prograssBar = bar;
  }
}