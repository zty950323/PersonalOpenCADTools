#ifndef SWITCHWIDGET_H
#define SWITCHWIDGET_H

#include <QWidget>
#include "switchwidgetinner.h"

class QMenu;

class switchWidget : public QWidget
{
    Q_OBJECT

public:
    switchWidget(QWidget *parent = 0);

    void mousePressEvent(QMouseEvent *event) override;
private slots:
    void addActsRes(bool);
    void deleteActsRes(bool);
private:
    switchWidgetInner * m_widget = Q_NULLPTR;
    QMenu * m_contextMenu = Q_NULLPTR;
    QAction *m_addAction = Q_NULLPTR;
    QAction *m_delAction = Q_NULLPTR;
};

#endif // SWITCHWIDGET_H
