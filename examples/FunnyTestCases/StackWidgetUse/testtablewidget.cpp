#include "testtablewidget.h"

#include <QTableWidget>
#include <QStringList>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QDebug>
#include <QBrush>
#include <QPushButton>


TestTableWidget::TestTableWidget(const QList<QPointF>* coord, QWidget *parent )
    : QWidget(parent),
      pTableWidget(new QTableWidget(0, 2, this))

{
    pCoordinates = coord;
    QStringList strList;
    strList.append(tr("X"));
    strList.append(tr("Y"));

    pTableWidget->setHorizontalHeaderLabels(strList);
    ItemClone * item_default = new ItemClone();
    item_default->setData(1, "(0,1,1)");
    item_default->setText("(0,0,0)");
    pTableWidget->setItemPrototype(item_default);
    // set pTableWidget to be disabled for changing item.
    // pTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    for (int row(0); row != pCoordinates->count(); ++row) {
        QPointF point = pCoordinates->at(row);
        addRow();

        // pTableWidget->item(row, 0)->setData(Qt::DisplayRole, QString::number(point.x()));
        pTableWidget->item(row, 0)->setText(QString::number(point.x()));
        pTableWidget->item(row, 1)->setText(QString::number(point.y()));
    }

    QVBoxLayout* vBoxLayout(new QVBoxLayout(this));
    vBoxLayout->addWidget(pTableWidget);
    setLayout(vBoxLayout);
    setMinimumSize(480, 640);
}


void TestTableWidget::addRow()
{
    // pTableWidget为QTableWidget实例。
    int row(pTableWidget->rowCount());
    pTableWidget->insertRow(row);

    ItemClone* item0(new ItemClone());
    // item0->setText("(1,0,0)");
    item0->setTextAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    pTableWidget->setItem(row, 0, item0);

    ItemClone* item1(new ItemClone());
    // item1->setText("(0,0,0)");
    item1->setTextAlignment(Qt::AlignBaseline | Qt::AlignRight);
    pTableWidget->setItem(row, 1, item1);

    pTableWidget->setCurrentCell(row, 0);
}

void TestTableWidget::addRowAuto()
{
    int row(pTableWidget->rowCount());
    pTableWidget->insertRow(row);
}

void TestTableWidget::readData()
{
    auto tp = pTableWidget->itemPrototype();
    ItemClone * tpm = reinterpret_cast<ItemClone *>(const_cast<QTableWidgetItem *>(tp));
    Q_ASSERT(tpm);
    tpm->setText("1,1010,111");
    tpm->setType(1000);
    qDebug() << tpm->m_type;
    auto it = pTableWidget->item(1, 1);
    ItemClone * item = reinterpret_cast<ItemClone *>(it);
    Q_ASSERT(item);
    qDebug() << item->m_type;
    item->setType(321);
    qDebug() << item->m_type;
    qDebug() << item->data(1);
}

void TestTableWidget::testCellWidget(int row, int col)
{
    QWidget * widget = new QWidget();
    widget->setMinimumSize(50, 50);
    widget->setStyleSheet("QWidget { background-color: rgb(255, 255, 0); };");
    QPushButton * button = new QPushButton(widget);
    button->setMinimumSize(50,20);
    QPushButton * button_1 = new QPushButton(widget);
    button_1->setMinimumSize(50,20);
    QPushButton * button_2 = new QPushButton(widget);
    button_2->setMinimumSize(50,20);
    QPushButton * button_3 = new QPushButton(widget);
    button_3->setMinimumSize(50,20);
    QVBoxLayout * layout = new QVBoxLayout();
    layout->addWidget(button);
    layout->addWidget(button_1);
    layout->addWidget(button_2);
    layout->addWidget(button_3);
    widget->setLayout(layout);
    pTableWidget->setCellWidget(row, col, widget);
    auto cell = pTableWidget->cellWidget(row, col);
    // cell->hide();
    Q_ASSERT(cell);
    cell->setMinimumSize(50, 50);
    cell->setStyleSheet("QWidget { background-color: rgb(255, 0, 0); }\n QPushButton { background-color: rgb(0, 0, 0);} ");
    cell->setFocus();
    cell->resize(100, 100);
}

ItemClone::ItemClone()
{
    QBrush bsh(QColor(100, 50, 50));
    setBackground(bsh);
}

void ItemClone::setType(int id)
{
    m_type = id;
}

QTableWidgetItem *ItemClone::clone() const
{
    QTableWidgetItem * ret = new ItemClone();
    ret->setData(1,"100, 200, 300");
    ret->setText("100, 200, 300");
    return ret;
}
