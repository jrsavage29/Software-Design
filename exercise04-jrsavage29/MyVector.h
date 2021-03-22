// ECE 3574, fall 2019
// Exercise 04 starter code
// File name: MyVector.h
// MyVector specification 

#ifndef MY_VECTOR_
#define MY_VECTOR_

template <class T>
class MyVector 
{
private:
    T *m_data;
    int m_capacity;
    int m_size;
  
public:
    MyVector();
	~MyVector();
	MyVector( const MyVector& v );
	const MyVector& operator=( const MyVector& v );
    int size();
    bool empty();
    void push_back(const T& value);
    T& at(int i);
};

#include "MyVector.cpp"
#endif