#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QListView>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QDebug>

#define ListView ui->listView
#define ListWidget ui->listWidget
#define TextViewer ui->textBrowser

#define TZ_WINDOW_TEST

int funcyAddMethod(int a, int b) 
{
#ifdef TZ_WINDOW_TEST
	return a + b;
#else
	if (a < b)
	{
		return b;
	}
	else if (a == b)
	{
		return a + b;
	}
	else 
	{
		return a;
	}
#endif
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ListView->setViewMode(QListView::ViewMode::IconMode);
    ListView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    ListView->setIconSize(QSize(128, 128));
    ListWidget->setViewMode(QListView::ViewMode::IconMode);
    ListWidget->setSelectionMode(QAbstractItemView::SelectionMode::MultiSelection);
    ListWidget->setIconSize(QSize(128, 128));
    QStandardItem * item = new QStandardItem(QIcon(":/images/013package.png"), "Package!");
    item->setEditable(false);
    QStandardItem * item1 = new QStandardItem(QIcon(":/images/013package.png"), "Big Package!");
    item1->setEditable(false);
    QStandardItem *item2= new QStandardItem(QIcon(":/images/004box.png"), "Box!");
    item2->setEditable(false);
    QAction * act = new QAction(tr("Show On Bottom"));
    connect(act, &QAction::triggered, [act](bool checked)
    {
        if (!checked)
        {
            act->setText(tr("Show On Top"));
            act->setCheckable(true);
            act->setChecked(true);
        }
        else
        {
            act->setText(tr("Show On Bottom"));
            act->setCheckable(false);
            act->setChecked(false);
        }
    });
    QMenu * menu = new QMenu(this);
    menu->addAction(act);
    ui->pushButton->setMenu(menu);
    ui->pushButton_2->setMenu(menu);
    ui->pushButton_3->setMenu(menu);

    QStandardItemModel * model = new QStandardItemModel(this);
    model->appendRow(item);
    model->appendRow(item1);
    model->appendRow(item2);
    ListView->setModel(model);

    // init ListWidget
    QListWidgetItem * wItem = new QListWidgetItem(QIcon(":/images/013package.png"), "Big Package!", ListWidget);
    QListWidgetItem* wItem1 = new QListWidgetItem(QIcon(":/images/013package.png"), "Package!", ListWidget);
    QListWidgetItem* wItem2 = new QListWidgetItem(QIcon(":/images/004box.png"), "Big Box!", ListWidget);

    connect(ui->pushButton, &QPushButton::clicked, [this](bool checked) 
        {
#ifdef TZ_WINDOW_TEST
			// QMenu * menu = new QMenu();
            qDebug() << "Use Test the  button states:" << checked;
			// menu->move(mapToGlobal(ui->pushButton->rect().bottomRight() + QPoint(menu->rect().width(), menu->rect().height())));
			// menu->exec();
#else
		ui->pushButton->setChecked(checked);
		QMenu * menu = new QMenu();
		menu->move(mapToGlobal(ui->pushButton->rect().bottomRight() + QPoint(menu->rect().width(), menu->rect().height())));
		ui->pushButton->setMenu(menu);
#endif
        });
}

MainWindow::~MainWindow()
{
    delete ui;
}