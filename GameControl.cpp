#include "GameControl.hpp"
#include <iostream>

QGraphicsView*
GameControl::createView()
{
    QGraphicsView* view = new QGraphicsView(m_scene);
	
	return view; 
}

QGraphicsRectItem*
GameControl::CreatePaddle()
{
	Paddle* paddle = new Paddle();
	QGraphicsRectItem* paddleItem = paddle->getPaddle();	

	return paddleItem;
}

QGraphicsScene*
GameControl::createScene()
{
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, G_WIDTH, G_HEIGHT);

	return scene;
}

void
GameControl::onUpdate()
{
	std::cout << "hi\n";	
}

void
GameControl::setConnect()
{
	connect(m_time, SIGNAL(timeout()),
		this, SLOT(update()));
}

void
GameControl::initTime()
{
	m_time = new QTime();
}

void
GameControl::initGraphics()
{
	m_scene = createScene();
	m_paddle = createPaddle();
	m_scene->addItem(m_paddle);
	m_view = createView(m_scene);
    m_view->setRenderHints(QPainter::Antialiasing);
    m_view->show();
}

GameControl::GameControl()
{
	initTime();
	initGraphics();
	setConnect();
}
