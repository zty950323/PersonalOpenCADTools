#include "switchwidgetinner.h"
#include "ui_switchwidgetinner.h"

// Qt Interfaces.
#include <QPushButton>
#include <QFile>
#include <QDomDocument>
#include <QButtonGroup>
#include <QDebug>

void switchWidgetInner::initUi()
{
    m_verticalLayout = ui->verticalLayout;
    m_widget = ui->widget;
    m_horizontalLayout = ui->horizontalLayout;
    m_horizontalSpacer = ui->horizontalSpacer;
    m_pushButton = ui->pushButton;
    m_pushButton_2 = ui->pushButton_2;
    m_pushButton_3 = ui->pushButton_3;
    m_pushButton_4 = ui->pushButton_4;
    m_horizontalSpacer_2 = ui->horizontalSpacer_2;
    m_stackedWidget = ui->stackedWidget;
    m_page = ui->page;
    m_page_2 = ui->page_2;
    m_page_3 = ui->page_3;
    m_page_4 = ui->page_4;
    m_group = new QButtonGroup;
    m_group->addButton(m_pushButton, 0);
    m_group->addButton(m_pushButton_2, 1);
    m_group->addButton(m_pushButton_3, 2);
    m_group->addButton(m_pushButton_4, 3);
}

void switchWidgetInner::initConnections()
{
    for (int i = 0; i < m_group->buttons().length(); ++i) {
        qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << ": " << i;
        connect(m_group, QOverload<int>::of(&QButtonGroup::buttonClicked),
                this, &switchWidgetInner::changeIndex);
    }
}

switchWidgetInner::switchWidgetInner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::switchWidgetInner)
{
    ui->setupUi(this);
    initUi();
    initConnections();
    QPushButton * button = new QPushButton;
    ui->widget->layout()->addWidget(button);
    QFile ui_xml(":/ui_files/switchwidgetinner.ui");
    if(!ui_xml.open(QFile::ReadOnly | QFile::Text))
    {
        Q_ASSERT(false);
    }
    QDomDocument doc;
    if (!doc.setContent(&ui_xml, true)) {
        ui_xml.close();
    }
}

switchWidgetInner::~switchWidgetInner()
{
    delete ui;
}

QWidget *switchWidgetInner::topControl()
{
    return ui->widget;
}

void switchWidgetInner::changeIndex(int index)
{
    qDebug() << __FILE__ << __FUNCTION__ << __LINE__ << ": " << index;
    m_stackedWidget->setCurrentIndex(index);
}
