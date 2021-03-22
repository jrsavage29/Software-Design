// ECE 3574, Project 4, Fall 2019 - starter code for Catch2 unit tests of VTmath
//
#define CATCH_CONFIG_MAIN  // Tells Catch to provide a main() function
#include "catch.hpp"
#include "VTmath.h"


TEST_CASE( "Test constructors", "[VTmath]" ) 
{
    //std::cout << "Test constructors\n";
	
	VTmath m; // invoke the default constructor
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "0");	
	REQUIRE(m == 0);
	
	// TO-DO: write more tests
}

TEST_CASE( "Test assigning '0'", "[VTmath]" ) 
{
    //std::cout << "Test constructors\n";
	
	VTmath m; // invoke the default constructor
	
	m = "0";
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "0");	
	REQUIRE(m == 0);
	
	m = "";
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "0");	
	REQUIRE(m == 0);
	
	// TO-DO: write more tests
}

TEST_CASE( "Test size", "[VTmath]" ) 
{
    //std::cout << "Test constructors\n";
	
	VTmath m; // invoke the default constructor
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "0");	
	REQUIRE(m == 0);
	
	m = 1; 
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "1");	
	REQUIRE(m == 1);
	
	m = -1; 
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "-1");	
	REQUIRE(m == -1);
	
	m = 0; 
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "0");	
	REQUIRE(m == 0);
	
	m = "_1"; 
	
	REQUIRE(m.size() == 1);
	//REQUIRE(m == "_1");	
	REQUIRE(m == "-1");	
	REQUIRE(m == -1);
	
	m = "1"; 
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "1");	
	REQUIRE(m == 1);
	
	m = "0"; 
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "0");	
	REQUIRE(m == 0);
	
	m ="0934";
	
	REQUIRE(m.size() == 3);
	REQUIRE(m == "934");	
	REQUIRE(m == 934);
	
}


TEST_CASE( "Test assignment", "[VTmath]" ) 
{
	
	VTmath m; // invoke the default constructor
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "0");	
	REQUIRE(m == 0);
	
	m = 0;
	
	REQUIRE(m.size() == 1);
	REQUIRE(m == "0");	
	REQUIRE(m == 0);
	
	// TO-DO: write more tests
}

TEST_CASE( "Test case 1 of addition with small values", "[VTmath]" ) 
{
    //std::cout << "Test addition with small values\n";
	
	VTmath m, n, r;
		
	m = 2;
	n = 3;
	r = m + n;
	REQUIRE(m == 2);
	REQUIRE(n == 3);
	REQUIRE(r == 5);
	
}
	
	
// TO-DO: write more tests
TEST_CASE( "Test case 2 of addition with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -5 ;
	n = 2;
	r = m + n;
	
	REQUIRE(m == -5);
	REQUIRE(n == 2);
	REQUIRE(r == -3);
	
}

TEST_CASE( "Test case 2.5 of addition with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -5 ;
	n = 6;
	r = m + n;
	
	REQUIRE(m == -5);
	REQUIRE(n == 6);
	REQUIRE(r == 1);
	
}

TEST_CASE( "Test case 3 of addition with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 6;
	n = -2;
	r = m + n;
	
	REQUIRE(m == 6);
	REQUIRE(n == -2);
	REQUIRE(r == 4);
	
}

TEST_CASE( "Test case 3.5 of addition with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 6;
	n = -10;
	r = m + n;
	
	REQUIRE(m == 6);
	REQUIRE(n == -10);
	REQUIRE(r == -4);
	
}

TEST_CASE( "Test case 4 of addition with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -25;
	
	VTmath p = m;
	
	n = -6;
	r = m + n;
	
	REQUIRE(m == -25);
	REQUIRE(p == -25);
	REQUIRE(n == -6);
	REQUIRE(r == -31);
	
}

TEST_CASE( "Test case 4.5 of addition with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -25;
	
	VTmath p = m;
	
	n = 25;
	r = m + n;
	
	REQUIRE(m == -25);
	REQUIRE(p == -25);
	REQUIRE(n == 25);
	REQUIRE(r == 0);
	
}


TEST_CASE( "Test case 1 of subtraction with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 100;
	n = 50;
	r = m - n;
	
	REQUIRE(m == 100);
	REQUIRE(n == 50);
	REQUIRE(r == 50);
	
}


TEST_CASE( "Test case 1.5 of subtraction with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 10;
	n = 1000;
	r = m - n;
	
	REQUIRE(m == 10);
	REQUIRE(n == 1000);
	REQUIRE(r == -990);
	
}

TEST_CASE( "Test case 2 of subtraction with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -10;
	n = 1000;
	r = m - n;
	
	REQUIRE(m == -10);
	REQUIRE(n == 1000);
	REQUIRE(r == -1010);
	
}

TEST_CASE( "Test case 2.5 of subtraction with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -1067;
	n = "5";
	r = m - n;
	
	REQUIRE(m == -1067);
	REQUIRE(n == 5);
	REQUIRE(r == -1072);
	
}


TEST_CASE( "Test case 3 of subtraction with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 547;
	n = -72346;
	r = m - n;
	
	REQUIRE(m == 547);
	REQUIRE(n == -72346);
	REQUIRE(r == 72893);
	
}

