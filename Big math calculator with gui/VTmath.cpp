////////////////////////////////////////////////////////////////////////////////////
// ECE 3574, Project 4, Jamahl Savage
//
// File name:	VTmath.cpp
// Description:	The .cpp file for the VTmath.h. It does all the big number computations for the post fix expressions (+, -, *, /, and ^ ONLY!)
//              This essentially acts similar to that of Java's BigInt class.
//
// Date:	11/28/2019
///////////////////////////////////////////////////////////////////////////////////
#include "VTmath.h"
#include <sstream>	

// default constructor
VTmath::VTmath()
{
	
	digit = 0; //default should be zero
	neg = false; // false for positive, true for negative
	BCD_I.push_back(0); //We will set the size to be 1 and the default value to be 0 when initialized
	
}

// copy constructor 
VTmath::VTmath(const VTmath& val) 
{

	BCD_I = val.BCD_I;
	neg = val.neg;
}

// destructor
VTmath::~VTmath() 
{
	
}


VTmath& VTmath::operator=(const VTmath& val)
{	
	BCD_I.clear(); //clear out the value currently in the left hand-side
	
	
	BCD_I = val.BCD_I; //copy the values of the vector currently in the right hand side VTmath variable into the left-side variable's VTmath vector
	
	
	neg = val.neg; //Also copy the sign of the the right-hand side VTmath variable
	
	return *this;
}

//Assignment operator
VTmath& VTmath::operator=(int rhs)
{
	BCD_I.clear(); //Clear out the current value stored in the vector since we're assigning a new value
	
	
	//Check if negative input was given so we can ignore the negative signal
	if(rhs < 0)
	{
		//std::cout<<"The number is negative!" << std::endl;
		rhs*= -1;
		neg = true;
	}
	//It must be positive then
	else
	{
		//std::cout<<"The number is positive!" << std::endl;
		neg = false;
	}
	
	//If the value read in is just zero, then just store zero and don't go through the conversion process.
	if(rhs == 0)
	{
		BCD_I.push_back(0);
	}
	
	while(rhs > 0 && rhs != 0)
	{
		digit = rhs % 10; // get only one digit of the number
		
		BCD_I.push_back(digit); //Push that digit into the VTmath vector
		
		rhs = rhs / 10;//set up so that the next digit to the left will be turned to binary
	}
	
    std::reverse(BCD_I.begin(), BCD_I.end()); //Reverse the values in the vector so that each digit can be printed out in the correct order
	return *this;
}


VTmath& VTmath::operator=(const std::string& rhs)
{
	BCD_I.clear(); //Clear out the current value stored in the vector since we're assigning a new value
	
	
	string s_rhs = rhs; //Variable will hold a copy of the rhs string so that we don't alter the actual value being passed in.
	int i = 0; //A simple counter variable
	
	
	//Check if negative input was given so we can ignore the negative signal
	std::size_t found = s_rhs.find("-");
	std::size_t found2 = s_rhs.find("_");
	
	
	if(found != std::string::npos)
	{
		s_rhs.erase(s_rhs.find("-"),1);
		//The number string is negative!
		neg = true;
		
	}
	
	else if(found2 != std::string::npos)
	{
		s_rhs.erase(s_rhs.find("_"),1);
		//The number string is negative!
		neg = true;
	}
	
	else //The number must be positive then
	{
		//The number string is positive!
		neg = false;
	}
	
	
	std::size_t found3 = s_rhs.find("0"); //Look to see if there are leading zeros at the beggining of the string
	
	if(found3 == 0 && s_rhs.length() > 1)
	{
		s_rhs.erase(0, s_rhs.find_first_not_of('0'));
	}
	
	
	int max_loc = s_rhs.length(); //We will need to keep the loop going for entire length of the string recieved so that we get each single digit

	while(i < max_loc && s_rhs != "")
	{
		string dig = s_rhs.substr(i,1); //Grab each char/ digit from the string and store it int the vector after 
		//converting it into an integer value.
		
		digit = std::stoi(dig);
		BCD_I.push_back(digit); //Grab each character of the string
				
		i++;
	}
	
	if(s_rhs == "") //if the string recieved is an empty string then we should just set it to the default value
	{
		BCD_I.push_back(0);
		neg = false;
	}
	
    return *this;
}


std::ostream& operator<<(std::ostream& os, const VTmath& rhs)
{
		
	rhs.show_Decimal(os); //Uses a function to get the big number string form of the VTmath's vector
    return os;
}


// compare 2 instances of VTmath
bool VTmath::operator==(const VTmath& rhs) const
{
	
	if(BCD_I != rhs.BCD_I) //Basically compare each digit inside of each VTmath varaible's vector
	{
		return false;	
	}
	
	else 
	{
		return true;
	}
}


