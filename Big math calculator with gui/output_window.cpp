////////////////////////////////////////////////////////////////////////////////////
// ECE 3574, Project 3, Jamahl Savage
//
// File name:	output_window.cpp
// Description:	The cpp file full of methods used for creating and controlling what's displayed on the gui's display box
//
// Date:	11/02/2019
///////////////////////////////////////////////////////////////////////////////////

#include "output_window.h"

OutputWindow::OutputWindow(QWidget* parent)
	: QWidget(parent)
{
	prec = interp.get_precision(); //set prec to be initialized to the same value as it is initialized in the interpreter
}

QGroupBox* OutputWindow::createReadOnlyGroup() //Used for initializing the display of the output window int vtqulator
{
	QGroupBox* groupBox = new QGroupBox(tr(""));
	
	display = new QPlainTextEdit;
	display->setObjectName("Output_window");
	display->setReadOnly(true);
	
	
	QVBoxLayout* vbox = new QVBoxLayout;
	vbox->addWidget(display);
	
	groupBox->setLayout(vbox);
	return groupBox;
}


void OutputWindow::editDisplayString(QString str)
{
		
	//display->setPlainText(display->toPlainText() + str);
	//display->insertPlainText(str);
	display->textCursor().insertText(str); //Append new text to the text currently displayed
	
}

QString OutputWindow::get_text()
{
	return display->toPlainText(); //gives back the text
}


void OutputWindow::computeDisplay(std::istream & input, std::ofstream & output) //Used for accessing the interpreter to do calculations
{
	interp.compute(input, output);
	
}

double OutputWindow::checkPrecision(double val)//A helpful function exactly like the one in the interpreter class that does precision calculation
{
	//checking the precision
	double intpart, fractpart, d;
	int p = 0;
	fractpart = modf(val, &intpart);

	//convert to string to get length of fractional part 
	string s = to_string(fractpart);

	//erase trailling zeros as well as the decimal point to get length of fractional part of string
	s.erase ( s.find_last_not_of('0') + 1, std::string::npos );
	s.erase ( s.find_last_not_of('.') + 1, std::string::npos );

	
	if(fractpart < 0)
	{
		p = get_prec() + 3;
	}
	
	if(fractpart > 0)
	{
		p = get_prec() + 2;
	}
	
	int l = 0;
	l = s.length();
	
	if( l >= p)
	{
		if(get_prec() == 0)
		{
			val = intpart;
		}
		
		else
		{
			int t = (trunc(val * pow(10, get_prec())));
			
			d = t/pow(10, get_prec());
			val = d;
		}
	}
	
	return val;
}

void OutputWindow::set_prec(int prec) //Used for setting the precision to be used in calculations 
{
	interp.set_precision(prec);
}

int OutputWindow::get_prec() //retrieves what the current precision is.
{
	return interp.get_precision(); //Retrieving from the interpreter class.
}

void OutputWindow::toggle_trig_unit(bool unit)//sets the trig calculations' unit type (degrees or radians)
{
	interp.set_trig_unit(unit);
}

void OutputWindow::backspace() //Used for backspacing in the display
{
	display->textCursor().deletePreviousChar();
}

void OutputWindow::reset_stack()
{
	interp.clear_stack();
}

bool OutputWindow::Is_VTmath_Active()//Used to check the VTmath status variable in the interpreter class
{
	return interp.get_VTmath_status();
}

void OutputWindow::set_VTmath_mode(bool stat) //Used to set the status of the VTmath status variable in the interpreter class.
{
	interp.set_VTmath_status(stat);
}