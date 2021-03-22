////////////////////////////////////////////////////////
// ECE 3574, Project 2 starter code
//
#include "Interpreter.h"
#include <algorithm>
#include <functional>
#include <string>
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
using std::string;
using std::stack;
using std::to_string;
using std::stoi;

Interpreter::Interpreter()
{
    stack<double> ops;
	interp_status = true;
	toogle_trig_unit = false; //if this is false we will perform trig with radians. If true the same will be done in degrees instead
	precision = 0; //default precision should always be 0
}


double Interpreter::topStack()
{
    if(ops.empty() == true)
	{
		throw std::runtime_error("runtime_error: The stack was empty");
	}
	
	else
		return ops.top();
}

void Interpreter::set_trig_unit(bool unit)
{
	toogle_trig_unit = unit;
}

bool Interpreter::get_trig_unit()
{
	return toogle_trig_unit;
}

void Interpreter::set_status(bool status)
{
	interp_status = status;
}

bool Interpreter::get_status()
{
	return interp_status;
}

void Interpreter::set_precision(int precision)
{
	this-> precision = precision;
}

int Interpreter::get_precision()
{
	return precision;
}

bool Interpreter::is_number(string temp) //This function is used to determine if the given input is a valid number or not
{
	
	//cout <<"The value of val is going to be: " << temp << endl;
    try
    {
		//double val = 0;
        std::stod(temp);
    }
    catch(...)
    {
		//cout << temp <<" is not a number" << endl; //if is not a valid number then we should not add it to the stack
        return false;
    }
	
	//cout << "The value of the string is: " << val << std::endl;
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

	//cout <<"The fraction part is: " << s << " and the length of string is: " << s.length() <<endl;
	
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
			//cout <<"The variable t is: " << t << endl;
			
			d = t/pow(10,precision);
			//cout <<"I checked the precision and now it's: " << d << endl;
			val = d;
		}
	}
	
	return val;
}


