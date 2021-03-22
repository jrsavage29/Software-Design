// complex_widget.cpp
#include <QtWidgets>
#include <QDebug>
#include <cmath>
#include <math.h>
#include "complex_widget.hpp"
#include <iostream>

#define PI 3.14159265359


ComplexWidget::ComplexWidget()
{
  // real
  QLabel *realLabel           = new QLabel("Real: ");
  m_realLineEdit              = new QLineEdit;
  m_realLineEdit->setPlaceholderText("0.0");
  m_realLineEdit->setFocus();
  
  
  // imaginary
  QLabel *imaginaryLabel           = new QLabel("Imaginary: ");
  m_imaginaryLineEdit              = new QLineEdit;
  m_imaginaryLineEdit->setPlaceholderText("0.0");
  m_imaginaryLineEdit->setFocus();
  

  // magnitude
  QLabel *magnitudeLabel      = new QLabel("Magnitude: ");
  m_magnitudeValueLabel       = new QLabel("0.0");
  
  
  // phase
  QLabel *phaseLabel      = new QLabel("Phase: ");
  m_phaseValueLabel       = new QLabel("0.0");
  
  
  errorReal = false;
  errorImag = false;
  errorPhase = false;
  errorMag = false;

  // pushbutton for updating display  
  QPushButton* button = new QPushButton("Update");
  button->setToolTip("Click to update");
  
  // grid layout
  QGridLayout *layout         = new QGridLayout;
  layout->addWidget(realLabel,             0, 0);
  layout->addWidget(m_realLineEdit,        0, 1);
  
  layout->addWidget(imaginaryLabel,        1, 0);
  layout->addWidget(m_imaginaryLineEdit,   1, 1);

  layout->addWidget(phaseLabel,            3, 0);
  layout->addWidget(m_phaseValueLabel,     3, 1);

  layout->addWidget(magnitudeLabel,        2, 0);
  layout->addWidget(m_magnitudeValueLabel, 2, 1);

  layout->addWidget(button, 4, 1);
  
  // connect a signal and slots
  QObject::connect(button, SIGNAL(clicked()), this, SLOT(updateClicked()));

  // prepare to show
  setLayout(layout);
  setWindowTitle("Exercise 10");
}

double ComplexWidget::getRealPart()
{
  // NOTE: convert a QString to double
  // https://stackoverflow.com/questions/43685944/qstring-to-double

  bool ok(false);
  double d = m_realLineEdit->text().toDouble(&ok);
  if (ok) {
	  errorReal = false;
    return d;
  }
  else
  {
	// error message
	//QGridLayout *layout         = new QGridLayout;
	//QLabel *errorLabel  = new QLabel("Error: This is invalid!");
	//layout->addWidget(errorLabel,        0, 1);
  // TO-DO: need to handle error
	errorReal = true;
	return -1.0;
  }
}


double ComplexWidget::getImaginaryPart()
{
	bool ok(false);
  double d = m_imaginaryLineEdit->text().toDouble(&ok);
  if (ok) {
	  errorImag = false;
    return d;
  }
  else
  {// TO-DO: need to handle error
	// error message
	//QGridLayout *layout         = new QGridLayout;
	//QLabel *errorLabel  = new QLabel("Error: This is invalid!");
	//layout->addWidget(errorLabel,        1, 1);
	errorImag = true;
	return -1.0;
  }
}


double ComplexWidget::getMagnitude()
{
  // NOTE: https://en.wikipedia.org/wiki/Complex_number
  double returnValue = sqrt( pow(getRealPart(), 2) + pow(getImaginaryPart(), 2) );
  
  if(returnValue < 0.0)
  {
	  returnValue *= -1.0;
  }
  return returnValue;
}


double ComplexWidget::getPhase()
{
	double returnReal = getRealPart();
	double returnImag = getImaginaryPart();
	
	double mag = sqrt( pow(getRealPart(), 2) + pow(getImaginaryPart(), 2) );
	double phase = 2*atan(returnImag / (mag + returnReal));
	
	if(returnReal > 0 || returnImag != 0)
	{
		errorPhase = false;
		return phase;
	}
	
	else if(returnReal < 0 && returnImag == 0)
	{
		errorPhase = false;
		return PI;
	}
	
	else
	{
		// error message
		//QGridLayout *layout         = new QGridLayout;
		//QLabel *errorLabel  = new QLabel("Error: This is invalid!");
		//layout->addWidget(errorLabel,       3, 1);
		errorPhase = true;
		return -1.0;
	}
	
}


void ComplexWidget::updateClicked()
{
  // NOTE: convert a double to QString
  // https://stackoverflow.com/questions/5940846/convert-a-double-to-a-qstring
  
  double m = getMagnitude();
  
  if(errorReal == false && errorImag == false)
  {
	QString magnitude_str = QString::number(m);
	m_magnitudeValueLabel->setText(magnitude_str);
  }
  
  else
  {
	  errorMag = true;
	  m_magnitudeValueLabel->setText(QString("Error: Invalid calculation for magnitude!"));
  }
  
  double n = getPhase();
  
  if((errorReal == false && errorImag == false) && errorPhase == false && errorPhase == false)
  {
	QString phase_str = QString::number(n);
	m_phaseValueLabel->setText(phase_str);
  }
  
  else
  {
	  m_phaseValueLabel->setText(QString("Error: Invalid calculation for phase!"));
  }
}