TEST_CASE( "Test case 3.5 of subtraction with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 123244756;
	n = -518;
	r = m - n;
	
	REQUIRE(m == 123244756);
	REQUIRE(n == -518);
	REQUIRE(r == 123245274);
	
}

TEST_CASE( "Test case 4 of subtraction with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -100000;
	n = -72163484;
	r = m - n;
	
	REQUIRE(m == "-100000");
	REQUIRE(n == "-72163484");
	REQUIRE(r == "72063484");
	
}

TEST_CASE( "Test case 4.5 of subtraction with small values", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -236543786;
	n = -76545;
	r = m - n;
	
	REQUIRE(m == -236543786);
	REQUIRE(n == -76545);
	REQUIRE(r == -236467241);
	
}

TEST_CASE( "Test positive multiplication", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 21546;
	n = 64975;
	r = m * n;
	
	REQUIRE(m == 21546);
	REQUIRE(n == 64975);
	REQUIRE(r == 1399951350);
	
}

TEST_CASE( "Test one negative and one positive multiplication", "[VTmath]" ) 
{
    //std::cout << "Test one negative and one positive multiplication\n";
	
	VTmath m, n, r;
		
	m = -23857;
	n = 2385;
	r = m * n;
	
	REQUIRE(m == -23857);
	REQUIRE(n == 2385);
	REQUIRE(r == -56898945);
	
}

TEST_CASE( "Test both negative multiplication", "[VTmath]" ) 
{
    //std::cout << "Test both negative multiplication\n";
	
	VTmath m, n, r;
		
	m = -4813;
	n = -10246;
	r = m * n;
	
	REQUIRE(m == -4813);
	REQUIRE(n == -10246);
	REQUIRE(r == 49313998);
	
}

TEST_CASE( "Test multiplication times 1", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = "1234567890123456789012345678904567643";
	n = 1;
	r = m * n;
	
	bool rand = true;
	
	if(m == "1234567890123456789012345678904567643")
	{
		rand = false;
	}
	
	REQUIRE(rand == false);
	
	REQUIRE(m == "1234567890123456789012345678904567643");
	REQUIRE(n == 1);
	REQUIRE(r == "1234567890123456789012345678904567643");
	
}

TEST_CASE( "Test multiplication times 0", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 0;
	n = "1234567890123456789012345678904567643";
	r = m * n;
	
	REQUIRE(m == 0);
	REQUIRE(n == "1234567890123456789012345678904567643");
	REQUIRE(r == 0);
	
}


TEST_CASE( "Test positive division", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 46591;
	n = 643;
	r = m / n;
	
	REQUIRE(m == 46591);
	REQUIRE(n == 643);
	REQUIRE(r == 72);
	
}

TEST_CASE( "Test one negative and one positive division", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 721641235;
	n = -49167;
	r = m / n;
	
	REQUIRE(m == 721641235);
	REQUIRE(n == -49167);
	REQUIRE(r == -14677);
	
}

TEST_CASE( "Test both negative division", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -4915267;
	n = -16495;
	r = m / n;
	
	REQUIRE(m == -4915267);
	REQUIRE(n == -16495);
	REQUIRE(r == 297);
	
}

TEST_CASE( "Test divide by 1", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = "192148129482194981249853612948124198405754";
	n = 1;
	r = m / n;
	
	REQUIRE(m == "192148129482194981249853612948124198405754");
	REQUIRE(n == 1);
	REQUIRE(r == "192148129482194981249853612948124198405754");
	
}

TEST_CASE( "Test division by 0", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = "192148129482194981249853612948124198405754";
	n = 0;
	r = m / n;
	
	REQUIRE(m == "192148129482194981249853612948124198405754");
	REQUIRE(n == 0);
	REQUIRE(r == 0);
	
}

TEST_CASE( "Test division with denominator bigger than numerator", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = "192148129482194981249853612948124198";
	n = "192148129482194981249853612948124198405754";
	r = m / n;
	
	REQUIRE(m == "192148129482194981249853612948124198");
	REQUIRE(n == "192148129482194981249853612948124198405754");
	REQUIRE(r == "0");
	
}

TEST_CASE( "Test positive exponentiation", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 2;
	n = 32;
	r = m ^ n;
	
	REQUIRE(m == 2);
	REQUIRE(n == "32");
	REQUIRE(r == "4294967296");
	
}

TEST_CASE( "Test negative exponentiation", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = -79;
	n = 5;
	r = m ^ n;
	
	REQUIRE(m == -79);
	REQUIRE(n == 5);
	REQUIRE(r == "-3077056399");
	
}

TEST_CASE( "Test exponentiation with exponent 0", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = "-3077056399";
	n = 0;
	r = m ^ n;
	
	REQUIRE(m == "-3077056399");
	REQUIRE(n == 0);
	REQUIRE(r == 1);
	
}

TEST_CASE( "Test exponentiation with exponent 1", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = "-124721748581371";
	n = 1;
	r = m ^ n;
	
	REQUIRE(m == "-124721748581371");
	REQUIRE(n == 1);
	REQUIRE(r == "-124721748581371");
	
}

TEST_CASE( "Test exponentiation with 0^0", "[VTmath]" ) 
{
    //std::cout << "Test \n";
	
	VTmath m, n, r;
		
	m = 0;
	n = 0;
	r = m ^ n;
	
	REQUIRE(m == 0);
	REQUIRE(n == 0);
	REQUIRE(r == 0);
	
}

