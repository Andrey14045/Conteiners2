#include "MyVector.h"
#include <iostream>
using namespace std;
MyVector::MyVector() :MyArray(), capacity(0)
{
	size = 0;
}

MyVector::MyVector(int n) : MyArray(n), capacity(n)
{
	size = 0;
}

MyVector::MyVector(int n, int value) : capacity(n)
{
	ar = new int[capacity];
	for (int i = 0; i < capacity; i++)
	{
		ar[i] = value;
	}
	size = capacity;
}

MyVector::MyVector(const MyVector& vec) :MyArray(vec.capacity)
{
	capacity = vec.capacity;
	size = vec.getSize();
	for (int i = 0; i < size; i++)
	{
		ar[i] = vec.ar[i];
	}
}

int MyVector::getCapacity() const
{
	return this->capacity;
}

void MyVector::addCapacity(int n)
{
	size = getSize();
	int* temp = new int[capacity + n];
	for (int i = 0; i < size; i++)
		temp[i] = ar[i];
	for (int i = size; i < capacity + n; i++)
		temp[i] = 0;
	delete[] ar;
	ar = temp;
	capacity += n;
	
}

void MyVector::pushBack(int val)
{
	size = getSize();

	if (size < capacity)
		ar[size++] = val;
	else {
		int* temp;
		
		temp = new int[capacity+1] {0};
		for (int i = 0; i < size; i++)
			temp[i] = ar[i];
		temp[capacity - 1] = val;
		delete[] ar;
		ar = NULL;
		capacity += 1;
		ar = temp;


	}

}

int MyVector::popBack()
{
	size = getSize();
	int temp = ar[size - 1];
	ar[size - 1] = 0;
	size--;
	return temp;
}





void MyVector::insert(int index, int val)
{
	size = getSize();
	if (index == 0)
	{
		if (size < capacity) size++;
		else capacity = size++;
		int* temp;
		temp = new int[capacity] {0};
		for (int i = 1; i < size; i++)
			temp[i] = ar[i];
		temp[0] = val;
		delete[] ar;
		ar = NULL;
		ar = temp;
	}
	else {
		if (index == (size + 1))
			pushBack(val);
		else {
			if (size < capacity) size++;
			else capacity = size++;
			int* temp;
			temp = new int[capacity] {0};
			for (int i = 0; i < index; i++)
				temp[i] = ar[i];
			temp[index] = val;
			for (int j = index + 1; j < size; j++)
				temp[j] = ar[j - 1];
			delete[] ar;
			ar = NULL;
			ar = temp;
		}
	}

}

int MyVector::remove(int index)
{
	size = getSize();
	int temp = ar[index];
	for (int i = index; i < size; i++) {
		ar[i] = ar[i + 1];
	}
	ar[size - 1] = 0;
	return temp;
}

MyVector& MyVector::operator=(const MyVector& vec)
{
	if (this == &vec)
		return *this;
	delete[]ar;
	size = vec.size;
	
	ar = new int[capacity+1];
	for (int i = 0; i < size; i++)
		ar[i] = vec.ar[i];
	capacity = vec.capacity+1;
	return *this;
}


