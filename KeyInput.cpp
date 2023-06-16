#include <iostream>

#include "KeyInput.hpp"

void
KeyInput::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Right) {
        emit moveRight();
    } else if (event->key() == Qt::Key_Left) {
        emit moveLeft();
    } else {
        QWidget::keyPressEvent(event);
    }
}

KeyInput::KeyInput()
    : QWidget()
{}
