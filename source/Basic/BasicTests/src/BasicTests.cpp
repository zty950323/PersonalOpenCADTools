/**
 * Copyright (c) 2021, Tom Zhao personal. ("TZOpenTools")
 * This software is a personal tools project by Tom Zhao.
 * Description:
 */

#include "BasicTests.h"

#include <QtGui/QMouseEvent>
#include <QtGui/QStandardItemModel>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTreeView>

#include "Widgets/widgets_keep_menu.h"
#include "BasicTests.h"
#include "BasicTests.h"

static void InitTree(QTreeView* pView)
{
    // 1. ����Model������ʾ������3���ϵ��model�������
    QStandardItemModel* pModel = new QStandardItemModel(pView);
    pModel->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("���") << QStringLiteral("����"));     //������ͷ
    for(size_t i = 0; i < 5;i++)
    {
        // һ���ڵ㣬����mModel
        QList<QStandardItem*> items1;
        QStandardItem* pItem1 = new QStandardItem(QString::number(i));
        QStandardItem* pItem2 = new QStandardItem(QStringLiteral("һ���ڵ�"));
        items1.append(pItem1);
        items1.append(pItem2);
        pModel->appendRow(items1);

        for(size_t j = 0; j < 5; j++)
        {
            // �����ڵ�, �����1��һ���ڵ�
            QList<QStandardItem*> items2;
            QStandardItem* pItem3 = new QStandardItem(QString::number(j));
            QStandardItem* pItem4 = new QStandardItem(QStringLiteral("�����ڵ�"));
            items2.append(pItem3);
            items2.append(pItem4);
            pItem1->appendRow(items2);

            for(size_t k = 0; k < 5; k++)
            {
                // �����ڵ�, �����1�������ڵ�
                QList<QStandardItem*> items3;
                QStandardItem* pItem5 = new QStandardItem(QString::number(k));
                QStandardItem* pItem6 = new QStandardItem(QStringLiteral("�����ڵ�"));
                items3.append(pItem5);
                items3.append(pItem6);
                pItem3->appendRow(items3);
            }
        }
    }
    // 2.��QTreeViewӦ��model
    pView->setModel(pModel);
}

BasicTests::BasicTests(QWidget* parent) : QMainWindow(parent)
{
  ui.setupUi(this);
  ui.ArrayTestTab->setEdit(ui.Array_textEdit);
  ui.ArrayTestTab->setPrograssBar(ui.ArrayTestProgressBar);
  TzSoft::TzKeepMenu *menu = new TzSoft::TzKeepMenu();
  auto act1 = new QAction(tr("Icon View"));
  act1->setCheckable(true);
  menu->addAction(act1);
  menu->addAction(
      QApplication::style()->standardIcon(QStyle::SP_MessageBoxQuestion),
      tr("Detil Viwe"));
  menu->addAction(
      QApplication::style()->standardIcon(QStyle::SP_MessageBoxInformation),
      tr("Information View"));
  menu->addAction(
      QApplication::style()->standardIcon(QStyle::SP_MessageBoxWarning),
      tr("Warning View"));
  ui.toolButton_test->setMinimumSize(30, 30);
  ui.toolButton_test->setIcon(
      QApplication::style()->standardIcon(QStyle::SP_ComputerIcon));
  ui.toolButton_test->setPopupMode(QToolButton::InstantPopup);
  ui.toolButton_test->setMenu(menu);
}

void BasicTests::on_Add_tree_item_button_clicked(bool)
{
    auto pUiTreeView = ui.AimTreeView;
    if (pUiTreeView)
    {
        InitTree(pUiTreeView);
    }
    pUiTreeView->viewport()->setMouseTracking(true);
    pUiTreeView->setMouseTracking(true);
    pUiTreeView->setCursor(Qt::PointingHandCursor);
}

void BasicTests::on_Array_start_pushButton_clicked(bool)
{
  QMessageBox::information(this, QStringLiteral("Start Test"),
                           QStringLiteral("Simple Test For Array."),
                           QMessageBox::Yes);
  ui.ArrayTestTab->start();
}

void BasicTests::on_Array_end_pushButton_clicked(bool)
{
  QMessageBox::information(this, QStringLiteral("End Test"),
                           QStringLiteral("Simple Test For Array."),
                           QMessageBox::Yes);
  ui.ArrayTestTab->end();
}
