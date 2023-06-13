#include "KeyInput.hpp"

void
KeyInput::KeyPressEvent(QKeyEvent *event)
{
    if (event->Key() == Qt::Key_Right) {
        emit moveRight();
    } else if (event->Key() == Qt::Key_Left) {
        emit moveLeft();
    } else {
        QWidget::KeyPressEvent(event);
    }
}
