#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMouseEvent>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->textEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    connect(ui->pushButton, &QPushButton::clicked, [this]()
    {
        ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setShow()
{
    ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    if (cursor().pos().x() >= this->pos().x() && cursor().pos().x() <= this->pos().x() + this->width()
            && cursor().pos().y() >= this->pos().y() && cursor().pos().y() <= this->pos().y() + this->height())
    {
        ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint cur = event->pos();
    if ((cur - ui->textEdit->pos()).x() >= ui->textEdit->width() * 0.9)
    {
        ui->textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        ui->textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    }
}
