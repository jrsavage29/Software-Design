////////////////////////////////////////////////////////////////////////////////////
// ECE 3574, Project 4, Jamahl Savage
//
// File name:	VTmath.h
// Description:	The .h file for the VTmath.cpp. It does all the big number computations for the post fix expressions (+, -, *, /, and ^ ONLY!)
//              This essentially acts similar to that of Java's BigInt class.
//
// Date:	11/28/2019
///////////////////////////////////////////////////////////////////////////////////
#ifndef VTMATH_
#define VTMATH_

#include <iostream> 
#include <cstdlib>	
#include <vector> 
#include <string>
#include <bitset>
#include <algorithm>

using std::vector;
using std::string;
using std::stoi;
using std::bitset;


// An instance of VTmath will contain one integer
//  that is limited in magnitude only by the amount of memory in the computer.
//  This integer may be positive or negative or zero.
class VTmath 
{
private:
	vector<int> BCD_I; //The stack for holding each digit of a number passed to a variable of the VTmath class
	
	int digit; //Essentially useless and was mainly used for debugging purposes. Contains a single digit of number passed into the class
	bool neg; //A boolean variable used to flag if a big number is positive or negative
	
public:
    VTmath();
	VTmath(const VTmath& val);   
	~VTmath();

	// Overloaded assignment operator
	VTmath& operator=(const VTmath& val);      
    VTmath& operator=(int rhs);
	VTmath& operator=(const std::string& rhs);
	// Overloaded stream operator to convert a VTmath object to a 
	//  string suitable for printing. May also be used for other string-based processing.
	friend std::ostream& operator<<(std::ostream& os, const VTmath& rhs);

	// Overloaded comparison operator
	bool operator==(const VTmath& rhs) const;
	bool operator==(const int rhs) const;
	bool operator==(const std::string& rhs) const;

	// Compute m + n (addition) using integers of any magnitude
    VTmath operator+(const VTmath& rhs) const;
	// Compute m - n (subtraction) using integers of any magnitude
	VTmath operator-(const VTmath& rhs) const;	
	// Compute m * n (multiplication) using integers of any magnitude
	VTmath operator*(const VTmath& rhs) const;
	// Compute m / n (division) using integers of any magnitude
	VTmath operator/(const VTmath& rhs) const;
	
	// Compute m^n  (exponentiation) using non-negative integers
	//  Assume that m is allowed to be 0, and n is allowed to be equal to 0,
	//  but m and n will never be 0 at the same time
	VTmath operator^(const VTmath& exp) const;

	// Return the number of decimal digits in this integer
    int size() const; 
	
	void show_BCD_I(std::ostream &os) const; //Used for debugging purposes. Shows digit by digit of the BCD_I vector
	void show_Decimal(std::ostream &os) const; //Shows the whole big number given to the the VTmath class
	string vec_to_string(); //used for string comparison. Also adds the sign to the string
	string vec_to_string_magn();//creates a string form of the number from the vector. String will always be positive.
	bool Is_Lhs_Smaller(string LHS, string RHS) const; //Used to determine the largest number based on magnitudes of strings.
	string digit_multiply(string Lhs, string Rhs) const; //Used for string multiplication (Elementary multiplication)
	string digit_division(string dividend, string divisor) const; //Used for string division (Performed just like long division)
	string digit_subtraction(string lhs, string rhs) const; //Used for subtraction between strings
};

#endif