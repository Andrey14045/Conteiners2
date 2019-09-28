#include "Containers.h"
#include <iostream>

using namespace std;
int Container::getSize() const
{
	return 0;
}

int Container::getCapacity() const
{
	return 0;
}

void Container::show() const
{
}

void Container::addCapacity(int n)
{
}

Container::~Container()
{
}

MyArray::MyArray()
{
	ar = new int[0];
}

MyArray::MyArray(int n)
{
	size = n;
	ar = new int[size] {0};
}

MyArray::MyArray(const MyArray& ar)
{
	size = ar.size;
	this->ar = new int[size];
	for (int i = 0; i < size; i++)
		this->ar[i] = ar.ar[i];
}

int MyArray::getSize() const
{
	int el = 0;

	for (int i = 0; i < getCapacity(); i++)
		if (ar[i] != 0)
			el = i + 1;
	return el;
}

int MyArray::getCapacity() const
{
	return size;
}

void MyArray::show() const
{
	for (int i = 0 ; i < getCapacity(); i++)
		cout << " ar[" << i << "] = " << ar[i]<<";";
	cout << endl;
}

void MyArray::addCapacity(int n)
{
	int* temp = new int[size + n];
	for (int i = 0; i < size; i++)
		temp[i] = ar[i];
	for (int i = size; i < size + n; i++)
		temp[i] = 0;
	delete[] ar;
	ar = NULL;
	ar = temp;
	size = size + n;
	
}

int& MyArray::operator[](int index)
{
	try
	{
		if (index < 0 || index > getCapacity())
			throw index - size;
		return ar[index];
	}
	catch (int thr) {
		cout << "Error " << endl;
		return ar[index];
	}

}

MyArray& MyArray::operator=(const MyArray& ar)
{
	if (ar.ar == this->ar)
		return *this;
	delete[]this->ar;
	size = ar.size;
	this->ar = new int[size];
	for (int i = 0; i < size; i++)
		this->ar[i] = ar.ar[i];
	return *this;
}

MyArray::~MyArray()
{
	delete[] ar;
	ar = NULL;
}
