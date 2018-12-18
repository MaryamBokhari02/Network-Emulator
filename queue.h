#pragma once
#include<iostream>
using namespace std; 

#include"Heap.h"

//Queue Implementation through Array 

class queue
{
private:
	Array<Message> arr;
	int size;
	int start;
	int end;
	string name; 

public:
	queue(int s = 1)
	{
		size = s;
		start = 0;
		end = arr.size;

	}
	void setQueueName(string x)
	{
		name = x; 
	}
	bool checkforempty()
	{
		if (start == end)
		{
			return true;
		}
		return false;
	}
	void pushdata(Message y)
	{
		arr.Arrgrow(y); 
		end++; 
	}
	Message popdata()
	{
		Message M; 
		if (checkforempty() == false)
		{
			M = arr.getitem(start); 
			start++; 
			return M; 
		}
		else if (checkforempty() == true)
		{
			cout << "Queue value can't be popped"<<endl;
			start = 0;
			end = 0;
			return M; 
		}
		return M; 
	}

};