// comparison an instance of VTmath to a string representation
bool VTmath::operator==(const std::string& rhs) const
{
	string r = rhs; //string containing the contents of the string being compared to
	VTmath l = *this;
	string bcd = l.vec_to_string(); //the leftside VTmath variable's big number into its string form
	string alt_bcd = bcd; //This is in case the input used the underscore as negative input
	
	//Since they are strings we can compare their string forms
	if(neg == true)
	{
		alt_bcd.insert(0,"_");
	}
	
	
	if(bcd != r && alt_bcd != r) //check for both different negative signs if there are any
	{
		return false;
	}
	
	else
	{
		return true;
	}
	
}

// comparison an instance of VTmath to an int
bool VTmath::operator==(const int rhs) const //compare string wise
{
	VTmath l = *this; //The VTmath value on the left hand side of the  == operator
	int r = rhs; //a copy of the int needing to be compared to
	string s_rhs = std::to_string(r); //Turn that int into a string for string comparison
	
	
	string s_lhs = l.vec_to_string(); //get the string form of the VTmath variable's vector
	
	
	
	if(s_rhs == s_lhs)//compare the strings
	{
		return true;
	}
	
	else
	{
		return false;
	}
	
}


VTmath VTmath::operator+(const VTmath& rhs) const
{
	VTmath Lhs = *this;
	VTmath Rhs = rhs;
	VTmath result;
	int inc_length = 0; //The length we should increase either operand so that they will have the same length during addition or subtraction
	int temp = 0;
	string str = "";
	string ans = "";
	int max_loc = 0; //Used to locate the max index in the string 
	
	
	//If the amount of bcd digits in RHS is bigger than the LHS, then we should, fill the 
	//LHS vector with 0 until it's the same length as the RHS vector
	if(Rhs.size() > Lhs.size())
	{
		max_loc = Rhs.size() - 1;
		inc_length = Rhs.size() - Lhs.size();
		for(int n = 0; n < inc_length; n++)
		{
			Lhs.BCD_I.insert(Lhs.BCD_I.begin(), 0);
		}
	}
	
	//If the amount of bcd digits in LHS is bigger than the RHS, then we should, fill the 
	//RHS vector with 0 until it's the same length as the LHS vector
	else
	{
		max_loc =  Lhs.size() - 1;
		inc_length = Lhs.size() - Rhs.size();
		for(int n = 0; n < inc_length; n++)
		{
			Rhs.BCD_I.insert(Rhs.BCD_I.begin(), 0);
		}
	}
	
	string s_lhs = Lhs.vec_to_string_magn();
	string s_rhs = Rhs.vec_to_string_magn();
	
	//Different situations for addition:
	
	if(Lhs.neg == false && Rhs.neg == false)//if both operands are positive
	{
		//Doing Addition
		while(max_loc >= 0)
		{
			
			temp = Lhs.BCD_I[max_loc] + Rhs.BCD_I[max_loc];
			
			if(temp > 9 && max_loc > 0) //If the result of the digit by digit addition is larger than 9, then we need to carry a 1 over to the next digit 
			{
				//performing a carry
				temp -= 10;
				Lhs.BCD_I[max_loc - 1] += 1;
				str = std::to_string(temp);
				
			}
			
			else if(temp > 9 && max_loc == 0) //This happens only if we are doing addition between the last digits of the lhs and rhs. If there results a carry then we just simply take that result and add it to the string
			{
				//The leftmost digit addition resulted in a carry
				str = std::to_string(temp);
				reverse(str.begin(), str.end());
			}
			
			else
			{
				str = std::to_string(temp); //If none of the cases are meet then just add the result to the string to be stored in the answer
			}
			
			ans = ans + str; //The string used to store the answers
			
			max_loc--;
		}
				
		result.neg = false;
		reverse(ans.begin(), ans.end()); //We reverse the ans string so that result, digit by digit, are in the right order
		
		result = ans;
		
	
	}	

	else if(Lhs.neg == true && Rhs.neg == false)//if the LHS is negative but the RHS is positive
	{
		//Use the subtraction operation here and check the magnitudes of the numbers to see if the result 
		//should be negative or positive.
		
		if(s_lhs == s_rhs) // If the magnitudes are the same, then the result should be 0.
		{
			ans = "0";
			result.neg = false;
			result = ans;
			return result;
			
		}
		
		if(Is_Lhs_Smaller(s_lhs, s_rhs) == false) //Perform normal subtraction if the lhs is larger than the rhs
		{			
			//Doing Subtraction even though this technically addition between a negative Lhs and a positive Rhs
			while(max_loc >= 0)
			{
				
				temp = Lhs.BCD_I[max_loc] - Rhs.BCD_I[max_loc];
				
				if(temp < 0 && max_loc > 0)
				{
					//The performing a carry from next digit
					temp += 10;
					Lhs.BCD_I[max_loc - 1] -= 1;
					str = std::to_string(temp);
					
				}
				
				else if(temp < 0 && max_loc == 0)
				{
					//The leftmost digit subtraction resulted in an attempted carry from leftmost digit
					temp*= -1;
					str = std::to_string(temp);
					reverse(str.begin(), str.end());
				}
				
				else
				{
					str = std::to_string(temp);
				}
				
				result.neg = true;
				ans = ans + str;
				
				max_loc--;
			}
		}
		
		else if(Is_Lhs_Smaller(s_lhs, s_rhs) == true) //In the situation where the rhs is a larger magnitude than the lhs
		{
			
			//Doing normal subtraction for 2nd case where rhs is bigger than lhs
			while(max_loc >= 0)
			{
				
				temp = Rhs.BCD_I[max_loc] - Lhs.BCD_I[max_loc];
				
				if(temp < 0 && max_loc > 0)
				{
					//[2nd case]Performing a carry from next digit
					temp += 10;
					Rhs.BCD_I[max_loc - 1] -= 1;
					str = std::to_string(temp);
					
				}
				
				else if(temp < 0 && max_loc == 0)
				{
					//[2nd]The leftmost digit subtraction resulted in an attempted carry from leftmost digit
					temp*= -1;
					str = std::to_string(temp);
					reverse(str.begin(), str.end());
				}
				
				else
				{
					str = std::to_string(temp);
				}
				
				result.neg = false;
				ans = ans + str;
				
				max_loc--;
			}
		}
				
		reverse(ans.begin(), ans.end());
		
		if(result.neg == true && ans != "0")
		{
			//The given number was supposed to be negative, so imma add a negative to it.
			ans.insert(0,"-");
		}
		
		else
		{
			result.neg = false;
		}
		
		
		result = ans;
	}
	
	else if(Lhs.neg == false && Rhs.neg == true)//if the LHS is positive but the RHS is negative
	{
		//Use the subtraction operation here and check the magnitudes of the numbers to see if the result 
		//should be negative or positive.
		
		if(s_lhs == s_rhs) //Same deal here with equal magnitudes
		{
			ans = "0";
			result.neg = false;
			result = ans;
			return result;
			
		}
		
		if(Is_Lhs_Smaller(s_lhs, s_rhs) == false) //Perform normal subtraction if the lhs is larger than the rhs
		{			
			//Doing Subtraction
			while(max_loc >= 0)
			{
				
				temp = Lhs.BCD_I[max_loc] - Rhs.BCD_I[max_loc];
				
				//The result of the digit by digit subtraction results in a negative number, 
				//then we need to take a carry from the next digit in front of the current digit we're doing subtraction on
				if(temp < 0 && max_loc > 0) 
				{
					//The performing a carry from next digit
					temp += 10;
					Lhs.BCD_I[max_loc - 1] -= 1;
					str = std::to_string(temp);
					
				}
				
				//This in the case we're doing subtraction between the 2 leftmost digits. 
				//We know the result will be negative but we only want the magnitude since we need to reverse the string
				else if(temp < 0 && max_loc == 0) 
				{
					//The leftmost digit subtraction resulted in an attempted carry from leftmost digit
					temp*= -1;
					str = std::to_string(temp);
					reverse(str.begin(), str.end());
				}
				
				else //else just simply add the result of the digit by digit subtraction to the string
				{
					str = std::to_string(temp);
				}
				
				result.neg = false;
				ans = ans + str;
				
				max_loc--;
			}
		}
		
		else if(Is_Lhs_Smaller(s_lhs, s_rhs) == true) //In the situation where the rhs is a larger magnitude than the lhs
		{
			
			//Doing normal subtraction for 2nd case where rhs is bigger than lhs
			while(max_loc >= 0)
			{
				
				temp = Rhs.BCD_I[max_loc] - Lhs.BCD_I[max_loc];
				
				if(temp < 0 && max_loc > 0)
				{
					//[2nd case]Performing a carry from next digit
					temp += 10;
					Rhs.BCD_I[max_loc - 1] -= 1;
					str = std::to_string(temp);
					
				}
				
				else if(temp < 0 && max_loc == 0)
				{
					//[2nd]The leftmost digit subtraction resulted in an attempted carry from leftmost digit
					temp*= -1;
					str = std::to_string(temp);
					reverse(str.begin(), str.end());
				}
				
				else
				{
					str = std::to_string(temp);
				}
				
				result.neg = true;
				ans = ans + str;
				
				max_loc--;
			}
		}
				
		reverse(ans.begin(), ans.end());
		
		if(result.neg == true && ans != "0")
		{
			//The given number was supposed to be negative, so imma add a negative to it.
			ans.insert(0,"-");
		}
		
		else
		{
			result.neg = false;
		}
		
		
		result = ans;
		
	
	}	
	
	else if(Lhs.neg == true && Rhs.neg == true)//if both operands are negative
	{
		//Treat like regular addition except the result should be negative
				
		//Doing Addition
		while(max_loc >= 0)
		{
			
			temp = Lhs.BCD_I[max_loc] + Rhs.BCD_I[max_loc];
			
			if(temp > 9 && max_loc > 0)
			{
				//performing a carry
				temp -= 10;
				Lhs.BCD_I[max_loc - 1] += 1;
				str = std::to_string(temp);
				
			}
			
			else if(temp > 9 && max_loc == 0)
			{
				//The leftmost digit addition resulted in a carry
				str = std::to_string(temp);
				reverse(str.begin(), str.end());
			}
			
			else
			{
				str = std::to_string(temp);
			}
			
			ans = ans + str;
			
			max_loc--;
		}
				
		result.neg = true;
		reverse(ans.begin(), ans.end());
		
		if(result.neg == true && ans != "0")
		{
			//The given number was supposed to be negative, so imma add a negative to it.
			ans.insert(0,"-");
		}
		
		else
		{
			result.neg = true;
		}
		
		
		result = ans;
	}
	
	return result;
}


