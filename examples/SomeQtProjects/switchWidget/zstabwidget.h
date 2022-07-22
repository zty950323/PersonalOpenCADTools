#ifndef ZSTABWIDGET_H
#define ZSTABWIDGET_H

#include <QTabWidget>

namespace Ui {
class ZsTabWidget;
}

class ZsTabWidget : public QTabWidget
{
    Q_OBJECT

public:
    explicit ZsTabWidget(QWidget *parent = nullptr);
    ~ZsTabWidget();

private:
    Ui::ZsTabWidget *ui;
};

#endif // ZSTABWIDGET_H
