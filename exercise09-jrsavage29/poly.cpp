#include <QApplication>

#include "buttons.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	Buttons buttons;
	buttons.show();
	return app.exec();
}