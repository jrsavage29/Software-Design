#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "thread_safe_vector.hpp"
#include <thread>
#include <iostream>

ThreadSafeVector<int> safeVector;
int inc = 0;
int popped_value = 0;

void pushing() 
{ 
	for (int i = 0; i < 10; i++) 
	{
		inc++;
		safeVector.push_back(i);
		//std::cout<< i << std::endl;
	}
}	

void increment() 
{ 
	inc++;
	safeVector.push_back(inc);
	//std::cout<< inc << std::endl;
}

void decrement() 
{ 
	inc--;
	safeVector.try_pop_back(popped_value);
	//std::cout<< "Popped: " << popped_value << std::endl;
}		

void decrement_wait() 
{ 
	inc--;
	safeVector.wait_pop_back(popped_value);
	//std::cout<< "Popped: " << popped_value << std::endl;
}		

TEST_CASE( "testing push and try_pop", "[ThreadSafeVector]" ) 
{

	std::thread t1(increment);
	
	std::thread t2(increment);
	
	t1.join();
	t2.join();
	
	REQUIRE(inc == 2);
	
	//The threads are racing each other to get to the CPU first. One 
	//of the threads wins and locks the other thread out.
	//after incrementing the thread that won will unlock the mutex,
	//thus allowing the thread in last place to get the chance to
	//perform incrementing. But get this! The winning thread already
	//incremented the variable and thus the last thread should increment
	//the already incremented variable.
	
	std::thread t3(decrement);
	std::thread t4(decrement);
	
	t3.join();
	t4.join();
	
	REQUIRE(safeVector.empty() == true);
}

TEST_CASE( "testing empty", "[ThreadSafeVector]" ) 
{
	inc = 0;	
	REQUIRE(safeVector.empty());
	
	
	
}


TEST_CASE( "wait_pop", "[ThreadSafeVector]" ) 
{
	//ThreadSafeVector<int> safeVector;
	std::thread t1(decrement_wait);
	std::thread t2(decrement_wait);
	std::thread t3(increment);
	std::thread t4(increment);
	
	t1.join();
	t2.join();
	t3.join();
	
	REQUIRE(safeVector.empty() == true);
	
	t4.join();
	
	REQUIRE(safeVector.empty() == true);
	
	
}
