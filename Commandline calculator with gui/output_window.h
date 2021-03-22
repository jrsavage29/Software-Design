////////////////////////////////////////////////////////////////////////////////////
// ECE 3574, Project 3, Jamahl Savage
//
// File name:	output_window.h
// Description:	The header file for the creating and controlling what's displayed on the gui's display box
//
// Date:	11/02/2019
///////////////////////////////////////////////////////////////////////////////////

#ifndef OUTPUT_WINDOW_H
#define OUTPUT_WINDOW_H

#include <QtWidgets>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <QTextCursor>


#include "Interpreter.h"

using std::string;
using std::to_string;
using std::istream;
using std::ifstream;

class OutputWindow: public QWidget
{
	Q_OBJECT

public:
	OutputWindow(QWidget* parent = nullptr);	
	 QGroupBox* createReadOnlyGroup(); //Creates a read only display
	 void editDisplayString(QString str); //Appends input to the current input on the display
	 void toggle_trig_unit(bool unit); //Used for toggling the trig unit mode (Degree or radians)
	 
	 QString get_text(); //Grabs the text currently on the line 
	 void computeDisplay(std::istream & input, std::ofstream & output); //Used to access the interpreter class
	 double checkPrecision(double val); // A useful function for checking thre precision of any numbers given to it.
	 void set_prec(int prec); //sets the precision
	 int get_prec(); // returns the current precision of the code.
	 void backspace(); //Used for backspacing one previous charaacter
	 QPlainTextEdit *display;

private:
	
	Interpreter interp; //Gives the OutputWindow class the ability to use the interpreter to calculate the 
						//input on the display
	int prec; //Used for holding the precision
};

#endif