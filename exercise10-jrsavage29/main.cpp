// main.cpp
#include <QApplication>
#include "complex_widget.hpp"

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  ComplexWidget complexWidget;
  complexWidget.show();
  return app.exec();
}
