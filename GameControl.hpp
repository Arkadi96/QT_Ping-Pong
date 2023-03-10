#ifndef GAMECONTROL_HPP
#define GAMECONTROL_HPP

#include <QObject>
#include <QTime>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

class GameControl : public QObject
{
	Q_OBJECT

	private:
		QGraphicsView* createView();
		QGraphicsScene* createScene();
		QGraphicsRectItem* createPaddle();

	private:
		void setConnect();
		void initTime();
		void initGraphics();

	private slots:
		void onUpdate();

	public:
		GameControl();
		~GameControl() = default;
};

#endif
