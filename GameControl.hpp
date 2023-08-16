#ifndef GAMECONTROL_HPP
#define GAMECONTROL_HPP

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsProxyWidget>
#include <QRectF>

#include "Paddle.hpp"
#include "KeyInput.hpp"

class GameControl : public QObject
{
    Q_OBJECT

    private slots:
        void onUpdate();

    private:
        unsigned short m_screen_width;
        unsigned short m_screen_height;
        float m_rate_ms;

        QGraphicsScene* m_scene = nullptr;
        QGraphicsView* m_view = nullptr;
        QGraphicsProxyWidget* m_proxy = nullptr;
        QGraphicsRectItem* m_first_rect = nullptr;
        QGraphicsRectItem* m_second_rect = nullptr;
        QRectF* m_sceneRect = nullptr;
        QTimer* m_timer = nullptr;
        Paddle* m_first_paddle = nullptr;
        Paddle* m_second_paddle = nullptr;
        KeyInput* m_keyinput = nullptr;

    private:
        void setConnect();
        void initGraphics(unsigned short, unsigned short, float);

        QGraphicsView* createView();
        QGraphicsScene* createScene();
        QGraphicsProxyWidget* createProxyWidget();
        QGraphicsRectItem* createFirstRectItem();
        QGraphicsRectItem* createSecondRectItem();
        QRectF* createSceneRect();
        QTimer* createTimer();
        Paddle* createFirstPaddle();
        Paddle* createSecondPaddle();
        KeyInput* createKeyInput();

    public:
        GameControl(unsigned short, unsigned short, float);
        ~GameControl() = default;
};

#endif
