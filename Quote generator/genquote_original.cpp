/*
*  Purpose for program:
*  For this project creating a program that generates quotes from a text file.
*  The program also uses the commands -r (which removes a quote from the text file),
*  -a (which adds a quote to the text file), and -f (which changes the default text file database
*  for the quotes).
*  
*  Programmer: Jamahl Savage
*  Date: September 12, 2019
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/
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
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;



class GenQuote
{
private:

	string fName; //holds the filename of the text file holding the quotes
	int myindex; //holds the index of the quotes inside the quote database
	int size; //used to hold the how many entries (quotes) are in the text file 
	string quoteHolder; //This holds the quote that is to added
	string removeQuoteHolder; //This holds the quote that is to be removed
	bool status; //this holds the whether the code has passed or failed.
		
public:

	GenQuote();
	
	void addFileName(string input); //Changes the default filename for the quote database
	void addNewQuote(string output); //adds a new quote
	bool removeQuote(string output); //removes a quote from the text file
	void updateSize(string input); //updates the size variable with the current amount of entries in the text file
	
	string returnQuote(); //gives back the current quote to be added
	string returnRemoveQuote(); //gives back the current quote to be removed
	string getFileName(); //gives back the filename of the text file database
	int getSize(); //gives back the amount of entries in the text file
	void setAddQuote(string addQuote); //sets the quote to be added into the text file database
	void setRemoveQuote(string removeQuote); //sets the quote to be removed from the text file database
	void setIndex(int index); //sets the index for generating the quotes in the text file database
	int getIndex(); //gives back the current index for generating the quotes
	bool getStatus(); //gives back the pass or fail status of a function
	void setStatus(bool stat); //sets the pass or fail status of a function
	
};

GenQuote::GenQuote() //sets the default values for the private variables
{
	fName = "genquote.txt";
	size = 0;
	quoteHolder = " ";
	removeQuoteHolder = " ";
	myindex = 1;
}


void GenQuote::addFileName(string input)
{
	fName = input;
}

void GenQuote::addNewQuote(string output)
{
	ifstream in(output);
	
	ofstream out(output, std::ios_base::app); //appends any additional text
	
	
	out << quoteHolder << endl;;
		
	
	ifstream in2("index"+fName);
	
	
	if(in2.is_open() == false) //if the given file doesn't exist. Since we're adding a quote we will go ahead and create the file
	{
		ofstream out2("index"+fName); //also create an index file for the quotes
		//cout<<"The index file didn't exist so I'll create one for you"<<endl;
		out2 << myindex <<endl;
		out2.close();
	}
	
	
	out.close();
	in.close();
	in2.close();
	
	//cout <<"The current size of the file AFTER ADDING is now: " << size << endl;
	
	
}

bool GenQuote::removeQuote(string output)
{
	string temp;
	string temp2;
	ifstream in(output); //read in the file in which we will be removing the quote from
	ofstream out("temp.txt"); //use this temp file to collect all the quotes to not be removed from the text file database
	bool Found = false; //a flag used to know not to copy the following quote into the temp text file
	int curLine = 0; //variable for knowing the current line in the text file we're on
	
	while(getline(in,temp))
    {
		curLine++;
		//cout << temp <<endl;
		if(temp.find(removeQuoteHolder, 0) != string::npos && Found == false)
		{
			//cout << "found: " << removeQuoteHolder << "line: " << curLine << endl;
			cout <<"The following quotation has been removed:" <<endl;
			cout << temp << endl;
			Found = true;
		}
		
		else
		{
			out << temp << endl;
		}
    }
	
			
	out.close();
	in.close();
	
	if(Found == true) //Since the quote we wanted has been "removed". We will copy the results of the removal back into the original file
	{
		ifstream in2("temp.txt"); //retrieve the results from the temp file
		ofstream out2(output); //output the results in the original text file from whence the quotes came.
	
		while(getline(in2,temp))
		{
			
			out2 << temp << endl;
			
		}
	
		out2.close();
		in2.close();
		
		
	}
	
	else //if the keyword related to quote to be removed is not found within the text file, then we return EXIT_FAILURE.
	{
		
		//cout << "Error: The keyword/s \"" <<removeQuoteHolder<< "\" does/do not belong to any of available quotes in " << fName << endl;
		remove("temp.txt"); //Delete the temp.txt because it's useless now really.
		setStatus(EXIT_FAILURE);
		return EXIT_FAILURE;
		
	}
	
	remove("temp.txt"); //same thing here
	return true; //return true if there were no issues and removal was a success
	
}

void GenQuote::updateSize(string input)
{
	string temp;
	ifstream in(input);
	
	while(getline(in,temp, '\n')) //read through the whole text file until fail
    {
			size++; //increase the size for every successful line read.
			//cout <<"The size is: "<< size << endl;
	}
	in.close();
}

//The following are setters and getter methods for the private variables of the class.
string GenQuote::returnQuote()
{
	
	return quoteHolder;
}

string GenQuote::returnRemoveQuote()
{
	return removeQuoteHolder;
}

string GenQuote::getFileName()
{
	return fName;
}

int GenQuote::getSize()
{
	return size;
}

void GenQuote::setAddQuote(string addQuote)
{
	quoteHolder = addQuote;
}

void GenQuote::setIndex(int index)
{
	myindex = index;
}

int GenQuote::getIndex()
{
	return myindex;
}

void GenQuote::setRemoveQuote(string removeQuote)
{
	removeQuoteHolder = removeQuote;
}

bool GenQuote::getStatus()
{
	return status;
}

void GenQuote::setStatus(bool stat)
{
	status = stat;
}



int main(int argc, char **argv)
{
	GenQuote g; //make an instance of the class
	
	//used to keep track of when and how many times a certain command has been entered. This allows for detection of the different orders in which the commands
	//can be inputted
	int aCommand = 0;
	int fCommand = 0;
	int rCommand = 0;
	
	//Used to check if any of the possible commands are entered.
	bool fFound = false;
	bool rFound = false;
	bool aFound = false;
	
	//We will start reading from the default file even if it doesn't exist
	ifstream in(g.getFileName());
	
	
	
	int counter = 1;
	int temp = argc - 1;
	
	
	if(argc == 1)//if only ./genquote.exe is the only argument in the commandline
	{
		if(in.is_open() == false)
		{
			//cout<<"Error! The file you're trying to retrieve a quote from is either empty or does not exist." <<endl;
			return EXIT_FAILURE;
		}
		
		else
		{
			//cout << "Your text file is now set to: " << g.getFileName() << endl;
			string tempIndex;
			string quote;
			int indexloc = 0;
			string filename = g.getFileName();
			//cout << "Print out first quote from the file "<< filename << endl;
			
			ifstream readfile(filename);
			ifstream indexfile("index" + filename);
			indexfile >> tempIndex;
			indexfile.close();
			
			g.setIndex(stoi(tempIndex));
			
			//cout <<"The index I read from the indexfile is " << index << endl;
			
			ofstream outdexfile("index" + filename);
			
			//cout << "I made it past opening the the streams " << endl;
			
			
			
			g.updateSize(filename);
			
			
			if(g.getIndex() > g.getSize())
			{
				g.setIndex(1);
			}

			//cout << "I read the file and I see it has " << g.getSize() <<" entries" << endl;
			
			while(getline(readfile, quote))
			{
				indexloc++;
				if(indexloc == g.getIndex())
				{
					cout << quote << endl;
				}
					
			}
			
			
			if(g.getSize() == 0)
			{
				//cout <<"Error: There are no quotes in this file" << endl;
				return EXIT_FAILURE;
			}
			
			else
			{
				g.setIndex(g.getIndex() + 1);
				outdexfile << g.getIndex() << endl;
			}
			
			//cout <<"The next index is: "<< g.getIndex() <<endl;
			readfile.close();
			
			outdexfile.close();
			
			return EXIT_SUCCESS;
		}
	}
	
	for(int i = 1; argc > i; i++) //First we will check for the presence of any of possible commands
	{
		if((string)argv[i] == "-f")
		{
			fFound = true;
			//cout <<"Found command -f" << endl;
		}
		
		if((string)argv[i] == "-r")
		{
			rFound = true;
			//cout <<"Found command -r" << endl;
		}
		
		if((string)argv[i] == "-a")
		{
			aFound = true;
			//cout <<"Found command -a" << endl; 
		}
	}
	
	while(counter < argc)
	{
		if(argc >= 8) //if there are too many arguments
		{
			//cout << "Error! Invalid amount of arguments" << endl;
			return EXIT_FAILURE;
		}
		
		else if(argc >= 2 && rFound == true && rCommand == 0 && (string)argv[counter] == "-r") //All the protections and run cases for the -r command
		{
			//cout << "Command was -r" << endl;
			if(counter == temp)
			{
				//cout << "Error! Missing quote or file name following respective command. " << endl;
				g.setStatus(EXIT_FAILURE);
				return EXIT_FAILURE;
			}
			
			if((string)argv[counter + 1] == "-a" || (string)argv[counter + 1] == "-f")
			{
				//cout << "Error! Missing quote or file name following respective command. " << endl;
				g.setStatus(EXIT_FAILURE);
				return EXIT_FAILURE;
			}
			
			
			if(fFound == true && fCommand == 0)
			{
				g.setRemoveQuote((string)argv[counter + 1]);
				//cout <<"I will be removing the following: " << g.returnRemoveQuote() << endl;
			}
			
			if(fFound == false)
			{
				g.setRemoveQuote((string)argv[counter + 1]);
				g.removeQuote(g.getFileName());
			}
			
			if(fFound == true && fCommand == 1 && aCommand == 0)
			{
				g.setRemoveQuote((string)argv[counter + 1]);
				g.removeQuote(g.getFileName());
			}
			
			if(fCommand == 1 && aCommand == 1 && aFound ==  true && fFound == true)
			{
				g.setRemoveQuote((string)argv[counter + 1]);
				g.removeQuote(g.getFileName());
			}
			
			
			rCommand = 1;
		}
		
		else if(argc >= 2 && aFound == true && aCommand == 0 && (string)argv[counter] == "-a") //All the protections and run cases for the -a command
		{
			//cout << "Command was -a" << endl;
			
			if(fFound == true && fCommand == 0)
			{
				g.setAddQuote((string)argv[counter + 1]);
				//cout <<"I will be adding in the following: " << g.returnQuote() << endl;
			}
			
			if(fFound == false)
			{
				g.setAddQuote((string)argv[counter + 1]);
				g.addNewQuote(g.getFileName());
			}
			
			if(fFound == true && fCommand == 1 && rCommand == 0)
			{
				g.setAddQuote((string)argv[counter + 1]);
				g.addNewQuote(g.getFileName());
			}
			
			if(fCommand == 1 && rCommand == 1 && fFound == true && rFound == true)
			{
				g.setAddQuote((string)argv[counter + 1]);
				g.addNewQuote(g.getFileName());
			}
			
			if(counter == temp)
			{
				//cout << "Error! Missing quote or file name following respective command. " << endl;
				g.setStatus(EXIT_FAILURE);
				return EXIT_FAILURE;
			}
			
			if((string)argv[counter + 1] == "-f" || (string)argv[counter + 1] == "-r")
			{
				//cout << "Error! Missing quote or file name following respective command. " << endl;
				g.setStatus(EXIT_FAILURE);
				return EXIT_FAILURE;
			}
			
				aCommand = 1;
		}
		
		
		
		else if(argc >= 2 && fFound == true && fCommand == 0 && (string)argv[counter] == "-f") //And finally all the protections and run cases for the -f command
		{
			//cout <<"Command was -f" <<endl;
			
			if(counter == temp)
			{
				//cout << "Error! Missing quote or file name following respective command. " << endl;
				g.setStatus(EXIT_FAILURE);
				return EXIT_FAILURE;
			}

			if((string)argv[counter + 1] == "-a" || (string)argv[counter + 1] == "-r")
			{
				//cout << "Error! Missing quote or file name following respective command. " << endl;
				g.setStatus(EXIT_FAILURE);
				return EXIT_FAILURE;
			}
			
			if(argc == 3)//For when the user wants to generate a quote from a desired text file rather than the default file.
			{
				g.addFileName((string)argv[counter + 1]);
				
				if(in.is_open() == false)
				{
					cout<<"Error! The file you're trying to retrieve a quote from is either empty or does not exist." <<endl;
					//g.setStatus(EXIT_FAILURE);
					return EXIT_FAILURE;
				}
		
				else
				{
					//cout << "Your text file is now set to: " << g.getFileName() << endl;
					string tempIndex;
					string quote;
					int indexloc = 0;
					string filename = g.getFileName();
					//cout << "Print out first quote from the file "<< filename << endl;
					
					ifstream readfile(filename);
					ifstream indexfile("index" + filename);
					indexfile >> tempIndex;
					indexfile.close();
					
					g.setIndex(stoi(tempIndex));
					
					//cout <<"The index I read from the indexfile is " << index << endl;
					
					ofstream outdexfile("index" + filename);
					
					//cout << "I made it past opening the the streams " << endl;
					
					
					
					g.updateSize(filename); //check the amount of entries again
					
					
					if(g.getIndex() > g.getSize())
					{
						g.setIndex(1);
					}

					//cout << "I read the file and I see it has " << g.getSize() <<" entries" << endl;
					
					while(getline(readfile, quote))
					{
						indexloc++;
						if(indexloc == g.getIndex())
						{
							cout << quote << endl;
						}
							
					}
					
					
					if(g.getSize() == 0)
					{
						//cout <<"Error: There are no quotes in this file" << endl;
						g.setStatus(EXIT_FAILURE);
						return EXIT_FAILURE;
					}
					
					else
					{
						g.setIndex(g.getIndex() + 1);
						outdexfile << g.getIndex() << endl;
					}
					
					//cout <<"The next index is: "<< g.getIndex() <<endl;
					readfile.close();
					
					outdexfile.close();
					
					return EXIT_SUCCESS;
				}
			}
			
			if(aFound == true && rFound == true && aCommand == 1 && rCommand == 1)
			{
				//cout <<"I saw that you wanted to add and remove a quote from a different file" << endl;
				g.addFileName((string)argv[counter + 1]);
				
				g.setRemoveQuote(g.returnRemoveQuote());
				g.removeQuote(g.getFileName());
				
				g.setAddQuote(g.returnQuote());
				g.addNewQuote( g.getFileName());
				
				
				
				g.updateSize(g.getFileName());
				//cout <<" The size of your textfile is: " << g.getSize() << endl;
				
				return EXIT_SUCCESS;
			}
			
			else if(aFound == true && rFound == false && aCommand == 1 && rCommand == 0)
			{
				//cout <<"I saw that you wanted to add a quote into a different file" << endl;
				g.addFileName((string)argv[counter + 1]);
				g.addNewQuote(g.getFileName());
				
			}
			
			else if(aFound == true && rFound == true && aCommand == 1 && rCommand == 0)
			{
				//cout <<"I saw that you wanted to add a quote into a different file" << endl;
				g.addFileName((string)argv[counter + 1]);
				g.addNewQuote(g.getFileName());
				
			}
			
			else if(rFound == true && aFound == false && rCommand == 1 && aCommand == 0)
			{
				//cout <<"I saw that you wanted to remove a quote from a different file" << endl;
				g.addFileName((string)argv[counter + 1]);
				g.removeQuote(g.getFileName());
				
			}
			
			else if(rFound == true && aFound == true && rCommand == 1 && aCommand == 0)
			{
				//cout <<"I saw that you wanted to remove a quote from a different file" << endl;
				g.addFileName((string)argv[counter + 1]);
				g.removeQuote(g.getFileName());
				
			}
			
			else
			{
				g.addFileName((string)argv[counter + 1]);
			}
			
			fCommand = 1;
		}
		
		else
		{
			//cout << "Error! You can only have one -a, -f, -r per command." << endl;
			g.setStatus(EXIT_FAILURE);
			return EXIT_FAILURE;
		}
		
		counter = counter + 2;
	}
	

    //cout << "Your text file is now set to: " << g.getFileName() << endl;
	//g.updateSize(g.getFileName());
	//cout <<" The size of your textfile is: " << g.getSize() << endl;
	in.close();
	
	if(g.getStatus() == EXIT_FAILURE)
	{
		//cout << "The test has failed" << endl;
		return EXIT_FAILURE;
	}
}

