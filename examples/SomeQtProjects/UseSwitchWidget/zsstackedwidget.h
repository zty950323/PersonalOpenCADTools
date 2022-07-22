#ifndef ZSSTACKEDWIDGET_H
#define ZSSTACKEDWIDGET_H

#include <QStackedWidget>

class ZsStackedWidget : public QStackedWidget
{
    Q_OBJECT
public:
    ZsStackedWidget(QWidget * parent = Q_NULLPTR);
};

#endif // ZSSTACKEDWIDGET_H
