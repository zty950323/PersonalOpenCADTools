#ifndef TZDOCKETBUTTON_H
#define TZDOCKETBUTTON_H

#include <QToolButton>
#include <QStyle>

class TzDocketButton : public QToolButton
{
    Q_OBJECT
public:
    TzDocketButton(QWidget * parent, QStyle::SubControl control)
        : QToolButton(parent)
        , m_control(control)
    {
        setFixedSize(20, 20);
    }
protected:
    void paintEvent(QPaintEvent *) override;
private:
    QStyle::SubControl m_control;
};

#endif // TZDOCKETBUTTON_H
