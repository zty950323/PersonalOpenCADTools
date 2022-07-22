#include "switchwidget.h"

#include <QMenu>
#include <QVBoxLayout>
#include <QMouseEvent>

switchWidget::switchWidget(QWidget *parent) :
    QWidget(parent)
{
    m_widget = new switchWidgetInner(this);
    QVBoxLayout * lay = new QVBoxLayout;
    lay->addWidget(m_widget);
    setLayout(lay);
    m_contextMenu = new QMenu;  //这是右击弹出的菜单
    m_addAction = new QAction("新增",this);
    m_delAction = new QAction("删除",this);
    //给菜单添加菜单项
    m_contextMenu->addAction(m_addAction);
    m_contextMenu->addAction(m_delAction);
}

void switchWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::RightButton)
    {
        //在鼠标右击的地方弹出菜单
        m_contextMenu->exec(event->globalPos());
    }

    event->accept();

}

void switchWidget::addActsRes(bool)
{
    // TODO
}

void switchWidget::deleteActsRes(bool)
{
    // TODO
}
