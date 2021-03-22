// main.cpp
#include <QApplication>

#include "traffic_light.h"
#include <QTimer>
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  TrafficLight light;
  int returnValue;

  // setup the timer and connection here
  QTimer* timer = new QTimer;
  QObject::connect(timer, SIGNAL(timeout()), &light, SLOT(toggle()));
  
  light.show();
  timer->start(500); //the period for generating the event. Unit in ms
  returnValue = app.exec();
  delete timer;
  return returnValue;
}
