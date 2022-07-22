#ifndef SWITCHWIDGETINNER_H
#define SWITCHWIDGETINNER_H

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;
class QSpacerItem;
class QPushButton;
class ZsStackedWidget;
class QButtonGroup;

namespace Ui {
class switchWidgetInner;
}

class switchWidgetInner : public QWidget
{
    Q_OBJECT

public:
    void initUi(void);
    void initConnections(void);
    explicit switchWidgetInner(QWidget *parent = nullptr);
    ~switchWidgetInner();

    QWidget * topControl(void);
private slots:
    void changeIndex(int index);
private:
    Ui::switchWidgetInner *ui;
    QVBoxLayout *m_verticalLayout = nullptr;
    QWidget *m_widget = nullptr;
    QHBoxLayout *m_horizontalLayout = nullptr;
    QSpacerItem *m_horizontalSpacer = nullptr;
    QPushButton *m_pushButton = nullptr;
    QPushButton *m_pushButton_2 = nullptr;
    QPushButton *m_pushButton_3 = nullptr;
    QPushButton *m_pushButton_4 = nullptr;
    QSpacerItem *m_horizontalSpacer_2 = nullptr;
    ZsStackedWidget *m_stackedWidget = nullptr;
    QWidget *m_page = nullptr;
    QWidget *m_page_2 = nullptr;
    QWidget *m_page_3 = nullptr;
    QWidget *m_page_4 = nullptr;
    QButtonGroup * m_group = nullptr;
};

#endif // SWITCHWIDGETINNER_H
