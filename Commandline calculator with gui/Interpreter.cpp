////////////////////////////////////////////////////////
// ECE 3574, Project 2 starter code
//
#include "Interpreter.h"
#include <algorithm>
#include <functional>
#include <string>
////////////////////////////////////////////////////////////////////////////////////
// ECE 3574, Project 3, Jamahl Savage
//
// File name:	Interpreter.cpp
// Description:	The .cpp file of the Interpreter. It computes the the user input from a file it recieves and outputs the results in another file
//
// Date:	11/02/2019
///////////////////////////////////////////////////////////////////////////////////

#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <math.h>

using std::cout;
using std::endl;
using std::istream;
using std::ofstream;
using std::string;
using std::stack;
using std::to_string;
using std::stoi;

Interpreter::Interpreter()
{
    stack<double> ops; //the stack of operands
	interp_status = true; //status of the interpreter. As long as its true, it's recieving valid input and valid operations are being performed
	toogle_trig_unit = true; //if this is true we will perform trig with radians. If false the same will be done in degrees instead
	precision = 0; //default precision should always be 0
	
}


double Interpreter::topStack()
{
    /*if(ops.empty() == true)
	{
		throw std::runtime_error("runtime_error: The stack was empty");
	}
	
	else*/
		return ops.top();
}

void Interpreter::set_trig_unit(bool unit) //set the trig units for calculations in the interpreter
{
	//cout<< "Trig unit mode has been toggled!" <<endl;
	toogle_trig_unit = unit;
}

bool Interpreter::get_trig_unit() //get the current trig units to be used in the trig calculations
{
	
	return toogle_trig_unit;
}
	
void Interpreter::set_status(bool status)
{
	interp_status = status;
}

/*bool Interpreter::get_status() //not needed for this project 3
{
	return interp_status;
}*/

void Interpreter::set_precision(int precision) //sets the precision for the interpreter and other dependencies using the interpreter's precision
{
	this-> precision = precision;
}

int Interpreter::get_precision()//gets the interpreter's current precision
{
	return precision;
}

bool Interpreter::is_number(string temp) //This function is used to determine if the given input is a valid number or not
{
	
	
    try
    {
        std::stod(temp);
    }
    catch(...)
    {
		//cout << temp <<" is not a number" << endl; //if is not a valid number then we should not add it to the stack
        return false;
    }
	
	
    return true;
}

double Interpreter::check_precision(double val)
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
		p = precision + 3;
	}
	
	if(fractpart > 0)
	{
		p = precision + 2;
	}
	
	int l = 0;
	l = s.length();
	
	if( l >= p)
	{
		if(precision == 0)
		{
			val = intpart;
		}
		
		else
		{
			int t = (trunc(val * pow(10,precision)));
			
			
			d = t/pow(10,precision);
			
			val = d;
		}
	}
	
	return val;
}


