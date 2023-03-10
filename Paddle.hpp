#ifndef PADDLE_HPP
#define PADDLE_HPP

#include <QGraphicsRectItem>

class Paddle 
{
	private:
		int m_pos_x0;
		int m_pos_y0;

		int m_height;
		int m_length;
		int m_speed;

		unsigned short m_screen_width;
		unsigned short m_screen_height;
	public:
		void setPos(int, int);
		void setLength(int);
		void setSpeed(int);

		QGraphicsRectItem* getPaddle();
		
		void moveLeft(float);
		void moveRight(float);

	public:
		Paddle(unsigned short, unsigned short); 
		~Paddle();		
};

#endif
