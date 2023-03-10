#ifndef GAMECONTROL_HPP
#define GAMECONTROL_HPP

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

class GameControl : public QObject
{
	Q_OBJECT

	private:
		unsigned short m_screen_width;
		unsigned short m_screen_height;
		
		QTimer* m_timer = nullptr;
		QGraphicsScene* m_scene = nullptr;
		QGraphicsView* m_view = nullptr;
		QGraphicsRectItem* m_paddle = nullptr;

	private:
		void setConnect();
		void initTimer();
		void initGraphics(unsigned short, unsigned short);

		QGraphicsView* createView(QGraphicsScene*);
		QGraphicsScene* createScene();
		QGraphicsRectItem* createPaddle();

	private slots:
		void onUpdate();

	public:
		GameControl(unsigned short, unsigned short);
		~GameControl() = default;
};

#endif