VTmath VTmath::operator-(const VTmath& rhs) const
{
	//This function covers 4 different scenarios for subtraction, positive minus positive, positive minus negative, negative minus positive, and negative minus negative
	
	VTmath Lhs = *this;
	VTmath Rhs = rhs;
	VTmath result;
	int inc_length = 0;
	int temp = 0;
	string str = "";
	string ans = "";
	int max_loc = 0;
	
	
	//If the amount of bcd digits in RHS is bigger than the LHS, then we should, fill the 
	//LHS vector with 0 until it's the same length as the RHS vector
	if(Rhs.size() > Lhs.size())
	{
		max_loc = Rhs.size() - 1;
		inc_length = Rhs.size() - Lhs.size();
		for(int n = 0; n < inc_length; n++)
		{
			Lhs.BCD_I.insert(Lhs.BCD_I.begin(), 0);
		}
	}
	
	//If the amount of bcd digits in LHS is bigger than the RHS, then we should, fill the 
	//RHS vector with 0 until it's the same length as the LHS vector
	else
	{
		max_loc =  Lhs.size() - 1;
		inc_length = Lhs.size() - Rhs.size();
		for(int n = 0; n < inc_length; n++)
		{
			Rhs.BCD_I.insert(Rhs.BCD_I.begin(), 0);
		}
	}
	
	string s_lhs = Lhs.vec_to_string_magn();
	string s_rhs = Rhs.vec_to_string_magn();
	
	//Different situations for subtraction:
	
	if(Lhs.neg == false && Rhs.neg == false)//if both operands are positive
	{
		
		if(s_lhs == s_rhs)
		{
			ans = "0";
			result.neg = false;
			result = ans;
			return result;
			
		}
		
		if(Is_Lhs_Smaller(s_lhs, s_rhs) == false) //Perform normal subtraction if the lhs is larger than the rhs
		{			
			//Doing Subtraction
			while(max_loc >= 0)
			{
				
				temp = Lhs.BCD_I[max_loc] - Rhs.BCD_I[max_loc];
				
				if(temp < 0 && max_loc > 0)
				{
					//The performing a carry from next digit
					temp += 10;
					Lhs.BCD_I[max_loc - 1] -= 1;
					str = std::to_string(temp);
					
				}
				
				else if(temp < 0 && max_loc == 0)
				{
					//The leftmost digit subtraction resulted in an attempted carry from leftmost digit
					temp*= -1;
					str = std::to_string(temp);
					reverse(str.begin(), str.end());
				}
				
				else
				{
					str = std::to_string(temp);
				}
				
				result.neg = false;
				ans = ans + str;
				
				max_loc--;
			}
		}
		
		else if(Is_Lhs_Smaller(s_lhs, s_rhs) == true) //In the situation where the rhs is a larger magnitude than the lhs
		{
			
			//Doing normal subtraction for 2nd case where rhs is bigger than lhs
			while(max_loc >= 0)
			{
				
				temp = Rhs.BCD_I[max_loc] - Lhs.BCD_I[max_loc];
				
				if(temp < 0 && max_loc > 0)
				{
					//[2nd case]Performing a carry from next digit
					temp += 10;
					Rhs.BCD_I[max_loc - 1] -= 1;
					str = std::to_string(temp);
					
				}
				
				else if(temp < 0 && max_loc == 0)
				{
					//[2nd]The leftmost digit subtraction resulted in an attempted carry from leftmost digit
					temp*= -1;
					str = std::to_string(temp);
					reverse(str.begin(), str.end());
				}
				
				else
				{
					str = std::to_string(temp);
				}
				
				result.neg = true;
				ans = ans + str;
				
				max_loc--;
			}
		}
				
		reverse(ans.begin(), ans.end());
		
		if(result.neg == true && ans != "0")
		{
			//The given number was supposed to be negative, so imma add a negative to it.
			ans.insert(0,"-");
		}
		
		else
		{
			result.neg = false;
		}
		
		
		result = ans;
		
	
	}	

	else if(Lhs.neg == true && Rhs.neg == false)//if the LHS is negative but the RHS is positive
	{
		//Treat as the addition of 2 negative numbers
		//Doing subtraction but technically it's addition of 2 negative numbers
		while(max_loc >= 0)
		{
			
			temp = Lhs.BCD_I[max_loc] + Rhs.BCD_I[max_loc];
			
			if(temp > 9 && max_loc > 0)
			{
				//performing a carry
				temp -= 10;
				Lhs.BCD_I[max_loc - 1] += 1;
				str = std::to_string(temp);
				
			}
			
			else if(temp > 9 && max_loc == 0)
			{
				//The leftmost digit addition resulted in a carry
				str = std::to_string(temp);
				reverse(str.begin(), str.end());
			}
			
			else
			{
				str = std::to_string(temp);
			}
			
			ans = ans + str;
			
			max_loc--;
		}
				
		result.neg = true;
		reverse(ans.begin(), ans.end());
		
		if(result.neg == true && ans != "0")
		{
			//The given number was supposed to be negative, so imma add a negative to it.
			ans.insert(0,"-");
		}
		
		else
		{
			result.neg = false;
		}
		
		
		result = ans;
	}
	
	else if(Lhs.neg == false && Rhs.neg == true)//if the LHS is positive but the RHS is negative
	{
		//Treat as the addition of 2 positive numbers
		//Doing subtraction in which technically 2 positive numbers are added together.
		//Doing Addition
		while(max_loc >= 0)
		{
			
			temp = Lhs.BCD_I[max_loc] + Rhs.BCD_I[max_loc];
			
			if(temp > 9 && max_loc > 0)
			{
				//The performing a carry
				temp -= 10;
				Lhs.BCD_I[max_loc - 1] += 1;
				str = std::to_string(temp);
				
			}
			
			else if(temp > 9 && max_loc == 0)
			{
				//The leftmost digit addition resulted in a carry
				str = std::to_string(temp);
				reverse(str.begin(), str.end());
			}
			
			else
			{
				str = std::to_string(temp);
			}
			
			ans = ans + str;
			
			max_loc--;
		}
				
		result.neg = false;
		reverse(ans.begin(), ans.end());
		
		result = ans;
		
		
	}
	
	else if(Lhs.neg == true && Rhs.neg == true)//if both operands are negative
	{
		//Treat like addition but with the lhs staying negative and the rhs being positive. Therefore, switch the Lhs to be the Rhs and the Rhs to be the Lhs so that
		//it's like regular subtraction now.
		
		if(s_lhs == s_rhs)
		{
			ans = "0";
			result.neg = false;
			result = ans;
			return result;
			
		}
		
		if(Is_Lhs_Smaller(s_lhs, s_rhs) == false) //Perform normal subtraction if the lhs is larger than the rhs
		{			
			//Doing Subtraction
			while(max_loc >= 0)
			{
				
				temp = Lhs.BCD_I[max_loc] - Rhs.BCD_I[max_loc];
				
				if(temp < 0 && max_loc > 0)
				{
					//The performing a carry from next digit
					temp += 10;
					Lhs.BCD_I[max_loc - 1] -= 1;
					str = std::to_string(temp);
					
				}
				
				else if(temp < 0 && max_loc == 0)
				{
					//The leftmost digit subtraction resulted in an attempted carry from leftmost digit
					temp*= -1;
					str = std::to_string(temp);
					reverse(str.begin(), str.end());
				}
				
				else
				{
					str = std::to_string(temp);
				}
				
				result.neg = true;
				ans = ans + str;
				
				max_loc--;
			}
		}
		
		else if(Is_Lhs_Smaller(s_lhs, s_rhs) == true) //In the situation where the rhs is a larger magnitude than the lhs
		{
			
			//Doing normal subtraction for 2nd case where rhs is bigger than lhs
			while(max_loc >= 0)
			{
				temp = Rhs.BCD_I[max_loc] - Lhs.BCD_I[max_loc];
				
				if(temp < 0 && max_loc > 0)
				{
					//[2nd case]Performing a carry from next digit
					temp += 10;
					Rhs.BCD_I[max_loc - 1] -= 1;
					str = std::to_string(temp);
					
				}
				
				else if(temp < 0 && max_loc == 0)
				{
					//[2nd]The leftmost digit subtraction resulted in an attempted carry from leftmost digit
					temp*= -1;
					str = std::to_string(temp);
					reverse(str.begin(), str.end());
				}
				
				else
				{
					str = std::to_string(temp);
				}
				
				result.neg = false;
				ans = ans + str;
				
				max_loc--;
			}
		}
				
		reverse(ans.begin(), ans.end());
		
		if(result.neg == true && ans != "0")
		{
			//The given number was supposed to be negative, so imma add a negative to it.
			ans.insert(0,"-");
		}
		
		else
		{
			result.neg = false;
		}
		
		result = ans;
		
	}
	

	return result;
}


