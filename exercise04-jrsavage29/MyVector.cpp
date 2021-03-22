// ECE 3574, fall 2019
// Exercise 04 starter code
// File name: MyVector.cpp
// MyVector implementation 

#include <cstddef>		

// default constructor
template <class T>
MyVector<T>::MyVector(): m_data(nullptr), m_capacity(0), m_size(0)
{
    // do nothing
}

template <class T>
MyVector<T>::~MyVector()
{
	delete [] m_data;
	m_data = nullptr;
}

template <class T>
MyVector<T>::MyVector(const MyVector& v)
{
	m_capacity = v.m_capacity;
	m_size = v.m_size;
	m_data = new T[m_capacity];
	
	for(int i =0; i < m_size; i++)
	{
		m_data[i] = v.m_data[i];
	}
}

template <class T>
const MyVector<T> &MyVector <T>::operator = (const MyVector& v)
{
	//check for self assignment
	if( this != &v)
	{
		delete [] m_data;
	//copy the regular data
	m_capacity = v.m_capacity;
	m_size = v.m_size;
	//copy the dynamic data
	m_data = new T[m_capacity];
	for (int i = 0; i < m_capacity; i++)
		m_data[i] = v.m_data[i];
	}
	return *this; //dereference to return object not the pointer to the object.
}


template <class T>
int MyVector<T>::size()
{
    return m_size;
}

template <class T>
bool MyVector<T>::empty()
{
	if(m_size == 0)
	{
		return true;
	}
	
	else
	{
		return false;
	}
}

template <class T>
void MyVector<T>::push_back(const T& value)
{
	if(m_capacity == m_size)
	{
		T * temp = m_data; //create temp pointer to old full array
		m_capacity = m_capacity + 1; //add 5 to the capacity
		m_data = new T[m_capacity]; //allocate new array
	
		for(int i = 0; i < m_size; i++)//copy elements from old cramped array into new array
		{
			m_data[i] = temp[i];
		}
	
		delete [] temp;// delete old full array
	
		temp = nullptr;// null out temp
		
		m_data[m_size] = value;
		m_size++;
	}
	
	else
	{
		m_data[m_size] = value;
		m_size++;
	}
	
}

template <class T>
T& MyVector<T>::at(int i)
{
	int lastIndex = m_size-1;
	if(i >= 0 && i <= lastIndex)
	{
		return m_data[i];
	}
	
	else if (m_size == 0)
	{
		std::cerr << "***ERROR: Invalid index! Index is outside of the available locations inside the vector!***\n";
	}
	
	else
	{
		std::cerr << "***ERROR: Invalid index! Index is outside of the available locations inside the vector!***\n";
	}
}