bool Interpreter::compute(istream & input, ofstream & output)
{
	
	string temp;
	double val = 0.0;
	double new_val = 0.0;
	bool match = false;
	bool status = true;
	
	double rhs = 0;
	double lhs = 0;
	double result = 0;
	
	
	//make sure there is a minimum of 2 operands before using operators
	
		
	while(input >> temp)
	{
				
		if(temp.at(0) == '_')//If we recieve a negative number (has an underscore in front) as input we should handle it correctly before doing anything further
		{
			
			temp.erase(0,1);
			
			double temp2 = stod(temp) * -1;
			temp = to_string(temp2);
		}
		
		if(is_number(temp) == true)
		{
			match = true;
			val = stod(temp);
			new_val = check_precision(val);
			
			ops.push(new_val);
		}
		
		
		//ADD THE REST OF THE COMMANDS INCLUDING THE PRINT COMMAND!!! They should be in if statements so that all the operations will be done 
		//instantaneously
		
		if(temp == "*") //check for multiplication operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			
			rhs = ops.top();
			ops.pop();
			
			
			lhs = ops.top();
			ops.pop();
			
			
			result = lhs * rhs;
			
			
			ops.push(check_precision(result));
			
		}
		
		if(temp == "+") //check for addition operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			rhs = ops.top();
			ops.pop();
			
			
			lhs = ops.top();
			ops.pop();
			
			
			result = lhs + rhs;
			
			
			ops.push(check_precision(result));
			
		}
		
		if(temp == "-") //check for subtraction operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			
			rhs = ops.top();
			ops.pop();
			
			
			lhs = ops.top();
			ops.pop();
			
			
			result = lhs - rhs;
			
			
			ops.push(check_precision(result));
			
		}
		
		if(temp == "/") //check for divison operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			
			rhs = ops.top();
			ops.pop();
			
			
			lhs = ops.top();
			ops.pop();
			
			
			if(rhs != 0)
			{
				result = lhs / rhs;
				
				
				ops.push(check_precision(result));
				
				
			}
			
		}
		
		if(temp == "^") //check for exponentiation operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			
			rhs = ops.top();
			ops.pop();
			
			
			lhs = ops.top();
			ops.pop();
			
			
			//Check to see if the rhs is a fractional exponent. If so, then we exit failure.
			double intpart, fractpart;
			fractpart = modf(rhs, &intpart);
			
			if(fractpart == 0)
			{
				result = pow(lhs, rhs);
			
			
				ops.push(check_precision(result));
			
				
			}
			
		}
		
		if(temp == "v") //check for square root operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			
			rhs = ops.top();
			ops.pop();
			
			
			if(rhs >= 0)
			{
				result = sqrt(rhs);
				
				
				ops.push(check_precision(result));
				
			}
			
		}
		
		if(temp == "c") //The clearing of the stack should only be done if the stack has contents in it.
		{
			match = true;
			
			while(ops.empty() == false)
			{
				ops.pop();
			}
			
		}
		
		if(temp == "P") //If the user wants to pop out the immediate value on top of the stack without it being printed out
		{
			match = true;
			
			ops.pop();
							
		}
		
		if(temp == "d") //If the user wants to duplicate the immediate value on top of the stack
		{
			match = true;
			
			double temp = ops.top();
			ops.push(temp);
			
		}
		
		if(temp == "r") //If the user wants to reverse the top 2 values on the top of the stack
		{
			match = true;

				double top = ops.top();
				ops.pop();
				double bottom = ops.top();
				ops.pop();
				
				ops.push(top);
				ops.push(bottom);
						
		}
		
		if(temp == "p") //If the user wants to print out the immediate value on top of the stack with a newline character
		{
			match = true;
			
			if(get_trig_unit() == false)
			{
				float temp = ops.top() * pow(10,get_precision());
				//cout <<"The number is Before trunc: "<< temp <<endl;
				temp = trunc(temp) / pow(10,get_precision());
				//cout <<"The number is After trunc: "<< temp <<endl;
				//cout << "The original number was: " << ops.top() <<endl;
				
				if(temp == -0)
				{
					temp = 0;
				}
				
				output << std::fixed << std::setprecision(get_precision()) << temp <<"\r";
			}
			
			else if(get_trig_unit() == true)//radians calculation for display and precision
			{
				double temp = ops.top() * pow(10,get_precision());
				//cout <<"The number is Before trunc: "<< temp <<endl;
				temp = trunc(temp) / pow(10,get_precision());
				//cout <<"The number is After trunc: "<< temp <<endl;
				//cout << "The original number was: " << ops.top() <<endl;
				
				if(temp == -0)
				{
					temp = 0;
				}
				
				output << std::fixed << std::setprecision(get_precision()) << temp <<"\r";
			}
			
						
		}
		
		if(temp == "n") //If the user wants to print out the immediate value on top of the stack without a newline character
		{
			match = true;
			
			
			if(get_trig_unit() == false)
			{
				float temp = ops.top() * pow(10,get_precision());
				//cout <<"The number is Before trunc: "<< temp <<endl;
				temp = trunc(temp) / pow(10,get_precision());
				//cout <<"The number is After trunc: "<< temp <<endl;
				//cout << "The original number was: " << ops.top() <<endl;
				
				if(temp == -0)
				{
					temp = 0;
				}
				
				output << std::fixed << std::setprecision(get_precision()) << temp;
			}
			
			else if(get_trig_unit() == true)
			{
				double temp = ops.top() * pow(10,get_precision());
				//cout <<"The number is Before trunc: "<< temp <<endl;
				temp = trunc(temp) / pow(10,get_precision());
				//cout <<"The number is After trunc: "<< temp <<endl;
				//cout << "The original number was: " << ops.top() <<endl;
				
				if(temp == -0)
				{
					temp = 0;
				}
				
				output << std::fixed << std::setprecision(get_precision()) << temp;
			}
			
			
		}
		
		if(temp == "f") //The printing the whole the stack should only be done if the stack has contents in it.
		{
			match = true;
			
			stack<double> ops_temp;
			ops_temp = ops;
			
					
			while(ops_temp.empty() == false)
			{
				if(get_trig_unit() == false)
				{
					float temp = ops_temp.top() * pow(10,get_precision());
					//cout <<"The number is Before trunc: "<< temp <<endl;
					temp = trunc(temp) / pow(10,get_precision());
					//cout <<"The number is After trunc: "<< temp <<endl;
					//cout << "The original number was: " << ops.top() <<endl;
					
					if(temp == -0)
					{
						temp = 0;
					}
					
					output << std::fixed << std::setprecision(get_precision()) << temp <<"\r";
					ops_temp.pop();
				}
			
				else if(get_trig_unit() == true)
				{
					double temp = ops_temp.top() * pow(10,get_precision());
					//cout <<"The number is Before trunc: "<< temp <<endl;
					temp = trunc(temp) / pow(10,get_precision());
					//cout <<"The number is After trunc: "<< temp <<endl;
					//cout << "The original number was: " << ops.top() <<endl;
					
					if(temp == -0)
					{
						temp = 0;
					}
					
					output << std::fixed << std::setprecision(get_precision()) << temp <<"\r";
					ops_temp.pop();
				
				}
			
				
			}
			
		}
		
		if(temp == "z") //The user wants to see what the length of the stack currently is
		{
			match = true;
			
			//adjust for current precision
			double temp = ops.size() * pow(10,get_precision());
			//cout <<"The number is Before trunc: "<< temp <<endl;
			temp = trunc(temp) / pow(10,get_precision());
			//cout <<"The number is After trunc: "<< temp <<endl;
			//cout << "The original number was: " << ops.top() <<endl;
			
			if(temp == -0)
			{
				temp = 0;
			}
			
			output << std::fixed << std::setprecision(get_precision()) << temp << "\r";
		}
		
		if(temp == "K") //The user wants to see the current precision setting for the program
		{
			match = true;
			
			output << get_precision() << "\r";
		}
		
		if(temp == "k")//The user wants the top value of to be stack to be the new set precision
		{
			match = true;
			
			
			double x = ops.top();
			ops.pop();
			
			
			x = trunc(x);
			
			set_precision(x);
			
			
		}
		
		if(temp == "Z")//The user wants to count the number of digits in the value on the top of the stack
		{
			match = true;
			
			
			string s;
			double x = ops.top();
			ops.pop();
			
			if(x < 0)//in case the number is negative
			{
				x = x * -1;
			}
			
			double intpart = 0.0;
			modf(x, &intpart);
			intpart = trunc(intpart);
			s = to_string(intpart);
			
			s.erase ( s.find_last_not_of('0') + 1, std::string::npos ); //Search through the string and get rid of all extra zeros from being a double
			s.erase ( s.find_last_not_of('.') + 1, std::string::npos ); //Get rid of the decimal point
			
			
			ops.push(s.length()+ get_precision());
			
		}
		
			
		if(temp == "g") //The user wants to calculate the top element from the stack's logarithm to the base 10 (log)
		{
			match = true;
			
			
			double temp = ops.top();
			
			ops.pop();
			
			ops.push(log10(temp));
		}

		if(temp == "l")//The user wants tp calculate the top element the stack's logarithm to the base e (ln)
		{
			match = true;
			
			
			double temp = ops.top();
			
			ops.pop();
			
			ops.push(log(temp));
		}
		
		if(temp == "s")//The user wants to calculate the sin of the top element from the stack
		{
			match = true;
			
			
			double temp = ops.top();
			
			ops.pop();
			
			if(get_trig_unit() == true)//the trig unit is set to radians calculation
			{
				
				temp = sin(temp);
				
				if(temp == -0.0)
				{
					temp = 0;
				}
				//cout <<"About to push the radians calculation for sin" << endl;
				//cout <<"sin in radian is: " << temp << endl;
				ops.push(temp);
			}
			
			else //the trig unit is set to degrees calculation
			{
				double ToRad = temp * (M_PI/180);
				ToRad = sin(ToRad);
				
				if(ToRad == -0.0)
				{
					
					ToRad = 0;
				}
				
				//cout <<"About to push the degrees calculation for sin" << endl;
				//cout <<"sin in degrees is: " << ToRad << endl;
				ops.push(ToRad);
			}
		}
		
		if(temp == "o") //The user wants to calculate the cos of the top element from the stack
		{
			match = true;
			
			
			double temp = ops.top();
			
			
			
			ops.pop();
			
			if(get_trig_unit() == true)//the trig unit is set to radians calculation
			{
				temp = cos(temp);
				
				if(temp == -0.0)
				{
					temp = 0;
				}
				
				//cout <<"About to push the radians calculation for cos" << endl;
				//cout <<"cosine in radian is: " << temp << endl;
				ops.push(temp);
			}
			
			else //the trig unit is set to degrees calculation
			{
				double ToRad = temp * (M_PI/180);
				ToRad = cos(ToRad);
				
				if(ToRad == -0.0)
				{
					
					ToRad = 0;
				}
				
				//cout <<"About to push the degrees calculation for cos" << endl;
				//cout <<"cos in degrees is: " << ToRad << endl;
				ops.push(ToRad);
			}
		}
		
		if(temp == "a") //The user wants to calculate the tan of the top element from the stack
		{
			match = true;
			
			
			double temp = ops.top();
			
			
			ops.pop();
			
			if(get_trig_unit() == true)//the trig unit is set to radians calculation
			{
				temp = tan(temp);
				
				if(temp == -0.0)
				{
					temp = 0;
				}
				
				//cout <<"About to push the radians calculation for tan" << endl;
				//cout <<"tan in radian is: " << temp << endl;
				ops.push(temp);
			}
			
			else //the trig unit is set to degrees calculation
			{
				double ToRad = temp * (M_PI/180);
				
				ToRad = tan(ToRad);
				
				if(ToRad  == -0.0)
				{
					
					ToRad = 0;
				}
				
				//cout <<"About to push the degrees calculation for tan" << endl;
				//cout <<"tan in degrees is: " << ToRad << endl;
				ops.push(ToRad);
			}
		}
		
		if(temp == "X")//The user wants count the number of digits in the fractional part of the top value in the stack
		{
			match = true;
			
			
			ops.pop();
			
			ops.push(get_precision());
			
			}
		
		else if (match == false)
		{
			
			//output << "Invalid command/operand detected: " << temp << "\r";
			
			status = false;
			set_status(status); //If there is an invalid operand or command, we return the status as false which will mean EXIT_FAILURE
			return status;
		}
		
		match = false;
	}
	
	if(!(input >> temp))
	{
		
		return true;
	}
	
    return true; //might not need
}


