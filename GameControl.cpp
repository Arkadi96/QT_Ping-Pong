#include <iostream>
#include <cassert>

#include "GameControl.hpp"

QGraphicsRectItem*
GameControl::createFirstRectItem()
{
    assert(m_first_paddle != nullptr);
    QGraphicsRectItem* rectItem = m_first_paddle->getPaddleItem();

    return rectItem;
}

QGraphicsRectItem*
GameControl::createSecondRectItem()
{
    assert(m_second_paddle != nullptr);
    QGraphicsRectItem* rectItem = m_second_paddle->getPaddleItem();

    return rectItem;
}

QTimer*
GameControl::createTimer()
{
    QTimer* timer = new QTimer();

    return timer;
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
    assert(m_first_rect != nullptr);
    assert(m_second_rect != nullptr);

    m_scene->addItem(m_proxy);
    m_scene->addItem(m_first_rect);
    m_scene->addItem(m_second_rect);

    QGraphicsView* view = new QGraphicsView(m_scene);
    view->setFixedSize(m_sceneRect->width(), m_sceneRect->height());
    view->setRenderHints(QPainter::Antialiasing);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    return view;
}

Paddle*
GameControl::createFirstPaddle()
{
    assert(m_scene != nullptr);
    Paddle* paddle = new Paddle(
        (QObject*)m_scene,
        m_screen_width,
        m_screen_height,
        m_rate_ms);

    paddle->setHeight(10);
    paddle->setLength(50);
    paddle->setPos(m_screen_width/2 - 25, m_screen_height - 20);

    return paddle;
}

Paddle*
GameControl::createSecondPaddle()
{
    assert(m_scene != nullptr);
    Paddle* paddle = new Paddle(
        (QObject*)m_scene,
        m_screen_width,
        m_screen_height,
        m_rate_ms);

    paddle->setHeight(10);
    paddle->setLength(50);
    paddle->setPos(m_screen_width/2 - 25, 20);

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
    assert(m_view != nullptr);
    assert(m_scene != nullptr);
    assert(m_first_rect != nullptr);
    assert(m_second_rect != nullptr);

    // updating rect item
    m_scene->removeItem(m_first_rect);
    m_scene->removeItem(m_second_rect);
    m_first_rect = nullptr;
    m_second_rect = nullptr;
    m_first_rect = createFirstRectItem();
    m_second_rect = createSecondRectItem();
    m_scene->addItem(m_first_rect);
    m_scene->addItem(m_second_rect);
    m_view->update();
}

void
GameControl::setConnect()
{
    assert(m_keyinput != nullptr);
    assert(m_first_paddle != nullptr);
    assert(m_second_paddle != nullptr);

    connect(m_keyinput, &KeyInput::moveLeftArrow, m_first_paddle, &Paddle::moveLeft);
    connect(m_keyinput, &KeyInput::moveRightArrow, m_first_paddle, &Paddle::moveRight);
    connect(m_keyinput, &KeyInput::moveRightLetter, m_second_paddle, &Paddle::moveLeft);
    connect(m_keyinput, &KeyInput::moveLeftLetter, m_second_paddle, &Paddle::moveRight);
    connect(m_first_paddle, &Paddle::paddleUpdated, this, &GameControl::onUpdate);
    connect(m_second_paddle, &Paddle::paddleUpdated, this, &GameControl::onUpdate);

    //    connect(m_timer, SIGNAL(timeout()), this, SLOT(onUpdate()));

 //   m_timer->start(m_rate_ms);
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
    m_first_paddle = createFirstPaddle();
    m_second_paddle = createSecondPaddle();
    assert(m_first_paddle != m_second_paddle);
//    std::cout << "Rect\n";
    m_first_rect = createFirstRectItem();
    m_second_rect = createSecondRectItem();
//    std::cout << "View\n";
    m_view = createView();
//    std::cout << "Timer\n";
//    m_timer = createTimer();
}

GameControl::GameControl(unsigned short w, unsigned short h, float dt)
{
    initGraphics(w, h, dt);
    setConnect();
}
