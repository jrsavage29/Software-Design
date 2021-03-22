// ECE 3574, fall 2019
// Exercise 04 starter code
// File name: MyVector.cpp
// MyVector implementation 

#include <cstddef>		

// default constructor
template <class T>
MyVector<T>::MyVector()
    : m_data(nullptr), m_capacity(0), m_size(0)
{
    // do nothing
}

template <class T>
int MyVector<T>::size()
{
	// TO DO:  implement this method
    return 0;
}

template <class T>
bool MyVector<T>::empty()
{
	// TO DO:  implement this method
    return true;
}

template <class T>
void MyVector<T>::push_back(const T& value)
{
	// TO DO:  implement this method
}

template <class T>
T& MyVector<T>::at(int i)
{
	// TO DO:  implement this method
    return m_data[0];
}

