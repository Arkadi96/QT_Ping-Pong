#include <QApplication>
//#include <QWidget>

// User to add headers here
#include "GameControl.hpp"
//#include "KeyInput.hpp"

#define G_WIDTH 360
#define G_HEIGHT 640
#define G_FREQ 1000

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    GameControl gameControl(G_WIDTH, G_HEIGHT, G_FREQ);

    return app.exec();
}
