#ifndef TESTTABLEWIDGET_H
#define TESTTABLEWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>

QT_BEGIN_NAMESPACE
class QTableWidget;
QT_END_NAMESPACE

class ItemClone : public QTableWidgetItem
{
public:
    ItemClone();
    void setType(int id);
    virtual QTableWidgetItem *clone() const;
    int m_type = 1111;
};

class TestTableWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TestTableWidget(const QList<QPointF>* coord, QWidget *parent = nullptr);
    void addRow();
    void addRowAuto();
    void readData();
    void testCellWidget(int row, int col);

private:
    QTableWidget* pTableWidget;
    const QList<QPointF>* pCoordinates;
};


#endif // TESTTABLEWIDGET_H
