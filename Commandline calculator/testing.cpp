#include <iostream>
#include <string>
#include <cstring>

using std::string;

int main()
{
	double val;
	
    try
    {
        val = std::stod("a");
    }
    catch(...)
    {
		std::cout <<"That did not work" << std::endl;
        return false;
    }
	
	std::cout << "The value of a is: " << val << std::endl;
    return true;
	
}