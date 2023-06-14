#include <iostream>
#include <cassert>

#include "GameControl.hpp"

KeyInput*
GameControl::createKeyInput()
{
    KeyInput* keyinput = new KeyInput();

    return keyinput;
}

QGraphicsView*
GameControl::createView(QGraphicsScene* m_scene)
{
    QGraphicsView* view = new QGraphicsView(m_scene);

    return view;
}

Paddle*
GameControl::createPaddle(QObject* p)
{
    Paddle* paddle = &Paddle::get(p, m_screen_width, m_screen_height, m_rate_ms);

    return paddle;
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
    assert(m_keyinput != nullptr);
    assert(m_paddle != nullptr);
    m_paddle->setLength(300);
    connect(m_keyinput, &KeyInput::moveLeft, m_paddle, &Paddle::moveLeft);
    connect(m_keyinput, &KeyInput::moveRight, m_paddle, &Paddle::moveRight);

    m_timer->start(m_rate_ms);
}

void
GameControl::initTimer(float dt)
{
    m_timer = new QTimer();
    m_rate_ms = dt;
}

void
GameControl::initGraphics(unsigned short w, unsigned short h)
{
    m_screen_width = w;
    m_screen_height = h;
    m_scene = createScene();
    m_paddle = createPaddle(m_scene);
    m_keyinput = createKeyInput();
    m_scene->addItem(m_paddle->getPaddleItem());
    m_scene->addWidget(m_keyinput);
    m_view = createView(m_scene);
    m_view->setRenderHints(QPainter::Antialiasing);
    m_view->show();
}

GameControl::GameControl(unsigned short w, unsigned short h, float dt)
{
    initTimer(dt);
    initGraphics(w, h);
    setConnect();
}
