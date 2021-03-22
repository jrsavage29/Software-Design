// ECE 3574, Project 4, Fall 2019
// File name: run_vtmath.cpp
// Client code to demonstrate usage of VTmath  
#include <iostream> 
#include "VTmath.h"

int main()
{
	VTmath m, n, r, t;

    if (m.size() != 1)
	{
		std::cerr << "ERROR: invalid size of VTmath integer after declaration!\n";
	}
	
	//m = -12345;
	m = "1000000000000";
	n = 98;
	t = 100;
	
	std::cout << "m = " << m << std::endl;
	
	n = m;
	
	VTmath p = n;
	
	n = 67;
	
	std::cout << "n = " << n << std::endl;
	std::cout << "p = " << p << std::endl;
	std::cout << "t = " << t << std::endl;
	
	if(m == p)
	{
		std::cout << "m is equal to p" <<std::endl;
	}
	
	else
	{
		std::cout << "m is not equal to p at ALL!" << std::endl;
	}
	
	if(n == "67")
	{
		std::cout << "n, which is " << n <<" is equal to 67" <<std::endl;
	}
	
	else
	{
		std::cout << "n, which is " << n <<", is NOT equal to 67" <<std::endl;
	}
	
	if(m == -12345)
	{
		std::cout << "m is equal to -12345" <<std::endl;
	}
	
	else
	{
		std::cout << "m is not equal to -12345 at ALL!" << std::endl;
	}
	
	r = n + t;
    std::cout << "n + t = " << r << std::endl;

    r = m + n;
    std::cout << "m + n = " << r << std::endl;
    
	r = n - t;
    std::cout << "n - t = " << r << std::endl;
	std::cout << "After subtraction, r is equal to: " << r <<std::endl;
	
	
	if(r == -33)
	{
		std::cout << "r is equal to -33" <<std::endl;
	}
	
	else
	{
		std::cout << "r is NOT equal to -33" <<std::endl;
	}
	
	r = "33";
	std::cout << "r is equal to: " << r <<std::endl;
	
	if(r == 33)
	{
		std::cout << "After turning into positive string, r is equal to 33" <<std::endl;
	}
	
	else
	{
		std::cout << "After turning into positive string, r is NOT equal to 33" <<std::endl;
	}
	
	m = -48; 
	n = -9;
	
	r = n - m;
	std::cout << "n - m = " << r << std::endl;
	
	std::cout << "After adding 2 negative numbers, r is NOW equal to " << r << std::endl;
	
	if(r == -13)
	{
		std::cout << "r IS INDEED equal to -13" << std::endl;
	}
	
	else
	{
		std::cout << "r is NOT equal to -13 AT ALL" << std::endl;
	}
	
	r = m - n;
    std::cout << "m - n = " << r << std::endl;

	m = "2"; 
	n = "-6";
	
	r = m * n;
    std::cout << "m * n = " << r << std::endl;
	
	m = "46591";
	n = "643";
	
	r = m / n;
    std::cout << "m / n = " << r << std::endl;
	
	m = -2;
	n = 11;
	
	r = m ^ n;
    std::cout << "m ^ n = " << r << std::endl;
		
	
	std::cout << "Finished!" << std::endl; 
    return EXIT_SUCCESS;

}