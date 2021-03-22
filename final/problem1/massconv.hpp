#ifndef MASS_CONVERTER_HPP
#define MASS_CONVERTER_HPP

#include <QtWidgets>
#include <string>
#include <cmath>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <sstream>

using std::string;


class Mass_Converter : public QWidget
{
  Q_OBJECT

public:
	Mass_Converter();
	QLineEdit *input_display;
	QLineEdit *output_display;

public slots:
  void updateClicked();
  
  void inputOunces();
  void inputPounds();
  void inputKilograms();
  
  void outputOunces();
  void outputPounds();
  void outputKilograms();
  
  double massConversion(double mass);

private:
  QGroupBox* createInputGroup();
  QGroupBox* createOutputReadOnlyGroup();
  QGroupBox* createInputRadioGroup();
  QGroupBox* createOutputRadioGroup();
  
  bool inKilograms;
  bool inPounds;
  bool inOunces;
  
  bool outKilograms;
  bool outPounds;
  bool outOunces;

};



#endif
