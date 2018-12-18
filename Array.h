#pragma once

#include<iostream>
#include<string>
#include<fstream>
using namespace std;
template< class type > class Array
{
	type *A; 

public:
	int size;
	Array() {
		size = 0;
		//A = NULL; 
		//if (typeid(type) != typeid(string))
		//{
		//	A = NULL;
		//}
		//string cannot be null so we not calling it here. 
		//A = NULL; 
	}
	Array(int s) {
		size = s;
		A= new type[s];

	}
	Array(Array* m, int s) {
		//Copy Constructor 
		size = s;
		A = new type[size];
		for (int i = 0; i < size; i++)
		{
			A[i] = m.A[i];
		}
	}
	//return new size of the array. 
	Array copy(const Array& m) {
		size = m.size;
		A = new type[size]; 
		for (int i = 0; i < size; m++)
		{
			A[i] = m.A[i];
		}
	}

	type Arrpop()
	{
		//decreasing the size of the array 
		//loop through
		if (size != 0)
		{
			//make a temporary array of reduced size 
			type m = A[size - 1];
			Array <type>temp(size - 1);
			for (int i = 0; i < size-1; i++)
			{
				temp.A[i] = A[i];
			}
			
			//Delete(); 
			size = size - 1;
			A = new type[size]; 
			for (int i = 0; i < size; i++)
			{
				A[i] = temp.A[i];
			}
			//delete []temp.A; 
			return m;
		} 

	}
	void Arrgrow(type elm) {
		//growing the array 
		//1) Create a constructor, Increase size+1 , Delete the current array , make a copy again 
		if (size != 0)
		{
			Array <type>temp(size);
			for (int i = 0; i < size; i++)
			{
				temp.A[i] = A[i];
			}
			//Delete();
			size = size + 1;
			A = new type[size];
			for (int i = 0; i < size - 1; i++)
			{
				A[i] = temp.A[i];
			}
			A[size - 1] = elm;
			//delete[] temp.A;
		}
		else {
			A = new type[1]; 
			size = 1;
			A[0] = elm; 
		}
		/*
		
		if (size != 0)
		{
			Array temp(*this);
			//temp.size = temp.size + 1;
			//Delete(*this); 
			Delete(); 
			// *this = temp;
			size = temp.size + 1;
			A = new type [size];
			for (int i = 0; i< size - 1; i++)
			{
				A[i] = temp.A[i];
			}
			A[temp.size - 1] = elm;
			//Delete(temp);
		}
		//return *this;
		*/
	}
	void Delete( ) {
		if (A != NULL)
		{
			delete[] A;
		}
		
	}
	bool boolCheck(const int & i) {
		if (i >= 0 && i <= size - 1)
		{
			return true;
		}
		else
		{
			cout << "Index is out of bounds.\n";
			return false;
		}
	}
	void insert(type val, int idx)
	{
		if (boolCheck(idx))
		{
			A[idx]=val;
		}
	
	}
	type operator[](int i) {
		if (boolCheck(i))
		{
			return A[i];
		}

	}
	type getitem(int m)
	{
		return A[m]; 
	}
	void display() {
		for (int i = 0; i < size; i++)
		{
			cout << A[i] << endl;
		}
	}
	~Array() {
	
		
		Delete(); 
	}
};

