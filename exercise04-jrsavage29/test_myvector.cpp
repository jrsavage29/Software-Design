// ECE 3574, fall 2019
// Exercise 04 starter code
// File name: test_myvector.cpp
// Client code to test MyVector  

#include <iostream>
#include <cstdlib>
#include "MyVector.h"

int main()
{
    MyVector<int> vint;
    MyVector<double> vdouble;
	MyVector<std::string> vstring;
	
    std::cout << "Testing an empty vector of integers" << std::endl;
    if (vint.size() != 0)
	{
		std::cout << "ERROR: size of vector is not 0 after initialization!\n";
	}
	if (!vint.empty())
	{
		std::cout << "ERROR: vector is not empty after initialization!\n";
	}
	
	std::cout << "Testing an empty vector of doubles" << std::endl;
    if (vdouble.size() != 0)
	{
		std::cout << "ERROR: size of vector is not 0 after initialization\n";
	}
	if (!vdouble.empty())
	{
		std::cout << "ERROR: vector is not empty after initialization!\n";
	}
	
	std::cout << "Testing push_back with vector of integers\n";
    vint.push_back(100);
	vint.push_back(200);
    if (vint.size() != 2)
	{
		std::cout << "Size of vector after push_back is "<< vint.size();
		std::cout << "ERROR: invalid size of vector after push_back!\n";
	}

	// TO DO: ADD EXTENSIVE TESTS OF MyVector HERE
		
	std::cout << "Testing copy constructor, equals operator, and at function\n";	
	MyVector<int> tint;	
	
	tint = vint;
	if(tint.size() != 2)
	{
		std::cout << "ERROR: Second instance of MyVector should have a size of 2!\n";
	}
	
	if(tint.at(0) != 100)
	{
		std::cout << "ERROR: Second instance of MyVector should have the same value as vint.at(0)!\n";
	}
	
	if(tint.at(1) != 200)
	{
		std::cout << "ERROR: Second instance of MyVector should have the same value as vint.at(0)!\n";
	}
		
	std::cout << "Testing invalid location in the vector (Error message should be displayed)\n";
	if(vint.at(3) == true)
	{
		std::cout << "Index 3 in this vector is an invalid location!\n";
	}
		
		
	std::cout << "Testing completed" << std::endl; 
    return EXIT_SUCCESS;
}