VTmath VTmath::operator*(const VTmath& rhs) const
{
	VTmath Lhs = *this;
	VTmath Rhs = rhs;
	
	string s_Lhs = Lhs.vec_to_string_magn(); //We get the magnitudes of the rhs and lhs and perform multiplication on those
	string s_Rhs = Rhs.vec_to_string_magn();
	
	string ans = "";
	
	VTmath result;
	
	if(s_Lhs == "0" || s_Rhs == "0") //If we're multiplying 0 then the result will simply be 0
	{
		ans = "0";
		result = ans;
		return result;
	}
	
	ans = digit_multiply(s_Lhs, s_Rhs); //store the result of string multiplication in this string
	
	
	if( (Lhs.neg == true && Rhs.neg == false) || (Lhs.neg == false && Rhs.neg == true) )//if one of the operands is negative
	{
		//One of the numbers must have been negative, therefore the result should be negative.
		result.neg = true;
	}
	
	else if(Lhs.neg == true && Rhs.neg == true) //if both of the operands are negative
	{
		//Both numbers must've been negative, therefore the result will positive.
		result.neg = false;
	}
	
	else //Otherwise the result should  be positive
	{
		//Both numbers must be positive
		result.neg = false;
	}
	
	if(result.neg == true)
	{
		//The given number was supposed to be negative, so imma add a negative to it.
		ans.insert(0,"-");
	}
	
	
	
	result = ans;
	
	return result;
}

