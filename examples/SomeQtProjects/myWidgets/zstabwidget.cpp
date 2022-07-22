#include "zstabwidget.h"
#include "ui_zstabwidget.h"

ZsTabWidget::ZsTabWidget(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::ZsTabWidget)
{
    ui->setupUi(this);
}

ZsTabWidget::~ZsTabWidget()
{
    delete ui;
}
