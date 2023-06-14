#ifndef KEYINPUT_HPP
#define KEYINPUT_HPP

#include <QObject>
#include <QWidget>
#include <QKeyEvent>

class KeyInput : public QWidget
{
    Q_OBJECT

    signals:
        void moveLeft();
        void moveRight();

    protected:
        void keyPressEvent(QKeyEvent*) override;

    public:
        KeyInput();
        ~KeyInput() = default;
};

#endif