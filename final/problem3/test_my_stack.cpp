#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "my_stack.hpp"
#include <thread>
#include <iostream>

// 	TODO: add your test code here
MyStack safeStack;
int inc = 0;
int temp = 0;

void increment() 
{ 
	inc++;
	
	for (int i = 0; i < 1000; i++) 
	{
		temp++;
		safeStack.push(i);
	}
	
	//std::cout << "The amount of element pushed: " << temp << std::endl;
}	

void decrement() 
{ 
	inc--;
	for (int i = 0; i < 500; i++) 
	{
		safeStack.pop();
	}
}		

TEST_CASE( "testing push and pop", "[MyStack]" ) 
{

	std::thread t1(increment);
	
	std::thread t2(increment);
	
	t1.join();
	t2.join();
	
	REQUIRE(inc == 2);
	
	std::thread t3(decrement);
	std::thread t4(decrement);
	
	t3.join();
	t4.join();
	
	REQUIRE(safeStack.size() == 1000);
}