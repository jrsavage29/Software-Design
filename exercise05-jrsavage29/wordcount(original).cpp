#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::string;
using std::map;
using std::set;
using std::pair;

int main()
{
	string temp;
	ifstream in("mobydick.txt");
	int n = 1;
	map <string, int> wordc;
	
	
	while(!in.fail())//Read the file until fail then store each new word into
	{
		in >> temp;
		for (int i=0; i < temp.length(); i++)
		{
			temp[i] = tolower(temp[i]);
			++wordc[temp];
		}
	}
	
	// Declaring the type of Predicate that accepts 2 pairs and return a bool
	typedef std::function<bool(pair<string, int>, pair<string, int>)> Comparator;
 
	// Defining a lambda function to compare two pairs. It will compare two pairs using second field
	Comparator compFunctor =
			[](pair<string, int> elem1 ,pair<string, int> elem2)
			{
				return elem1.second > elem2.second;
			};
 
	// Declaring a set that will store the pairs using above comparision logic
	std::set<pair<string, int>, Comparator> setOfWords(
			wordc.begin(), wordc.end(), compFunctor);
 
	// Iterate over a set using range base for loop
	// It will display the items in sorted order of values
	for (pair<string, int> element : setOfWords)
	{
		if (n <= 10)
		{
			
			cout << n <<". " << element.first << " : " << element.second << " times" << endl;
			n++;
			
		}
		
		else
		{
			return 0;
		}
	}
 
	return 0;
	
	/*for(map <string, int> ::iterator k = wordc.begin(); k != wordc.end(); k++)
	{
		//cout << k->first << " occurred " << k->second << " times.\n";
	}*/
}