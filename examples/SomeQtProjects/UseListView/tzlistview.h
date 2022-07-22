#ifndef TZLISTVIEW_H
#define TZLISTVIEW_H

#include <QListView>

class TzItemDelegate;

class TzListView : public QListView
{
    Q_OBJECT
public:
    TzListView();
    TzListView(QWidget * parent = nullptr);
private:
    void init(void);
protected:
    TzItemDelegate * m_delegate;
    QAbstractItemDelegate * m_defaultDelegate;
};

#endif // TZLISTVIEW_H
