#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QMessageBox>
#include <QDebug>
#include <QHBoxLayout>
#include <QDomDocument>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("XML Reader/Dom Reader"));
    _treeWidget = new QTreeWidget(this);
    _domWidget = new QTreeWidget(this);
    QStringList headers;
    headers << "Items" << "Pages";
    _treeWidget->setHeaderLabels(headers);
    _domWidget->setHeaderLabels(headers);
    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setMargin(2);
    layout->setSpacing(3);
    layout->addWidget(_treeWidget);
    layout->addWidget(_domWidget);
    QWidget *center = new QWidget;
    center->setLayout(layout);
    setCentralWidget(center);
    QString fileName = QApplication::applicationDirPath() + "/demo.xml";
    readFile(fileName);
    fileName = QApplication::applicationDirPath() + "/DomDemo.xml";
    readDomFile(fileName);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::readFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Cannot read file %1").arg(fileName));
        return false;
    }
    _reader.setDevice(&file);
    while (!_reader.atEnd())
    {

        if (_reader.isStartElement())
        {
            qDebug()<<"2222222222222222";
            if (_reader.name() == "bookindex")
            {
                readBookindexElement();//递归下降算法，层层读取
            }
            else
            {
                _reader.raiseError(tr("Not a valid book file"));
            }
        }
        else
        {
            qDebug()<<"111111111111111";
            _reader.readNext(); //循坏调用首次移动3次，后面移动一次
        }
    }
    file.close();
    if (_reader.hasError())
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Failed to parse file %1").arg(fileName));
        return false;
    }
    else if (file.error() != QFile::NoError)
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Cannot read file %1").arg(fileName));
        return false;
    }
    return true;
}

bool MainWindow::readDomFile(const QString &fileName)
{

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Cannot read file %1").arg(fileName));
        return false;
    }

    QString errorStr;
    int errorLine;
    int errorColumn;

    QDomDocument doc;
    //填充dom树
    if (!doc.setContent(&file, false, &errorStr, &errorLine,
                        &errorColumn))//形参2，是否创建命名空间
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Parse error at line %1, column %2: %3")
                              .arg(errorLine).arg(errorColumn).arg(errorStr));
        return false;
    }

    QDomElement root = doc.documentElement();//获取dom树的根标签
    if (root.tagName() != "doc")
    {
        QMessageBox::critical(this, tr("Error"),
                              tr("Not a doc file"));
        return false;
    }
    parseBookindexElement(root);
    return true;
}

void MainWindow::readBookindexElement()
{
    Q_ASSERT(_reader.isStartElement() && _reader.name() == "bookindex");//不是则会报错
    _reader.readNext(); // 读取下一个记号，它返回记号的类型
    while (!_reader.atEnd())
    {
        if (_reader.isEndElement())
        {
            _reader.readNext();
            break;
        }

        if (_reader.isStartElement())
        {
            if (_reader.name() == "entry")
            {
                readEntryElement(_treeWidget->invisibleRootItem());
            }
            else
            {
                skipUnknownElement();
            }
        }
        else
        {
            _reader.readNext();
        }
    }
}

void MainWindow::readEntryElement(QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, _reader.attributes().value("term").toString());//元素的属性

    _reader.readNext();
    while (!_reader.atEnd())
    {
        if (_reader.isEndElement())
        {
            _reader.readNext();
            break;
        }

        if (_reader.isStartElement())
        {
            if (_reader.name() == "entry")
            {
                readEntryElement(item);
            }
            else if (_reader.name() == "page")
            {
                readPageElement(item);
            }
            else
            {
                skipUnknownElement();
            }
        }
        else
        {
            _reader.readNext();
        }
    }
}

void MainWindow::readPageElement(QTreeWidgetItem *parent)
{
    QString page = _reader.readElementText();
    if (_reader.isEndElement())
    {
        qDebug()<<"3333333333333333";
        _reader.readNext();
    }

    QString allPages = parent->text(1);
    if (!allPages.isEmpty())
    {
        allPages += ", ";
    }
    allPages += page;
    parent->setText(1, allPages);
}

void MainWindow::parseBookindexElement(const QDomElement &element)
{
    QDomNode child = element.firstChild();//根标签下的子标签
    while (!child.isNull())
    {
        if (child.toElement().tagName() == "entry")//qdomnode ————》qdomelement的转换基类到子类的转换
        {
            parseEntryElement(child.toElement(),
                              _domWidget->invisibleRootItem());
        }
        child = child.nextSibling();
    }
}

void MainWindow::parseEntryElement(const QDomElement &element, QTreeWidgetItem *parent)
{
    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, element.attribute("term"));

    QDomNode child = element.firstChild();
    while (!child.isNull())//遍历标签的子标签
    {
        if (child.toElement().tagName() == "entry")
        {
            parseEntryElement(child.toElement(), item);//递归调用本身
        }
        else if (child.toElement().tagName() == "page")
        {
            parsePageElement(child.toElement(), item);
        }
        else if (child.toElement().tagName() == "quote")
        {
            parsePageElement(child.toElement(), item);
        }
        else if (child.toElement().tagName() == "translation")
        {
            parsePageElement(child.toElement(), item);
        }
        else if (child.toElement().tagName() == "money")
        {
            parsePageElement(child.toElement(), item);
        }
        else if (child.toElement().tagName() == "Panda")
        {
            parsePageElement(child.toElement(), item);
        }
        child = child.nextSibling();//指针移动一个标签
    }
}

void MainWindow::parsePageElement(const QDomElement &element, QTreeWidgetItem *parent)
{
    QString page = element.text();
    QString allPages = parent->text(1);//最开始的一次为空
    qDebug()<<"allPages "<<allPages;
    if (!allPages.isEmpty())
    {
        allPages += ", ";
    }
    allPages += page;
    parent->setText(1, allPages);
}

void MainWindow::skipUnknownElement()
{
    _reader.readNext();
    while (!_reader.atEnd())
    {
        if (_reader.isEndElement())
        {
            _reader.readNext();
            break;
        }

        if (_reader.isStartElement())
        {
            skipUnknownElement();
        }
        else
        {
            _reader.readNext();
        }
    }
}

