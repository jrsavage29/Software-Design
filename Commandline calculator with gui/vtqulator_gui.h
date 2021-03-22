////////////////////////////////////////////////////////////////////////////////////
// ECE 3574, Project 3, Jamahl Savage
//
// File name:	vtqulator_gui.h
// Description:	The header file for the vtqulator.
//
// Date:	11/02/2019
///////////////////////////////////////////////////////////////////////////////////

#ifndef VTQULATOR_GUI_H
#define VTQULATOR_GUI_H

#include <QtWidgets>
#include <QEvent>
#include <QMetaEnum>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <stack>

#include "output_window.h"

using std::istream;
using std::ifstream;
using std::ofstream;

class VtqulatorGui : public QWidget
{
	Q_OBJECT

public:
	VtqulatorGui(QWidget* parent = nullptr);
	
public slots:
//These are the various tasks that can be performed by the vtqulator depending on the button pressed
//and signal recieved

	void digitClicked(); //This is for simple digits pressed
	void unaryOperatorClicked(); //This is for when unary operations are pressed
	void e_or_pi_Clicked(); //This is a special since it's only for when e or pi is pressed
	void specialUnaryOperatorClicked(); //For ln, log , and all the trig functions
	void additiveOperatorClicked(); //For addition and subtraction operations
	void multiplicativeOperatorClicked(); //For multiplaction and division operations
	void returnClicked(); //For when the enter key is pressed
	void pointClicked(); //For when the decimal button is pressed
	void changeSignClicked(); //For adding a negative sign in front of a number
	void backspaceClicked(); //For backspacing input into the vtqulator
	void space(); //Fir creating spaces between input 
	void commandClicked(); //For when the user inputs a command into the vtqulator
	void degreeMode(); //For when the radio buttons for the trig units are toggled
	void radianMode();

private:
	std::stack<int> epiloc; //A stack used for keeping track of the locations of anytime e or pi is pressed instead of typed out
	QString computeStr; //A QString that contains the everything that is inputted on a line in the vtqulator
	QString eStr; //A QString that holds the value e (including with the current precision)
	QString piStr; //A QString that holds the value pi (including with the current precision)
	int inputCount; //Used to keep track of the current position of the cursor(next be inputted)
	ofstream calc; //Used for storing the input to calculated
	ifstream input; //Allows the interpreter to read from the calc file to do the calculations
	ofstream output; //Contains the outputted results of the interpreter
	ifstream result; //Allows the display to read in the results of from the interpreter
	
	QLabel *Label_precision; //A label for displaying the precision on the vtqulator. Updated when the precision is changed
	OutputWindow Output_window; //An instance of the OuputWindow class. This allows control over the display
	QGroupBox* createTrigRadioGroup(); //Creates the raido buttons for the trig unit buttons
	QGroupBox* createPrecisionGroup(); //Initializes te precision label's display on the vtqulator
	QGroupBox* createPushButtonGroup(); //Initializes the pushbuttons for display and sets up their connections
};

#endif