VTmath VTmath::operator/(const VTmath& rhs) const
{	
	VTmath Lhs = *this;
	VTmath Rhs = rhs;
	
	
	//We get the magnitudes of the rhs and lhs and worry about the sign of the result after we compute the division
	string s_Lhs = Lhs.vec_to_string_magn();
	string s_Rhs = Rhs.vec_to_string_magn();
	
	string ans = "";
	
	VTmath result;
	
	ans = digit_division(s_Lhs, s_Rhs); //store the result of string long division in this string
	
	if(ans == "0") //This could either be due to the user trying to divide 0 by a number, the user trying to divide the dividend by a larger divisor, or the user trying to cause an error
	{
		result.neg = false;
	}
	
	if( ((Lhs.neg == true && Rhs.neg == false) || (Lhs.neg == false && Rhs.neg == true)) && ans != "0" )//if one of the operands is negative
	{
		//One of the numbers must have been negative, therefore the result should be negative.
		result.neg = true;
	}
	
	else if(Lhs.neg == true && Rhs.neg == true && ans != "0") //if both of the operands are negative
	{
		//Both numbers must've been negative, therefore the result will positive.
		result.neg = false;
	}
	
	else //Otherwise the result should  be positive
	{
		
		result.neg = false;
	}
	
	if(result.neg == true && ans != "0")
	{
		//The given number was supposed to be negative, so imma add a negative to it.
		ans.insert(0,"-");
	}
	
	result = ans;
	
	return result;
}

