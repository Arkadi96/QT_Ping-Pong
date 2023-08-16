#include "KeyInput.hpp"

void
KeyInput::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Right) {
        emit moveRightArrow();
    } else if (event->key() == Qt::Key_Left) {
        emit moveLeftArrow();
    } else {
        QWidget::keyPressEvent(event);
    }

    if (event->key() == Qt::Key_A) {
        emit moveRightLetter();
    } else if (event->key() == Qt::Key_D) {
        emit moveLeftLetter();
    } else {
        QWidget::keyPressEvent(event);
    }
}

KeyInput::KeyInput()
    : QWidget()
{}
