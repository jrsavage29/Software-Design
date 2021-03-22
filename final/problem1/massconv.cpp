#include "massconv.hpp"
#include <QtWidgets>
#include <QDebug>
#include <cmath>
#include <math.h>
#include <iostream>

#define PI 3.14159265359


Mass_Converter::Mass_Converter()
{
	
	inKilograms = true;
	inPounds = false;
	inOunces = false;
  
	outKilograms = true;
	outPounds = false;
	outOunces = false;
	
	QGridLayout* grid = new QGridLayout;
	
	QPushButton* Update_button = new QPushButton("Calculate"); //creating the update pushbutton
	Update_button->setObjectName("Update_button");
	Update_button->setShortcut(QKeySequence(Qt::Key_Return));
	Update_button->setToolTip("Click to update");

	grid->addWidget(createInputGroup(),0,0);
	grid->addWidget(createOutputReadOnlyGroup(),0,1);
	grid->addWidget(createInputRadioGroup(), 1, 0); //initializes the radio buttons
	grid->addWidget(createOutputRadioGroup(), 1, 1);
	grid->addWidget(Update_button, 2,0);

	QObject::connect(Update_button, SIGNAL(clicked()), this, SLOT(updateClicked())); //connect the signal for the update pushbutton
	
	// prepare to show
	setLayout(grid);
	setWindowTitle("Mass Converter");
}

QGroupBox* Mass_Converter::createInputRadioGroup()
{
	QGroupBox* groupBox = new QGroupBox(tr("Input Mass Units"));

	QRadioButton* Radiobutton_KilogramsL = new QRadioButton(tr("Kilogram"));
	Radiobutton_KilogramsL->setObjectName("Radiobutton_KilogramsL");
	
	QRadioButton* Radiobutton_PoundsL = new QRadioButton(tr("Pounds"));
	Radiobutton_PoundsL->setObjectName("Radiobutton_PoundsL");
	
	QRadioButton* Radiobutton_OuncesL = new QRadioButton(tr("Ounces"));
	Radiobutton_OuncesL->setObjectName("Radiobutton_OuncesL");
	
	Radiobutton_KilogramsL->setChecked(true); //Set the radio button for fahrenheit to already be checked
	

	QGridLayout* grid = new QGridLayout;
	grid->addWidget(Radiobutton_KilogramsL,0,0);
	grid->addWidget(Radiobutton_PoundsL,1,0);
	grid->addWidget(Radiobutton_OuncesL,2,0);
	
	
	
	groupBox->setLayout(grid);
	
	QObject::connect(Radiobutton_KilogramsL, SIGNAL(clicked()), this, SLOT(inputKilograms()));//connect the signals for the radio buttons to their slots
	QObject::connect(Radiobutton_PoundsL, SIGNAL(clicked()), this, SLOT(inputPounds()));
	QObject::connect(Radiobutton_OuncesL, SIGNAL(clicked()), this, SLOT(inputOunces()));

	return groupBox;
}

QGroupBox* Mass_Converter::createOutputRadioGroup()
{
	QGroupBox* groupBox = new QGroupBox(tr("Output Mass Units"));

	QRadioButton* Radiobutton_KilogramsR = new QRadioButton(tr("Kilograms"));
	Radiobutton_KilogramsR->setObjectName("Radiobutton_KilogramsR");
	
	QRadioButton* Radiobutton_PoundsR = new QRadioButton(tr("Pounds"));
	Radiobutton_PoundsR->setObjectName("Radiobutton_PoundsR");
	
	QRadioButton* Radiobutton_OuncesR = new QRadioButton(tr("Ounces"));
	Radiobutton_KilogramsR->setObjectName("Radiobutton_KilogramsR");
	
	Radiobutton_KilogramsR->setChecked(true); //Set the radio button for fahrenheit to already be checked
	

	QGridLayout* grid = new QGridLayout;
	grid->addWidget(Radiobutton_KilogramsR,0,0);
	grid->addWidget(Radiobutton_PoundsR,1,0);
	grid->addWidget(Radiobutton_OuncesR,2,0);
	
	
	
	groupBox->setLayout(grid);
	
	QObject::connect(Radiobutton_KilogramsR, SIGNAL(clicked()), this, SLOT(outputKilograms()));//connect the signals for the radio buttons to their slots
	QObject::connect(Radiobutton_PoundsR, SIGNAL(clicked()), this, SLOT(outputPounds()));
	QObject::connect(Radiobutton_OuncesR, SIGNAL(clicked()), this, SLOT(outputOunces()));

	return groupBox;
}


QGroupBox* Mass_Converter::createInputGroup() //Used for initializing the display of the input window 
{
	QGroupBox* groupBox = new QGroupBox(tr("Input Mass"));
	
	input_display = new QLineEdit;
	input_display->setObjectName("Input_Mass");
	input_display->setPlaceholderText("0");
	
	//QVBoxLayout* vbox = new QVBoxLayout;
	//vbox->addWidget(input_display);
	
	QGridLayout* grid = new QGridLayout;
	grid->addWidget(input_display);
	
	groupBox->setLayout(grid);
	return groupBox;
}

QGroupBox* Mass_Converter::createOutputReadOnlyGroup() //Used for initializing the display of the output window 
{
	QGroupBox* groupBox = new QGroupBox(tr("Output Mass"));
	
	output_display = new QLineEdit;
	output_display->setObjectName("Output_Mass");
	output_display->setPlaceholderText("0");
	output_display->setReadOnly(true);
	
	QGridLayout* grid = new QGridLayout;
	grid->addWidget(output_display);
	
	groupBox->setLayout(grid);
	return groupBox;
}


void Mass_Converter::inputKilograms()
{
  inKilograms = true;
  inOunces = false;
  inPounds = false;
}

void Mass_Converter::outputKilograms()
{
  outKilograms = true;
  outOunces = false;
  outPounds = false;
}

void Mass_Converter::inputPounds()
{
  inKilograms = false;
  inOunces = false;
  inPounds = true;
}

void Mass_Converter::outputPounds()
{
  outKilograms = false;
  outOunces = false;
  outPounds = true;
}

void Mass_Converter::inputOunces()
{
  inKilograms = false;
  inOunces = true;
  inPounds = false;
}

void Mass_Converter::outputOunces()
{
  outKilograms = false;
  outOunces = true;
  outPounds = false;
}

void Mass_Converter::updateClicked()
{
  double inputMass;
  std::ostringstream out;
  
  inputMass = input_display->text().toDouble();
    
  inputMass = massConversion(inputMass);
  
  out<< std::fixed << std::setprecision(4) << inputMass;
  
  output_display->setText(QString::fromStdString(out.str()));
}

double Mass_Converter::massConversion(double mass)
{
	if(inKilograms == true && outKilograms == true)
	{
		return mass;
	}
	
	else if(inPounds == true && outPounds == true)
	{
		return mass;
	}
	
	else if(inOunces == true && outOunces == true)
	{
		return mass;
	}
	
	else if(inKilograms == true && outPounds == true)
	{
		mass *= 2.205;
		
	}
	
	else if(inKilograms == true && outOunces == true)
	{
		mass *= 35.274;
		
	}
	
	else if(inPounds == true && outKilograms == true)
	{
		mass /= 2.205;
		
	}
	
	else if(inPounds == true && outOunces == true)
	{
		mass *= 16;
		
	}
	
	else if(inOunces == true && outKilograms == true)
	{
		mass /= 35.274;
		
	}
	
	else if(inOunces == true && outPounds == true)
	{
		mass /= 16;
		
	}
	
	return mass;
}