VTmath VTmath::operator^(const VTmath& exp) const //If the last digit of the exponential term is is 0 after modulus, then the sign of the result will be positive
{
	VTmath Lhs = *this;
	VTmath Rhs = exp;
	VTmath result;
	string ans;
	
	string s_Lhs = Lhs.vec_to_string_magn();
	string s_Rhs = Rhs.vec_to_string_magn();
	int exp_count = std::stoi(s_Rhs) - 1;
	
	int last_Rhs_digit = s_Rhs[s_Rhs.length()-1];
	
	if(Lhs == 0 && Rhs == 0)
	{
		//You can't raise 0 by 0!! Returning '0' instead
		ans = "0";
		result = ans;
		return result;
	}
	
	if(Lhs.neg == true && last_Rhs_digit % 2 == 0)
	{
		result.neg = false;
	}
	
	else if(Lhs.neg == true && Lhs.neg == true && last_Rhs_digit % 2 == 1)
	{
		result.neg = true;
	}
	
	if(Rhs == 0)
	{
		ans = "1";
		result = ans;
		return result;
	}
	
	ans = s_Lhs;
	
	if(Rhs == 1)
	{
		ans = s_Lhs;
	}
	
	while(exp_count > 0 && s_Rhs != "1")
	{ 
		ans = digit_multiply(s_Lhs, ans);
		
		exp_count--;
	}
	
	
	
	if(result.neg == true)
	{
		//The given number was supposed to be negative, so imma add a negative to it.
		ans.insert(0,"-");
	}
	
	result = ans;
	return result;
}


