/**
 * Copyright (c) 2022, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#ifndef SOURCE_INCLUDE_WIDGETS_WIDGETS_KEEP_MENU_H_
#define SOURCE_INCLUDE_WIDGETS_WIDGETS_KEEP_MENU_H_

#include <QtGui/QMouseEvent>
#include <QtWidgets/QMenu>

#include "widgets_export.h"

TZ_NAMESPACE_BEGIN(TzSoft)

class TZ_WIDGETS_STATIC_EXPORT TzKeepMenu : public QMenu {
 public:
  explicit TzKeepMenu(QWidget* parent = nullptr) : QMenu(parent) {}

 protected:
  inline void mouseReleaseEvent(QMouseEvent* e) {
    QAction* action = this->actionAt(e->pos());
    if (action) {
      QString strCanHide = action->property("canHideMenu").toString();
      if (strCanHide == QStringLiteral("true")) {
        QMenu::mouseReleaseEvent(e);
        return;
      } else {
        action->activate(QAction::Trigger);
        return;
      }
    }
    QMenu::mouseReleaseEvent(e);
  }
};

TZ_NAMESPACE_END(TzSoft)

#endif  // SOURCE_INCLUDE_WIDGETS_WIDGETS_KEEP_MENU_H_
