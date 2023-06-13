#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <QGraphicsRectItem>

class Paddle
{
public:
    static Paddle& get(unsigned short, unsigned short, float);

public slots:
    void moveLeft();
    void moveRight();

private:
    int m_pos_x0;
    int m_pos_y0;

    int m_height;
    int m_length;
    int m_speed;
    float m_dt_ms;

    unsigned short m_screen_width;
    unsigned short m_screen_height;


public:
    void setPos(int, int);
    void setLength(int);
    void setSpeed(int);
    void setDeltaTime(float);

    QGraphicsRectItem* getPaddleItem();

public:
    Paddle(unsigned short, unsigned short, float);
    ~Paddle();
};

#endif
