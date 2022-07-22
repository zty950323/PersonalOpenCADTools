// widgets headers
#include "TZButtonGroupWidget.h"
// some qt headers.
#include <QPushButton>
#include <QAbstractSlider>
#include <QSlider>
#include <QHBoxLayout>
#include <QDebug>
#include <QList>
#include <QString>
#include <QIcon>

int divide(int a, int b)
{
    Q_ASSERT(b != 0);
    Q_ASSERT_X(b != 0, "divide", "division by zero");
    return a / b;
}

int setButton(const QList<QIcon>& icons, const QList<QString>& texts) 
{
    Q_ASSERT(icons.length() == texts.length());
    return icons.length();
}

void testSomeQ_ASSERT_Useage(void) 
{
    qDebug() << divide(10, 2) << divide(10, 10);
    QList<QIcon> icons;
    QList<QString> texts;
    for (int i = 0; i < 10; i++)
    {
        QIcon icon;
        QString str;
        icons.append(icon);
        texts.append(str);
    }
    qDebug() << setButton(icons, texts);
    // QIcon icon;
    // icons.append(icon);
    // qDebug() << setButton(icons, texts);
}

TZButtonGroupWidget::TZButtonGroupWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton* button1 = new QPushButton("One");
    button1->setMinimumSize(50, 20);
    QPushButton* button2 = new QPushButton("Two");
    button2->setMinimumSize(50, 20);
    QPushButton* button3 = new QPushButton("Three");
    button3->setMinimumSize(50, 20);
    QIcon icon(QString (":/style/res/style/icon1.png"));
    button1->setIcon(icon);
    button2->setIcon(icon);
    button3->setIcon(icon);
    QSpacerItem* left = new QSpacerItem(3, 0, QSizePolicy::Expanding);
    QSpacerItem* right = new QSpacerItem(3, 0, QSizePolicy::Expanding);
    m_lay = new QHBoxLayout;
    m_lay->addSpacerItem(left);
    m_lay->addWidget(button1);
    m_lay->addWidget(button2);
    m_lay->addWidget(button3);
    m_group.addButton(button1, 0);
    m_group.addButton(button2, 1);
    m_group.addButton(button3, 2);
    m_lay->addSpacerItem(right);
    this->setLayout(m_lay);
    this->show();
    testSomeQ_ASSERT_Useage();
    qDebug() << "lay Count: " << m_lay->count();
}

TZButtonGroupWidget::~TZButtonGroupWidget()
{

}

void TZButtonGroupWidget::testSetFlat(const bool& flat)
{
    QPushButton* button = (QPushButton*)m_group.button(0);
    button->setFlat(flat);
}

void TZButtonGroupWidget::testRemoveButton(void)
{
    for (size_t i = 0; i < m_group.buttons().length(); i++)
    {
        m_group.removeButton(m_group.button(i));
    }
    this->update();
    QPushButton * button = (QPushButton *)m_group.button(0);
}

void TZButtonGroupWidget::addButton(void)
{
    QPushButton* button = new QPushButton("Add New");
    QIcon icon(QString(":/style/res/style/icon1.png"));
    button->setIcon(icon);
    m_lay->insertWidget(m_lay->count() - 1, button);
    QAbstractSlider * slider = new QAbstractSlider(this);
    slider->setMinimumSize(200, 20);
    slider->setOrientation(Qt::Orientation::Horizontal);
    slider->setStyleSheet(" QWidget { backgound: white; }");
    QSlider *SpeficSlider = new QSlider(this);
    SpeficSlider->setMinimumSize(200, 20);
    SpeficSlider->setOrientation(Qt::Orientation::Horizontal);
    m_lay->addWidget(slider);
    m_lay->addWidget(SpeficSlider);
}
