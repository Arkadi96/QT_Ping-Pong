#include <iostream>
#include <cassert>

#include "GameControl.hpp"

QTimer*
GameControl::createTimer()
{
    m_timer = new QTimer();

    return m_timer;
}

QRectF*
GameControl::createSceneRect()
{
    assert(m_scene != nullptr);
    QRectF* sceneRect = new QRectF(m_scene->sceneRect());

    return sceneRect;
}

KeyInput*
GameControl::createKeyInput()
{
    KeyInput* keyinput = new KeyInput();
    keyinput->setStyleSheet("background-color:red");
    keyinput->setWindowOpacity(0.3);

    return keyinput;
}

QGraphicsView*
GameControl::createView()
{
    assert(m_scene != nullptr);
    assert(m_sceneRect != nullptr);
    assert(m_proxy != nullptr);

    m_scene->addItem(m_proxy);
    m_scene->addItem(m_paddle->getPaddleItem());

    QGraphicsView* view = new QGraphicsView(m_scene);
    view->setFixedSize(m_sceneRect->width(), m_sceneRect->height());
    view->setRenderHints(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    return view;
}

Paddle*
GameControl::createPaddle()
{
    assert(m_scene != nullptr);
    Paddle* paddle = &Paddle::get(
        (QObject*)m_scene,
        m_screen_width,
        m_screen_height,
        m_rate_ms);

    return paddle;
}

QGraphicsScene*
GameControl::createScene()
{
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, m_screen_width, m_screen_height);

    return scene;
}

QGraphicsProxyWidget*
GameControl::createProxyWidget()
{
    assert(m_keyinput != nullptr);
    assert(m_sceneRect != nullptr);

    QGraphicsProxyWidget* proxy = new QGraphicsProxyWidget();
    proxy->setWidget(m_keyinput);
    proxy->setPos(m_sceneRect->topLeft());
    proxy->setMinimumSize(m_sceneRect->width(), m_sceneRect->height());
    proxy->setMaximumSize(m_sceneRect->width(), m_sceneRect->height());

    return proxy;
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
//    connect(m_timer, SIGNAL(timeout()), this, SLOT(onUpdate()));
    assert(m_keyinput != nullptr);
    assert(m_paddle != nullptr);
//    m_paddle->setLength(300);
  //  connect(m_keyinput, &KeyInput::moveLeft, m_paddle, &Paddle::moveLeft);
    //connect(m_keyinput, &KeyInput::moveRight, m_paddle, &Paddle::moveRight);

    m_timer->start(m_rate_ms);
}

void
GameControl::initGraphics(unsigned short w, unsigned short h, float dt)
{
    m_screen_width = w;
    m_screen_height = h;
    m_rate_ms = dt;

//    std::cout << "Scene\n";
    m_scene = createScene();
//    std::cout << "Key\n";
    m_keyinput = createKeyInput();
//    std::cout << "Rect\n";
    m_sceneRect = createSceneRect();
//    std::cout << "Widget\n";
    m_proxy = createProxyWidget();
//    std::cout << "Paddle\n";
    m_paddle = createPaddle();
//    std::cout << "View\n";
    m_view = createView();
//    std::cout << "Timer\n";
    m_timer = createTimer();
}

GameControl::GameControl(unsigned short w, unsigned short h, float dt)
{
    initGraphics(w, h, dt);
    setConnect();
}
