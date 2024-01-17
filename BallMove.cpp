#include <iostream>

#include "Paddle.hpp"

Paddle&
Paddle::get(QObject *p, unsigned short w, unsigned short h, float dt)
{
    static Paddle paddle(p,w,h,dt);
    return paddle;
}

void
Paddle::moveRight()
{
    int step = (int)m_dt_ms/100 * m_speed;
    if (m_pos_x0 + m_length + step < m_screen_width) {
        m_pos_x0 += step;
    } else {
        m_pos_x0 = m_pos_x0 - step/2;
    }
    emit paddleUpdated();
}

void
Paddle::moveLeft()
{
    int step = (int)m_dt_ms/100 * m_speed;
    if (m_pos_x0 - step > 0) {
        m_pos_x0 -= step;
    } else {
        m_pos_x0 = m_pos_x0 + step/2;
    }
    emit paddleUpdated();
}

QGraphicsRectItem*
Paddle::getPaddleItem()
{
    QGraphicsRectItem* paddle = new QGraphicsRectItem(
        m_pos_x0,
        m_pos_y0,
        m_length,
        m_height);

    return paddle;
}

void
Paddle::setDeltaTime(float dt)
{
    m_dt_ms = dt;
}

void
Paddle::setSpeed(int s)
{
    m_speed = s;
}

void
Paddle::setLength(int l)
{
    std::cout << "length changed\n";
    m_length = l;
}

void
Paddle::setPos(int x0, int y0)
{
    m_pos_x0 = x0;
    m_pos_y0 = y0;
}

Paddle::Paddle(QObject *p)
    : QObject(p)
{}

Paddle::~Paddle() = default;
