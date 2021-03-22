////////////////////////////////////////////////////////
// ECE 3574, Project 2 - starter code for unit tests
//
#define CATCH_CONFIG_MAIN  // Tells Catch to provide a main() function
#include "catch.hpp"
#include "Interpreter.h"

// This 'run' function is a sample only.  You may use it, modify it, or ignore it.
double run(const std::string & program, std::string & output){

  std::istringstream iss(program);
  std::stringstream buffer;
  std::streambuf * old = std::cout.rdbuf(buffer.rdbuf());
  Interpreter interp;
  double result;

  bool ok = interp.compute(iss);
  if(!ok){
    std::cerr << "Failed to parse: " << program << std::endl;
  }
  REQUIRE(ok == true);

  REQUIRE_NOTHROW(result = interp.topStack());

  output = buffer.str();
  std::cout.rdbuf( old );

  return result;
}

TEST_CASE( "Test addition with default precision", "[interpreter]" ) {
 
    std::string program;
	std::string output;
	double result;
	
	program = "3 4 +";
    result = run(program, output);
    REQUIRE(result == 7);
	REQUIRE(output == "");
	
	program = "1 2 3 4 + 5 6 + + + +";
    result = run(program, output);
    REQUIRE(result == 21);
	REQUIRE(output == "");
}

TEST_CASE( "Test simple output cases", "[interpreter]" ) {
 
    std::string program;
	std::string output;
	double result;
	
	program = "3 p";
    result = run(program, output);
    REQUIRE(result == 3);
	REQUIRE(output == "3\n");
	
	program = "4 n";
    result = run(program, output);
    REQUIRE(result == 4);
	REQUIRE(output == "4");
	
	program = "3 p 4 p + p";
    result = run(program, output);
    REQUIRE(result == 7);
	REQUIRE(output == "3\n4\n7\n");
}

TEST_CASE( "Test precision", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 * 2 / n";
    double result = run(program, output);
    REQUIRE(result == 10);
    REQUIRE(output == "10");
  
    program = "1 2 + k c 3 7 * 2 / p";
    result = run(program, output);
    REQUIRE(result == 10.500);
    REQUIRE(output == "10.500\n");
  
}

TEST_CASE( "Test stack length", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 z";
    double result = run(program, output);
    REQUIRE(result == 7);
    REQUIRE(output == "2\n");
  
}

//MY ADDED TESTS/////////////////////////////////////////////

TEST_CASE( "Test reverse command", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 4 5 p r p";
    double result = run(program, output);
    REQUIRE(result == 4);
    REQUIRE(output == "5\n4\n");
  
}

TEST_CASE( "Test duplicate command", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 4 5 f d f";
    double result = run(program, output);
    REQUIRE(result == 5);
    REQUIRE(output == "5\n4\n7\n3\n5\n5\n4\n7\n3\n");
  
}

TEST_CASE( "Test full stack print out command", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 5 6 7 9 10.1 f";
    double result = run(program, output);
    REQUIRE(result == 10);
    REQUIRE(output == "10\n9\n7\n6\n5\n7\n3\n");
  
}

TEST_CASE( "Test pop of stack without output to window", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 P";
    double result = run(program, output);
    REQUIRE(result == 3);
    REQUIRE(output == "");
  
}

TEST_CASE( "Test see current precision command", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 K p 4 k p";
    double result = run(program, output);
    REQUIRE(result == 7);
    REQUIRE(output == "0\n7\n7.0000\n");
  
}

TEST_CASE( "Test number of digits in top value in stack command", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 Z p 3 k 576.72 p Z p";
    double result = run(program, output);
    REQUIRE(result == 6);
    REQUIRE(output == "1\n576.720\n6.000\n");
  
}

TEST_CASE( "Test number of digits in fractional part of top value in stack command", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 X p 3 k 576.72 p X p";
    double result = run(program, output);
    REQUIRE(result == 3);
    REQUIRE(output == "0\n576.720\n3.000\n");
  
}

TEST_CASE( "Test top value print out without new line character command", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 n";
    double result = run(program, output);
    REQUIRE(result == 7);
    REQUIRE(output == "7");
  
}

TEST_CASE( "Test clear stack command", "[interpreter]" ) {
    std::string output;
    std::string program = "3 7 c 1";
    double result = run(program, output);
    REQUIRE(result == 1);
    REQUIRE(output == "");
  
}

TEST_CASE( "Test square root command", "[interpreter]" ) {
    std::string output;
    std::string program = "3 v p 4 v p";
    double result = run(program, output);
    REQUIRE(result == 2);
    REQUIRE(output == "1\n2\n");
  
}

TEST_CASE( "Test exponential command", "[interpreter]" ) {
    std::string output;
    std::string program = "2 4.1 ^ p";
    double result = run(program, output);
    REQUIRE(result == 16);
    REQUIRE(output == "16\n");
  
}

TEST_CASE( "Test subtraction command", "[interpreter]" ) {
    std::string output;
    std::string program = "7 7.5 - p c 5 k 2.350 3.350 - p";
    double result = run(program, output);
    REQUIRE(result == -1);
    REQUIRE(output == "0\n-1.00000\n");
  
}

TEST_CASE( "Test for negative number entry", "[interpreter]" ) {
    std::string output;
    std::string program = "_1 _7 + p";
    double result = run(program, output);
    REQUIRE(result == -8);
    REQUIRE(output == "-8\n");
  
}
