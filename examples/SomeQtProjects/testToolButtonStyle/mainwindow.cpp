#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_buttonMenu = new QMenu(this);
    m_buttonMenu->addAction("123312321");
    m_buttonMenu->addAction("123312321");
    m_buttonMenu->addAction("123312321");
    m_buttonMenu->addAction("123312321");
    QAction * action = new QAction("3213");
    action->setCheckable(true);
    QAction * action1 = new QAction("32213");
    action1->setCheckable(true);
    m_buttonMenu->addAction(action);
    m_buttonMenu->addAction(action1);
    ui->toolButton->setMenu(m_buttonMenu);
    ui->toolButton->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
    ui->toolButton_2->setMenu(m_buttonMenu);
    ui->toolButton_2->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
    ui->toolButton_3->setMenu(m_buttonMenu);
    ui->toolButton_3->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
    ui->toolButton_4->setMenu(m_buttonMenu);
    ui->toolButton_4->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
    ui->toolButton_5->setMenu(m_buttonMenu);
    ui->toolButton_5->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
    ui->toolButton_6->setMenu(m_buttonMenu);
    ui->toolButton_6->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
    ui->toolButton_7->setMenu(m_buttonMenu);
    ui->toolButton_7->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
    ui->toolButton_8->setMenu(m_buttonMenu);
    ui->toolButton_8->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
    ui->toolButton_9->setMenu(m_buttonMenu);
    ui->toolButton_9->setPopupMode(QToolButton::ToolButtonPopupMode::InstantPopup);
}

MainWindow::~MainWindow()
{
    delete ui;
}

