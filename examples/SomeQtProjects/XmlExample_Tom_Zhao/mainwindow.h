#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QXmlStreamReader>

class QDomElement;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    bool readFile(const QString &fileName);
    bool readDomFile(const QString &fileName);
private:
    void readBookindexElement();
    void readEntryElement(QTreeWidgetItem *parent);
    void readPageElement(QTreeWidgetItem *parent);
    void parseBookindexElement(const QDomElement &element);
    void parseEntryElement(const QDomElement &element, QTreeWidgetItem *parent);
    void parsePageElement(const QDomElement &element, QTreeWidgetItem *parent);

    void skipUnknownElement();

    QTreeWidget* _treeWidget;
    QTreeWidget* _domWidget;
    QXmlStreamReader _reader;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
