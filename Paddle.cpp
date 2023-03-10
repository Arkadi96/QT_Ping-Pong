#include "Paddle.h"

extern const int G_WIDTH;
extern const int G_HEIGHT;

void
Paddle::moveRight(float deltaTime)
{
	if (m_pos_x0 > 0 && m_pos_x0 + m_length < G_WIDTH) {
		m_pos_x0 = m_pos_x0 + deltaTime * m_speed;
	} else {
		// Toggling effect
		m_pos_x0 = m_pos_x0 - 5;
	}
}

void
Paddle::moveLeft(float deltaTime)
{
	if (m_pos_x0 > 0 && m_pos_x0 + m_length < G_WIDTH) {
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

Paddle::Paddle()
	: m_pos_x0(G_WIDTH/2 - 25)
	, m_pos_y0(G_HEIGHT - 20)
	, m_height(10)
	, m_length(50)	
	, m_speed(1)
{}

Paddle::~Paddle() = default;
