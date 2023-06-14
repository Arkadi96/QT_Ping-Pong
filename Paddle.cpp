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
    if (m_pos_x0 > 0 && m_pos_x0 + m_length < m_screen_width) {
        m_pos_x0 = m_pos_x0 + m_dt_ms * m_speed;
    } else {
        // Toggling effect
        m_pos_x0 = m_pos_x0 - 5;
    }
}

void
Paddle::moveLeft()
{
    std::cout << "left\n";
    if (m_pos_x0 > 0 && m_pos_x0 + m_length < m_screen_width) {
        m_pos_x0 = m_pos_x0 - m_dt_ms * m_speed;
    } else {
        // Toggling effect
        m_pos_x0 = m_pos_x0 + 5;
    }
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

Paddle::Paddle(QObject *p, unsigned short w, unsigned short h, float dt)
    : QObject(p)
    , m_pos_x0(w/2 - 25)
    , m_pos_y0(h - 20)
    , m_height(10)
    , m_length(50)
    , m_speed(1)
    , m_dt_ms(dt)
    , m_screen_width(w)
    , m_screen_height(h)
{}

Paddle::~Paddle() = default;
