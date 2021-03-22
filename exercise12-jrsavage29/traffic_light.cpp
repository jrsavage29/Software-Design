// traffic_light.cpp
#include "traffic_light.h"

#include <QWidget>
#include <QLayout>
#include <QRadioButton>

TrafficLight::TrafficLight(QWidget * parent): QWidget(parent){

  position = 0;
  
  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");
  
  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");
    
  greenlight = new QRadioButton;
  greenlight->setEnabled(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
  
  auto layout = new QVBoxLayout;
  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);

  setLayout(layout);
}

void TrafficLight::toggle()
{
	switch(position % 3)
	{
		case 0:
			redlight->toggle();
			greenlight->toggle();
			break;
			
		case 1:
			greenlight->toggle();
			yellowlight->toggle();
			break;
		
		case 2:
			yellowlight->toggle();
			redlight->toggle();
			break;
		
	};
	position++;
}