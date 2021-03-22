////////////////////////////////////////////////////////
// ECE 3574, Project 2 starter code 
//

#include <cstdlib>
#include <string>
#include <stack>

using std::string;

class Interpreter {
private:
    std::stack<double> ops;
	bool interp_status;
	int precision;
	bool toogle_trig_unit;

public:
    // Default constructor that initializes an empty processing stack.
    Interpreter();

    // Perform computations based on an input stream.
    //  Attempt to process the stream by updating the stack
    //  and by sending appropriate output to std::out.
    // Return true on success, false on failure.
    bool compute(std::istream & input);

    // Return the current value that is at the top of the stack.
    //  The stack is not modified.
    //  If stack is empty, throw an exception of type std::runtime_error.
    double topStack();
	
	//These methods are to be used for the purpose of determining whether
	//something invalid has happened in the interpreter.
	void set_status(bool status);
	bool get_status();
	
	//Used for checking if the string is a valid double
	bool is_number(string temp);
	
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
};
