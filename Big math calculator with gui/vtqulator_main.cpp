////////////////////////////////////////////////////////
// ECE 3574, Project 3 starter code
//

#include <QApplication>

#include "vtqulator_gui.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	VtqulatorGui gui;
	gui.show();
	return app.exec();
}