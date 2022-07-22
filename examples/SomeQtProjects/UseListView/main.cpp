#include "mainwindow.h"
#include "TzStdMapValueFinder.h"
#include <QApplication>
#include <QDebug>

class parentC 
{
public:
    parentC(int i) 
    {
        m_i = i;
    }
    ~parentC() 
    {

    }
protected:
    int m_i = 0;
};

class childC : public parentC 
{
public:
    childC(int i = 100)
        : parentC(i)
    {

    }
};

void testMap(void) 
{
    childC c(200);
    std::map<int, QString> mapT;
    for (int i = 0; i < 10; i++)
    {
        mapT[i] = "Number : " + QString::number(i);
    }
    std::map<int, QString>::iterator iter = mapT.end();
    QString str("Number : 1");
    int num = 0;
    TzStdMapValueFinder<int, QString> p(str, num);
    iter = std::find_if(mapT.begin(), mapT.end(), p);
    qDebug() << __FILE__ << __LINE__ << __FUNCDNAME__ << iter->first << iter->second;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    testMap();
    MainWindow w;
    // w.show();
    w.showMaximized();
    return a.exec();
}
