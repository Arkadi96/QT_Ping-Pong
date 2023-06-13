#ifndef GAMECONTROL_HPP
#define GAMECONTROL_HPP

#include <QObject>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>

#include "Paddle.hpp"
#include "KeyInput.hpp"

class GameControl : public QObject
{
    Q_OBJECT

    private:
        unsigned short m_screen_width;
        unsigned short m_screen_height;

        float m_rate_ms;

        QTimer* m_timer = nullptr;
        QGraphicsScene* m_scene = nullptr;
        QGraphicsView* m_view = nullptr;
        QGraphicsRectItem* m_paddle = nullptr;
        KeyInput* m_keyinput = nullptr;

    private:
        void setConnect();
        void initTimer(float);
        void initGraphics(unsigned short, unsigned short);

        QGraphicsView* createView(QGraphicsScene*);
        QGraphicsScene* createScene();
        Paddle* createPaddle();
        KeyInput* createKeyInput();

    private slots:
        void onUpdate();

    public:
        GameControl(unsigned short, unsigned short float);
        ~GameControl() = default;
};

#endif