int VTmath::size() const
{
    return BCD_I.size(); //simply return the size of vector storing each digit of the big number
}

void VTmath::show_BCD_I(std::ostream &os) const
{
	int i = 0;
	int max_loc = BCD_I.size()-1; //The max index inside the vector
	
	while(i <= max_loc)
	{
        os << BCD_I[i] << " "; //store the printed out resulted of the digit by digit vector into the ostream for being displayed
		i++;
	}
}

void VTmath::show_Decimal(std::ostream &os) const
{
	int i = 0;
	int max_loc = BCD_I.size()-1; //The max index inside the vector
	string str = "";
	while(i <= max_loc)
	{
		str += std::to_string(BCD_I[i]);//store the printed out resulted of the digit by digit vector into a string for being displayed
		i++;
	}
	
	if(neg == true) //If the private variable neg is true for that instance of the VTmath class, then we should append a negative sign to the front of the string
	{
		str.insert(0,"-");
	}
	
	os << str; //pass the string to the ostream
}


string VTmath::vec_to_string()
{
	int i = 0;
	int max_loc = BCD_I.size()-1; //The max index inside the vector
	string str = "";
	while(i <= max_loc)
	{
		str += std::to_string(BCD_I[i]); //store the printed out resulted of the digit by digit vector into a string
		i++;
	}
	
	if(neg == true)
	{
		str.insert(0,"-"); //If the private variable neg is true for that instance of the VTmath class, then we should append a negative sign to the front of the string
	}
	
	return str;
}

string VTmath::vec_to_string_magn() //This is like the function above but only returns a magnitude version of the vector containing each digit.
{
	int i = 0;
	int max_loc = BCD_I.size()-1; //The max index inside the vector
	string str = "";
	while(i <= max_loc)
	{
		str += std::to_string(BCD_I[i]);
		i++;
	}
		
	return str;
}

bool VTmath::Is_Lhs_Smaller(string LHS, string RHS) const
{ 
    // Calculate lengths of both string 
	
	
	string s_RHS = RHS;
	string s_LHS = LHS;
	
	
	std::size_t foundRHS = s_RHS.find("0"); //Look to see if there are leading zeros at the beggining of the string
	std::size_t foundLHS = s_LHS.find("0"); //Look to see if there are leading zeros at the beggining of the string
	
	if(foundRHS == 0 && s_RHS.length() > 1)
	{
		s_RHS.erase(0, s_RHS.find_first_not_of('0'));
	}
	
	if(foundLHS == 0 && s_LHS.length() > 1)
	{
		s_LHS.erase(0, s_LHS.find_first_not_of('0'));
	}
	
	//After getting rid of leading 0s in the rhs and lhs
	
	int Lhs = s_LHS.length(); 
	int Rhs = s_RHS.length(); 
	
	if(Lhs == Rhs)
	{
		//The lengths are equal like they should be in some cases
	}
	
    if (Lhs < Rhs)
	{	
		//The Lhs is smaller!
        return true; 
	}
	
    if (Rhs < Lhs)
	{	
		//The Rhs is smaller!
        return false; 
	}
	
	//If those didn't pass then we will check digit by digit to see how has the larger magnitude
	for (int i=0; i<Lhs; i++) 
    { 
        if (s_LHS[i] < s_RHS[i])
		{	
			//The Lhs is smaller!
            return true; 
		}
		
        else if (s_LHS[i] > s_RHS[i]) 
		{
			//The Rhs is smaller!
            return false; 
		}
    } 
	
    return false; 
} 

string VTmath::digit_multiply(string Lhs, string Rhs) const
{ 
    int len1 = Lhs.size(); 
    int len2 = Rhs.size();
	
	string s_Lhs = Lhs;
	string s_Rhs = Rhs;
	
    if (len1 == 0 || len2 == 0) //If not given anything to multiply then we should just return a 0
    {
		return "0"; 
	}
	
    //Keep the result number in vector 
    // in reverse order 
    vector<int> result(len1 + len2, 0); 
  
    // Below are two indexes that are used to find positions 
    // in the result.  
    int i_n1 = 0;  
    int i_n2 = 0;  
      
    //We go from right to left in the Lhs 
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = s_Lhs[i] - '0'; 
  
        // Shift position to left after every 
        // multiplication of a digit in Rhs 
        i_n2 = 0;  
          
        // Go from right to left in Rhs              
        for (int j=len2-1; j>=0; j--) 
        { 
            // Take current digit of second number 
            int n2 = s_Rhs[j] - '0'; 
  
            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
  
            // Carry for next iteration 
            carry = sum/10; 
  
            // Store result 
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        // store carry in next cell 
        if (carry > 0) 
		{
            result[i_n1 + i_n2] += carry; 
		}
		
        // Shift position to left after every 
        // multiplication of a digit in the Lhs. 
        i_n1++; 
    } 
  
    // ignore '0's from the right 
    int i = result.size() - 1; 
	
    while (i>=0 && result[i] == 0) 
	{
		i--; 
	}
	
    // If all were '0's - means either both or 
    // one of Lhs or Rhs were '0' 
    if (i == -1)
	{		
		return "0";
	}		
  
    // generate the result string 
    string str = ""; 
      
    while (i >= 0)
	{		
        str += std::to_string(result[i--]); 
	}
  
    return str; 
} 

