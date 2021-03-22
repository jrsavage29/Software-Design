////////////////////////////////////////////////////////
// ECE 3574, Project 2 starter code 
//
#include "Interpreter.h"
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::string;


int main(int argc, char **argv)
{
	Interpreter interp;
	
///////////////////////////////////////////////////////////////////////////////CLA mode///////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
	
	if(argc > 1)
	{
		int counter = 1;
		
		
		//displays the help menu
		if((string)argv[1] == "-h")
		{
			cout <<"Usage: ./vtcalc [OPTION] [file ...]"<<endl;
			cout <<"	-e, --expression=EXPR	evaluate expression" << endl;
			cout <<"	-h, --help		display this help and exit" << endl;
			return EXIT_SUCCESS;
		}
		
		
		//Command used for entering a sequence of operands and operators (not a text file)
		if((string)argv[1] == "-e")
		{
			ofstream out("temp.txt", std::ios_base::app);
			counter = 3;
			//cout<<"This is a sequence of operands and operators: " << argv[2] << endl;
			out <<argv[2] << " ";
			out.close();
			
			ifstream input_temp("temp.txt");
				
			interp.compute(input_temp);
			
			input_temp.close();
			remove("temp.txt");
			
		}
		
		//Now we will try to read out of the remaining text files
		while(counter < argc && interp.get_status() == true)
		{
			if((string)argv[counter] != "<")
			{
				ifstream in((string)argv[counter]);
				
				if(in.is_open() == false)
				{
					return EXIT_FAILURE;
				}
			
				else
				{
					interp.compute(in);
				}
				
				in.close();
			}
			
			//In case there is "redirection" (<) in the Linux environment
			else if((string)argv[counter] == "<")
			{
				ifstream in((string)argv[counter + 1]);
				
				if(in.is_open() == false)
				{
					return EXIT_FAILURE;
				}
			
				else
				{
					interp.compute(in);
				}
				
				in.close();
			}
			
			counter++;
		}
		
		
		if(interp.get_status() == false)
		{
			return EXIT_FAILURE;
		}
		
		else
		{
			return EXIT_SUCCESS;
		}
		
	}
	
	else if(argc == 2 && (string)argv[1] == "-e")
	{
		cout <<"Usage: ./vtcalc [OPTION] [file ...]"<<endl;
		cout <<"	-e, --expression=EXPR	evaluate expression" << endl;
		cout <<"	-h, --help		display this help and exit" << endl;
		return EXIT_FAILURE;
	}
	
////////////////////////////////////////////////////////////////////////////////////interactive mode/////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	else if (argc == 1)
	{	
		string line; 
		
		
		while (cin)
		{
			//cout << "What you typed: " << line << endl;
			//counter++;
			//cout<< "This is the value of the counter: " << counter << endl;
			
			interp.compute(cin);
			
			if(interp.get_status() == false)
			{
				//cout << "I did not run succesfully" << endl;
				return EXIT_FAILURE; //probably not going to need this.
			}
		}
		
		
	}
	
	//cout <<"I ran successfully!" << endl;
	
    return EXIT_SUCCESS;
}
