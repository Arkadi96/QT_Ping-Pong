#include <QApplication>

// User to add headers here
#include "GameControl.hpp"

extern const int G_WIDTH = 360;
extern const int G_HEIGHT = 640;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
	GameControl gameControl;
	 
    return app.exec();
}
