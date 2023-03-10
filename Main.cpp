#include <QApplication>

// User to add headers here
#include "GameControl.hpp"

#define G_WIDTH 360
#define G_HEIGHT 640

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
	GameControl gameControl(G_WIDTH, G_HEIGHT);
	 
    return app.exec();
}