string VTmath::digit_subtraction(string lhs, string rhs)const
{
    // Take an empty string for storing result 
    string str = ""; 
  
    // Calculate length of both string 
    int n1 = lhs.length(), n2 = rhs.length(); 
  
    // Reverse both of strings 
    reverse(lhs.begin(), lhs.end()); 
    reverse(rhs.begin(), rhs.end()); 
      
    int carry = 0; 
  
    // Run loop till small string length 
    // and subtract digit of str1 to str2 
    for (int i=0; i<n2; i++) 
    { 
        // Do school mathematics, compute difference of 
        // current digits 
          
        int sub = ((lhs[i]-'0')-(rhs[i]-'0')-carry); 
          
        // If subtraction is less then zero 
        // we add then we add 10 into sub and 
        // take carry as 1 for calculating next step 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
  
        str.push_back(sub + '0'); 
    } 
  
    // subtract remaining digits of larger number 
    for (int i=n2; i<n1; i++) 
    { 
        int sub = ((lhs[i]-'0') - carry); 
          
        // if the sub value is -ve, then make it positive 
        if (sub < 0) 
        { 
            sub = sub + 10; 
            carry = 1; 
        } 
        else
            carry = 0; 
              
        str.push_back(sub + '0'); 
    } 
  
    // reverse resultant string 
    reverse(str.begin(), str.end()); 
  
    return str; 
	
}


string VTmath::digit_division(string dividend, string divisor) const
{
	//Doing long division
	// Since result can be very large store it in string  
	string quotient = "";
	bool continue_division = true; //Used to control how long long division is done
	

	//After subtraction can no longer be performed on te current dividend because the divisor is now bigger, we carry down what ever is left of the original dividend and add it to the result.
	//We will then perform subtraction on the new result using the divisor and repeat this process unitl we can't carry down any more.
	int carry_downs = 0; //Lets us know how many carrys we have left
	int loc_carry = 0;	//Holds the location of the next carry.
	int iterations = 0; //counts how many times the subtraction was able to be performed against the current dividend and the divisor

	if(divisor == "1")
	{
		return dividend;
	}

	//Just for fun because obviously you shouldn't be dividing by 0
	if(divisor == "0")
	{
		//You can not divide by 0! Error is represented by a '0'
		return "0";
	}

	string s_dividend = dividend;

	if(dividend == divisor)
	{
		return "1";
	}

	else if(Is_Lhs_Smaller(dividend, divisor) == true)
	{
		//The precision is set to 0 in this mode so dividing by large divisor does not return a decimal, just 0!
		return "0";
	}

	else if(Is_Lhs_Smaller(dividend, divisor) == false)
	{
		//The dividend will have carrys!
		s_dividend = s_dividend.substr(0,divisor.length());
		carry_downs = dividend.length() - s_dividend.length();
	}

	while(continue_division == true)
	{
		if(carry_downs <= 0 && Is_Lhs_Smaller(s_dividend, divisor) == true)
		{
			//We are out of carrys!
			continue_division = false;
		}
		
		//Doing the subtraction part of long division
		if(Is_Lhs_Smaller(s_dividend, divisor) == false)
		{
			s_dividend = digit_subtraction(s_dividend, divisor); //answer will hold the result of the subtraction between the dividend and the divisor
			iterations++;
			
			//std::cout<<"The dividend is now: " << s_dividend << std::endl;
			//std::cout<<"Long division subtraction has been done: " << iterations <<" times on the current dividend"<< std::endl;
		}
		
		//This means either we're done with the first iteration of subtration and need to bring down the carry from the original
		//dividend or if we have no more carrys from the original then we need to stop.
		
		if(Is_Lhs_Smaller(s_dividend, divisor) == true) 
		{
			//The dividend is too small to continue division, so lets look to see if we can carry down
			
			if(loc_carry != (int)dividend.length())
			{
				quotient = quotient + std::to_string(iterations);
			}
			
			iterations = 0;
			
			loc_carry = (dividend.length() - carry_downs);
			
			
			if(loc_carry < (int)dividend.length())
			{
				carry_downs--; //We've done a carry so we will have to carry down the next loc in the original dividend if it's available
				s_dividend += dividend[loc_carry];
				
			}
		}
		
	}

	return quotient; 
}