#pragma once

class TzArrowButton : public QPushButton
{
    Q_OBJECT

public:
    enum class Direction 
    {
        Left,
        Right,
        Top,
        Bottom
    };
    explicit TzArrowButton(Direction dir = Direction::Top ,QWidget *parent = nullptr);
    ~TzArrowButton();

    QSize sizeHint(void) const override;
    Direction direction() const;
    void setDirection(Direction dir);

protected:
    void paintEvent(QPaintEvent * event) override;

private:
    QPainterPath arrowPath() const;

    Direction m_direction;
};
