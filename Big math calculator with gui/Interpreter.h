////////////////////////////////////////////////////////////////////////////////////
// ECE 3574, Project 3, Jamahl Savage
//
// File name:	Interpreter.h
// Description:	The header file for the interpreter.cpp. It does all the computations for the post fix expressions
//
// Date:	11/02/2019
///////////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <string>
#include <stack>
#include <QtWidgets>
#include <QTextCursor>
#include "VTmath.h"

using std::string;

class Interpreter {
private:
    std::stack<double> ops; //For normal mode calculations
	std::stack<string> ops_s; //For VTmath mode calculations
	bool interp_status;
	int precision;
	bool toogle_trig_unit;
	bool VTmath_status;

public:
    // Default constructor that initializes an empty processing stack.
    Interpreter();

    // Perform computations based on an input stream.
    //  Attempt to process the stream by updating the stack
    //  and by sending appropriate output to std::out.
    // Return true on success, false on failure.
    bool compute(std::istream & input, std::ofstream & output);

    // Return the current value that is at the top of the stack.
    //  The stack is not modified.
    //  If stack is empty, throw an exception of type std::runtime_error.
    double topStack();
	
	//Used for checking if the string is a valid double
	bool is_number(string temp);
	
	//Used for checking if the string is a valid string operand for computations in VTmath mode
	bool is_NOT_op(string temp);
	
	//used to check if a number entered meets the current precision
	//setting. If not then we will set the incoming number
	//so that it meets the current precision
	double check_precision(double val);
	
	//These methods are for setting and getting the private variable called precision
	void set_precision(int precision);
	int get_precision();
	
	//These methods are for toogling the unit we will perform trig in for sin and cos 
	//(either deg or rad)
	void set_trig_unit(bool unit);
	bool get_trig_unit();
	
	void set_VTmath_status(bool stat); //Used to toggle if VTmath mode is active or not
	bool get_VTmath_status(); // Checks the if VTmath mode is active or not
	
	void clear_stack(); //clears the stack
	
};
