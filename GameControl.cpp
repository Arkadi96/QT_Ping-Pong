#include "GameControl.hpp"
#include "Paddle.hpp"

#include <iostream>

QGraphicsView*
GameControl::createView(QGraphicsScene* m_scene)
{
    QGraphicsView* view = new QGraphicsView(m_scene);

    return view;
}

QGraphicsRectItem*
GameControl::createPaddle()
{
    Paddle* paddle = &Paddle::get(m_screen_width, m_screen_height);
    QGraphicsRectItem* paddleItem = paddle->getPaddle();

    return paddleItem;
}

QGraphicsScene*
GameControl::createScene()
{
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, m_screen_width, m_screen_height);

    return scene;
}

void
GameControl::onUpdate()
{
    // if left is pressed
        // move Paddle left
    // else
        // move Paddle right

    // Ball physics update

    // Check for the collision, if true
        // change Ball moving vector

    std::cout << "hi\n";
}

void
GameControl::setConnect()
{
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onUpdate()));
    m_timer->start(1000);
}

void
GameControl::initTimer()
{
    m_timer = new QTimer();
}

void
GameControl::initGraphics(unsigned short w, unsigned short h)
{
    m_screen_width = w;
    m_screen_height = h;
    m_scene = createScene();
    m_paddle = createPaddle();
    m_scene->addItem(m_paddle);
    m_view = createView(m_scene);
    m_view->setRenderHints(QPainter::Antialiasing);
    m_view->show();
}

GameControl::GameControl(unsigned short w, unsigned short h)
{
    initTimer();
    initGraphics(w, h);
    setConnect();
}
