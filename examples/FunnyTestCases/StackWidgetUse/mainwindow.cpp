#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QStackedWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include <QTableWidget>
#include <QDebug>
#include "TZButtonGroupWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initData();
    initUi();
    initConnections();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUi()
{
    ///
    /// \brief group crate some thing
    ///
    TZButtonGroupWidget* group = new TZButtonGroupWidget;
    group->testSetFlat(true);
    group->addButton();
    ui->stackedWidget->addWidget(group);
    this->resize(1920 / 2 , 1080 / 2);
    this->setWindowFlags(Qt::FramelessWindowHint);
    QStringList pages;
    QString pre("Page_");
    for (int i = 0; i < 12; ++i) {
        pages.append(pre + QString::number(i));
    }
    // init combobox to control the pages.

    ui->comboBox->addItems(pages);
    for (int i = 0; i < 10; ++i) {
        QWidget * cur = new QWidget(ui->stackedWidget);
        cur->setToolTip("Page_" + QString::number(i));
        QComboBox *box = new QComboBox;
        box->addItem("Page_" + QString::number(i));
        QHBoxLayout *lay = new QHBoxLayout;
        lay->addWidget(box);
        cur->setLayout(lay);
        ui->stackedWidget->addWidget(cur);
    }
    ///
    /// \brief tbw test cases.
    ///
    QVBoxLayout * layout_0 = new QVBoxLayout();
    ui->stackedWidget->widget(1)->setLayout(layout_0);
    QTableWidget *tbw = new QTableWidget(ui->stackedWidget->widget(1));
    m_table_widget = tbw;
    tbw->setMinimumSize(300, 300);
    tbw->setRowCount(100);
    tbw->setColumnCount(100);
    QTableWidgetItem * item = new QTableWidgetItem();
    item->setText("Header");
    tbw->setItem(1,1, item);
    tbw->editItem(item);
    tbw->openPersistentEditor(item);
    auto data = item->data(0);
    qDebug() << data.toString();
//    auto cell = tbw->cellWidget(1, 2);
//    cell->hide();
    QTableWidgetItem *item_default = new QTableWidgetItem("(0,0)");
    item_default->setData(1, "(1,1)");
    m_table_widget->setItemPrototype(item_default);
    m_table_widget->insertRow(1);
    // tbw->setRowCount(200);
    // tbw->setColumnCount(200);
    tbw->closePersistentEditor(item);
    ///
    /// \brief button_spacer is to create space between controls.
    ///
    QSpacerItem *button_spacer = new QSpacerItem(20, 10, QSizePolicy::Expanding);
    // init buttons
    for (int i = 0; i < 10; ++i) {
        ZsIndexedButton * button = new ZsIndexedButton(pre + QString::number(i));
        button->setIndex(i);
        button->setObjectName(pre + QString::number(i) + "_button");
        m_buttons.insert(button->objectName(), button);
        ui->horizontalLayout_buttons->addWidget(button);
        QSpacerItem *spacer = new QSpacerItem(5, 10, QSizePolicy::Expanding);
        ui->horizontalLayout_buttons->addSpacerItem(spacer);
        ui->horizontalLayout_buttons->addWidget(button);
    }
    ui->horizontalLayout_buttons->addSpacerItem(button_spacer);
    group->testRemoveButton();
}

void MainWindow::initConnections()
{
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::activated), ui->stackedWidget, &QStackedWidget::setCurrentIndex);
    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), ui->stackedWidget, &QStackedWidget::setCurrentIndex);
    for (auto iter = m_buttons.begin(); iter != m_buttons.end(); ++iter) {
        connect(iter.value(), &ZsIndexedButton::clicked, this, &MainWindow::buttonChangePages);
    }
    // connect(ui->comboBox, &QComboBox::setCurrentIndex, ui->stackedWidget, &QStackedWidget::setCurrentIndex);
}

void MainWindow::initData()
{
    // Current nothing to do.
}

void MainWindow::choseToHide(const SenderControls &control)
{
    ui->comboBox->setCurrentIndex(2);
    switch (control) {
        case SenderControls::BUTTONS:
        {
            if(ui->horizontalLayout_buttons->widget() && ui->horizontalLayout->widget())
            {
                ui->horizontalLayout_buttons->widget()->show();
                ui->horizontalLayout->widget()->hide();
            }
        }
        break;
        case SenderControls::COMBOBOX:
        {
            if(ui->horizontalLayout_buttons->widget() && ui->horizontalLayout->widget())
            {
                ui->horizontalLayout->widget()->show();
                ui->horizontalLayout_buttons->widget()->hide();
            }

        }
        break;
    }
}

void MainWindow::messageBoxUse()
{
    QMessageBox::question(this, "Question Abort!!", "This is a Question Abort test!!");
    QMessageBox::question(this, "Question Abort!!", "This is a Question Abort test!!"
                          , QMessageBox::StandardButton::Ok | QMessageBox::StandardButton::No | \
                          QMessageBox::StandardButton::Open, QMessageBox::StandardButton::Ok);
    QMessageBox box(QMessageBox::Icon::Critical, "BOX!!!", "Text", QMessageBox::StandardButton::Ok);
    switch(box.exec())
    {
        case QMessageBox::StandardButton::Ok:
            qDebug() << "OK";
            break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Escape)
    {
        this->close();
    }
    if (event->key() == Qt::Key_A)
    {
        // auto data_101 = m_table_widget->item(1, 1)->data(1);
        // Q_ASSERT(&data_101);
        // qDebug() << data_101->toString();
    }
}

void MainWindow::buttonChangePages(bool checked)
{
    ZsIndexedButton * button = (ZsIndexedButton*)sender();
    ui->stackedWidget->setCurrentIndex(button->getIndex() + 2);
}
