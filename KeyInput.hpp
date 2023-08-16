#ifndef KEYINPUT_HPP
#define KEYINPUT_HPP

#include <QObject>
#include <QWidget>
#include <QKeyEvent>
#include <thread>

class KeyInput : public QWidget
{
    Q_OBJECT

    signals:
        void moveLeftArrow();
        void moveRightArrow();
        void moveLeftLetter();
        void moveRightLetter();

    protected:
        void keyPressEvent(QKeyEvent*) override;

    public:
        KeyInput();
        ~KeyInput() = default;
};

#endif
