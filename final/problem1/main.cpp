#include <QApplication>
#include "massconv.hpp"

int main(int argc, char *argv[])
{
	// TODO: add your code here
  QApplication app(argc, argv);
  Mass_Converter massConverter;
  massConverter.show();
  return app.exec();
}
