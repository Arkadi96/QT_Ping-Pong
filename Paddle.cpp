#include "Paddle.hpp"

Paddle&
Paddle::get(unsigned short w, unsigned short h)
{
    static Paddle p(w,h);
    return p;
}

void
Paddle::moveRight(float deltaTime)
{
    if (m_pos_x0 > 0 && m_pos_x0 + m_length < m_screen_width) {
        m_pos_x0 = m_pos_x0 + deltaTime * m_speed;
    } else {
        // Toggling effect
        m_pos_x0 = m_pos_x0 - 5;
    }
}

void
Paddle::moveLeft(float deltaTime)
{
    if (m_pos_x0 > 0 && m_pos_x0 + m_length < m_screen_width) {
        m_pos_x0 = m_pos_x0 - deltaTime * m_speed;
    } else {
        // Toggling effect
        m_pos_x0 = m_pos_x0 + 5;
    }
}

QGraphicsRectItem*
Paddle::getPaddle()
{
    QGraphicsRectItem* paddle = new QGraphicsRectItem(
    m_pos_x0,
    m_pos_y0,
    m_length,
    m_height);

    return paddle;
}

void
Paddle::setSpeed(int s)
{
    m_speed = s;
}

void
Paddle::setLength(int l)
{
    m_length = l;
}

void
Paddle::setPos(int x0, int y0)
{
    m_pos_x0 = x0;
    m_pos_y0 = y0;
}

Paddle::Paddle(unsigned short w, unsigned short h)
    : m_pos_x0(w/2 - 25)
    , m_pos_y0(h - 20)
    , m_height(10)
    , m_length(50)	
    , m_speed(1)
    , m_screen_width(w)
    , m_screen_height(h)
{}

Paddle::~Paddle() = default;
