#include <iostream>

#include "KeyInput.hpp"

void
KeyInput::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Right) {
        std::cout << "Right\n";
        emit moveRight();
    } else if (event->key() == Qt::Key_Left) {
        std::cout << "Left\n";
        emit moveLeft();
    } else {
        QWidget::keyPressEvent(event);
    }
}

KeyInput::KeyInput()
    : QWidget()
{}
