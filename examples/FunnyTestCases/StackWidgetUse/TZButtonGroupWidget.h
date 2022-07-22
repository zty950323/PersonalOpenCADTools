#pragma once

#include <QWidget>
#include <QButtonGroup>

class QHBoxLayout;
class TZButtonGroupWidget : public QWidget
{
    Q_OBJECT

public:
    TZButtonGroupWidget(QWidget *parent = Q_NULLPTR);
    ~TZButtonGroupWidget();

    void testSetFlat(const bool& flat);
    void testRemoveButton(void);
    void addButton(void);
    
    QButtonGroup m_group;
    QHBoxLayout* m_lay;
};