bool Interpreter::compute(istream & input)
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
		
		/*if(input.eof()) //NOT REALLY NECESSARY BUTT WHAT THEY HECK, WHY NOT. (The while loop condition will automatically check for this)
		{
			//keepreading = true;
			//cout <<"There is stuff in the file" << endl;
			cout << "There is no longer stuff in the file" <<endl;
		}
		
		else if(!input.eof()) //NOT REALLY NECESSARY BUTT WHAT THEY HECK, WHY NOT
		{
			//keepreading = false;
			//cout << "There is no longer stuff in the file" << endl;
			cout <<"There is stuff still in the file" <<endl;
		}*/
		
		//cout <<"This is what the interpreter sees: " << temp << endl;
		
		if(temp.at(0) == '_')
		{
			//cout<<"I'm going to turn the number into an actually negative number" << endl;
			temp.erase(0,1);
			//cout<<"temp is now: " << temp << endl;
			double temp2 = stod(temp) * -1;
			temp = to_string(temp2);
		}
		
		if(is_number(temp) == true)
		{
			match = true;
			val = stod(temp);
			new_val = check_precision(val);
			
			ops.push(new_val);
			//cout <<"I pushed a value into the stack" <<endl;
			//cout <<"The size of the stack is now: " << ops.size() << endl;
			//cout <<"The value at the top of the stack is: " << ops.top() << endl;
		}
		
		
		/*if(ops.size() >= 2 )
		{
			cout<<"There is a minimum of 2 entries in the stack" << endl;
		}*/
		
		//ADD THE REST OF THE COMMANDS INCLUDING THE PRINT COMMAND!!! They should be in if statements so that all the operations will be done 
		//instantaneously
		
		if(temp == "*") //check for multiplication operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			if(ops.size() < 2)
			{
				cout << "There is an invalid number of operands before an operation can be performed" << endl;
				status = false;
				set_status(status);
				return status; //invalid number of operands before operation
			}
			
			rhs = ops.top();
			ops.pop();
			
			//cout <<"The value of rhs is: "<< rhs << endl;
			
			lhs = ops.top();
			ops.pop();
			
			//cout <<"The value of lhs is: "<< lhs << endl;
			
			result = lhs * rhs;
			
			//cout <<"The value of the result is: " << result << endl;
			
			ops.push(check_precision(result));
			
			//cout<<"I pushed the result of multiplication onto the stack" <<endl;
		}
		
		if(temp == "+") //check for addition operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			if(ops.size() < 2)
			{
				cout << "There is an invalid number of operands before an operation can be performed" << endl;
				status = false;
				set_status(status);
				return status; //invalid number of operands before operation
			}
			
			rhs = ops.top();
			ops.pop();
			
			//cout <<"The value of rhs is: "<< rhs << endl;
			
			lhs = ops.top();
			ops.pop();
			
			//cout <<"The value of lhs is: "<< lhs << endl;
			
			result = lhs + rhs;
			
			//cout <<"The value of the result is: " << result << endl;
			
			ops.push(check_precision(result));
			
			//cout<<"I pushed the result of addition onto the stack" <<endl;
		}
		
		if(temp == "-") //check for subtraction operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			if(ops.size() < 2)
			{
				cout << "There is an invalid number of operands before an operation can be performed" << endl;
				status = false;
				set_status(status);
				return status; //invalid number of operands before operation
			}
			
			rhs = ops.top();
			ops.pop();
			
			//cout <<"The value of rhs is: "<< rhs << endl;
			
			lhs = ops.top();
			ops.pop();
			
			//cout <<"The value of lhs is: "<< lhs << endl;
			
			result = lhs - rhs;
			
			//cout <<"The value of the result is: " << result << endl;
			
			ops.push(check_precision(result));
			
			//cout<<"I pushed the result of subtraction onto the stack" <<endl;
		}
		
		if(temp == "/") //check for divison operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			if(ops.size() < 2)
			{
				cout << "There is an invalid number of operands before an operation can be performed" << endl;
				status = false;
				set_status(status);
				return status; //invalid number of operands before operation
			}
			
			rhs = ops.top();
			ops.pop();
			
			//cout <<"The value of rhs is: "<< rhs << endl;
			
			lhs = ops.top();
			ops.pop();
			
			//cout <<"The value of lhs is: "<< lhs << endl;
			
			if(rhs != 0)
			{
				result = lhs / rhs;
				
				//cout <<"The value of the result is: " << result << endl;
				
				ops.push(check_precision(result));
				
				//cout<<"I pushed the result of divison onto the stack" <<endl;
			}
			
			else if(rhs == 0)
			{
				cout <<"You can not divide by 0!" << endl;
				status = false;
				set_status(status); //If the there is an error then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
		}
		
		if(temp == "^") //check for exponentiation operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			if(ops.size() < 2)
			{
				cout << "There is an invalid number of operands before an operation can be performed" << endl;
				status = false;
				set_status(status);
				return status; //invalid number of operands before operation
			}
			
			rhs = ops.top();
			ops.pop();
			
			//cout <<"The value of rhs is: "<< rhs << endl;
			
			lhs = ops.top();
			ops.pop();
			
			//cout <<"The value of lhs is: "<< lhs << endl;
			
			//Check to see if the rhs is a fractional exponent. If so, then we exit failure.
			double intpart, fractpart;
			fractpart = modf(rhs, &intpart);
			
			if(fractpart == 0)
			{
				result = pow(lhs, rhs);
			
				//cout <<"The value of the result is: " << result << endl;
			
				ops.push(check_precision(result));
			
				//cout<<"I pushed the result of exponentiation onto the stack" <<endl;
			}
			
			else
			{
				cout <<"Can not perform exponentiation with fractional exponent" << endl;
				status = false;
				set_status(status); //If the there is an error then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
		}
		
		if(temp == "v") //check for square root operation only if there are at least 2 operands left in the stack
		{
			match = true;
			
			if(ops.empty())
			{
				cout << "There is an invalid number of operands before an operation can be performed" << endl;
				status = false;
				set_status(status);
				return status; //invalid number of operands before operation
			}
			
			rhs = ops.top();
			ops.pop();
			
			//cout <<"The value of rhs is: "<< rhs << endl;
			
			if(rhs >= 0)
			{
				result = sqrt(rhs);
				
				//cout <<"The value of the result is: " << result << endl;
				
				ops.push(check_precision(result));
				
				//cout<<"I pushed the result of exponentiation onto the stack" <<endl;
			}
			
			else
			{
				cout << "Nonreal Answer! Cannot take the square root of a negative number!" << endl;
				status = false;
				set_status(status); //If the there is an error then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
		}
		
		if(temp == "c") //The clearing of the stack should only be done if the stack has contents in it.
		{
			match = true;
			
			//cout <<"The size of the stack is: " << ops.size() <<" before trying to clear it" <<endl;
			//It's ok to clear on a stack that is alreday empty so we really don't need the section of code commented out below.
			/*try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}*/
			
			while(ops.empty() == false)
			{
				ops.pop();
			}
			
			/*if(ops.empty() == true) //Just checking the stack to make sure it is completely empty
			{
				cout <<"The stack is now empty" << endl;
			}*/
		}
		
		if(temp == "P") //If the user wants to pop out the immediate value on top of the stack without it being printed out
		{
			match = true;
			
			//cout <<"The size of the stack is: " << ops.size() <<" and i'm going to remove the value on the top" <<endl;
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			ops.pop();
							
		}
		
		if(temp == "d") //If the user wants to duplicate the immediate value on top of the stack
		{
			match = true;
			
			//cout <<"The size of the stack is: " << ops.size() <<" and i'm going to duplicate the value on the top" <<endl;
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			double temp = ops.top();
			ops.push(temp);
			
		}
		
		if(temp == "r") //If the user wants to reverse the top 2 values on the top of the stack
		{
			match = true;
			
			//cout <<"The size of the stack is: " << ops.size() <<" and i'm going to reverse the 2 values on the top" <<endl;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}

				double top = ops.top();
				ops.pop();
				double bottom = ops.top();
				ops.pop();
				
				ops.push(top);
				ops.push(bottom);
				
				//cout<<"The top value is now: " << ops.top() <<" therefore the top values have been reversed." << endl;			
		}
		
		if(temp == "p") //If the user wants to print out the immediate value on top of the stack with a newline character
		{
			match = true;
			
			//cout <<"The size of the stack is: " << ops.size() <<" and i'm going to display the value on the top" <<endl;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
	
					
			cout << std::fixed << std::setprecision(get_precision()) << ops.top() <<endl;
						
		}
		
		if(temp == "n") //If the user wants to print out the immediate value on top of the stack without a newline character
		{
			match = true;
			
			//cout <<"The size of the stack is: " << ops.size() <<" and i'm going to display the value on the top" <<endl;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
	
	
			cout << std::fixed << std::setprecision(get_precision()) << ops.top();
		}
		
		if(temp == "f") //The printing the whole the stack should only be done if the stack has contents in it.
		{
			match = true;
			
			//cout <<"The size of the stack is: " << ops.size() <<" before trying to print it all out" <<endl;
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			stack<double> ops_temp;
			ops_temp = ops;
			
			while(ops_temp.empty() == false)
			{
				cout << std::fixed << std::setprecision(get_precision()) << ops_temp.top() <<endl;
				ops_temp.pop();
			}
			
			/*if(ops_temp.empty() == true) //Just checking the temporary stack to make sure it is completely empty
			{
				cout <<"The temp stack is now empty" << endl;
			}*/
		}
		
		if(temp == "z") //The user wants to see what the length of the stack currently is
		{
			match = true;
			
			cout << ops.size() << endl;
		}
		
		if(temp == "K") //The user wants to see the current precision setting for the program
		{
			match = true;
			
			cout << get_precision() << endl;
		}
		
		if(temp == "k")//The user wants the top value of to be stack to be the new set precision
		{
			match = true;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			double x = ops.top();
			ops.pop();
			
			if(x < 0)
			{
				cout<<"You can not set the precision to be a negative number!" << endl;
				status = false;
				set_status(status); //You can not set precision to be a negative number
				return status;
			}
			
			x = trunc(x);
			
			set_precision(x);
			
			//cout <<"The precision has now been set to " << get_precision() << endl;
			
		}
		
		if(temp == "Z")//The user wants to count the number of digits in the value on the top of the stack
		{
			match = true;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
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
			
			//cout <<"The top number's integer part is " << s << endl;
			//cout <<"The number of digits in the top value's integer part is " << s.length() <<" and was pushed onto the stack." << endl;
			
			ops.push(s.length()+ get_precision());
			
		}
		
		if(temp == "e")//The user wants to insert euler's number which is just e=2.71828
		{
			match = true;
			
			ops.push(check_precision(M_E));
		}
		
		if(temp == "i")//The user wants to insert pi which is just pi = 3.1415926...
		{
			match = true;
			ops.push(check_precision(M_PI));
		}
		
		if(temp == "g") //The user wants to calculate the top element from the stack's logarithm to the base 10 (log)
		{
			match = true;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			double temp = ops.top();
			
			ops.pop();
			
			ops.push(log10(temp));
		}

		if(temp == "l")//The user wants tp calculate the top element the stack's logarithm to the base e (ln)
		{
			match = true;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			double temp = ops.top();
			
			ops.pop();
			
			ops.push(log(temp));
		}
		
		if(temp == "s")//The user wants to calculate the sin of the top element from the stack
		{
			match = true;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			double temp = ops.top();
			
			ops.pop();
			
			if(get_trig_unit() == false)//the trig unit is set to radians calculation
			{
				temp = sin(temp);
				
				if(temp > -0.0000001 && temp < 0)
				{
					temp = 0;
				}
				
				ops.push(temp);
			}
			
			else //the trig unit is set to degrees calculation
			{
				double ToRad = temp * (M_PI/180);
				ToRad = sin(ToRad);
				
				if(ToRad > -0.000001 && ToRad < 0)
				{
					
					ToRad = 0;
				}
				
				ops.push(ToRad);
			}
		}
		
		if(temp == "o") //The user wants to calculate the cos of the top element from the stack
		{
			match = true;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			double temp = ops.top();
			
			
			
			ops.pop();
			
			if(get_trig_unit() == false)//the trig unit is set to radians calculation
			{
				temp = cos(temp);
				
				if(temp > -0.0000001 && temp < 0)
				{
					temp = 0;
				}
				
				ops.push(temp);
			}
			
			else //the trig unit is set to degrees calculation
			{
				double ToRad = temp * (M_PI/180);
				ToRad = cos(ToRad);
				
				if(ToRad > -0.000001 && ToRad < 0)
				{
					
					ToRad = 0;
				}
				
				ops.push(ToRad);
			}
		}
		
		if(temp == "a") //The user wants to calculate the tan of the top element from the stack
		{
			match = true;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			double temp = ops.top();
			
			
			ops.pop();
			
			if(get_trig_unit() == false)//the trig unit is set to radians calculation
			{
				temp = tan(temp);
				
				if(temp > -0.0000001 && temp < 0)
				{
					temp = 0;
				}
				
				ops.push(temp);
			}
			
			else //the trig unit is set to degrees calculation
			{
				double ToRad = temp * (M_PI/180);
				
				ToRad = tan(ToRad);
				
				if(ToRad > -0.000001 && ToRad < 0)
				{
					
					ToRad = 0;
				}
				
				ops.push(ToRad);
			}
		}
		
		if(temp == "X")//The user wants count the number of digits in the fractional part of the top value in the stack
		{
			match = true;
			
			try
			{
				topStack();
			}
	
			catch(std::runtime_error e)// Oh no I was not valid and an exception was thrown
			{
				cout << e.what() << endl; //display error and tell me what the problem was
				status = false;
				set_status(status); //If the stack is empty then we return the status as false which will mean EXIT_FAILURE
				return status;
			}
			
			
			//string s;
			//double x = ops.top();
			
			ops.pop();
			
			ops.push(get_precision());
			//match = false;
			
			//////////////////////////////////////////////////////////////NOT NEEDED///////////////////////////////////////////////////////////////
			//cout <<"The number is this "<< x << endl;
			/*if(x < 0)// in case the number is negative
			{
				x = x * -1;
			}
			
			double intpart, fractpart;
			fractpart = modf(x, &intpart);
			s = to_string(fractpart);
			//cout << "The string version is this " << s <<endl;
			
			if(fractpart != 0)
			{	
				s.erase ( s.find_last_not_of('0') + 1, std::string::npos ); //Search through the string and get rid of all extra zeros from being a double
				s.erase ( s.find_last_not_of('.') + 1, std::string::npos ); //Get rid of the decimal point
				
				ops.push(s.length() - 2); //Minus 2 because the 0 and decimal don't count as being part of the fractional part.
			}
			
			//cout <<"The top number's fractional part is " << s << endl;
			//cout <<"The number of digits in the top value's fractional part is " << s.length()- 2 <<" and was pushed onto the stack." << endl;
			
			else //The fractional part is just 0 due to the number being a whole number 
			{
				ops.push(0);
			}*/
			
			///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
		
		else if (match == false)
		{
			//cout << "Invalid command/ operand detected: " << temp << endl;
			//cout << "Closing program..." << endl;
			
			status = false;
			set_status(status); //If there is an invalid operand or command, we return the status as false which will mean EXIT_FAILURE
			return status;
		}
		
		match = false;
	}
	
	if(!(input >> temp))
	{
		//cout <<"There were no longer entries in the file" << endl;
		return true;
	}
	
    return true; //might not need
}


