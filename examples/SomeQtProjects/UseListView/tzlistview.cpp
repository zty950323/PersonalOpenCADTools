#include "tzlistview.h"
#include <QEvent>
#include <QStyledItemDelegate>

class TzItemDelegate : public QStyledItemDelegate
{
public:
    using QStyledItemDelegate::QStyledItemDelegate;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

QSize TzItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}

void TzItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    option.state;
    // option.state &~QStyle::StateFlag::State_MouseOver;
    QStyleOptionViewItem opt(option);
    opt.state = opt.state &~QStyle::StateFlag::State_MouseOver;
    QStyledItemDelegate::paint(painter, opt, index);
}

TzListView::TzListView()
{
    init();
}

TzListView::TzListView(QWidget *parent)
    : QListView(parent)
{
    init();
}

void TzListView::init(void)
{
    setAttribute(Qt::WA_OpaquePaintEvent);
    auto currentDelegate = itemDelegate();
    TzItemDelegate *del = new TzItemDelegate(currentDelegate);
    setItemDelegate(del);
}