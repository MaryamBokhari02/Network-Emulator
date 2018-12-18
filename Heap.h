#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include"Array.h"

using namespace std;

struct Message {
	int msgid;
	int priority;
	string scr;
	string dest;
	string message;
	string trace;

	Message()
	{
		msgid = -1;
		priority = -1; 
		scr = " "; 
		dest = " "; 
		message = " "; 
		trace = " "; 
	}
};
class Heap
{
		Array <Message> msg;

public:
	Heap();
	void Insert(Message new_ ) {
		msg.Arrgrow(new_); 
		Populateup(); 
	}

	int getparent(int child)
	{
		return child / 2; 
	}
	void Populateup( )
	{
		int child = msg.size;
		child--;
		int parent = getparent(child);

		while (msg[child].priority < msg[parent].priority && child>0 && parent>0 )
			{
			swap(child, parent); 
			child = parent; 
			parent = getparent(child); 
			}
	
	}
	int Heapsize()
	{
		return msg.size - 1; 
	}
	void PopHeapElement()
	{
		msg.Arrpop(); 

	}
	void Delete()
	{
		// First we will pop the last element of the array 
		int child = Heapsize(); 
		int beforeroot = msg[child].priority; 
		swap(child , 1);
		PopHeapElement(); 

		PercolateDown(1); 

		cout << "Deleted: " << beforeroot << endl; 
		cout << "Next Proccess:" << msg[1].priority << endl; 
		cout << "Now Displaying updated Heap " << endl; 
		DisplayHeap(); 
	}
	int getleftchild(int p)
	{
		return (p * 2); 
	}
	int getrightchild(int p)
	{
		return (p * 2 + 1); 
	}
	int Findmin(int leftnode, int rightnode, int &min)
	{
		if (rightnode <= Heapsize())
		{
			if (msg[leftnode].priority < msg[rightnode].priority)
			{
				min = leftnode;
				return msg[leftnode].priority;
			}
			else
			{
				min = rightnode;
				return msg[rightnode].priority;
			}
		}
		else
		{
			min = leftnode; 
			return msg[leftnode].priority; 
		}
		
	}
	int minChild(int parent)
	{
		if (getrightchild(parent) >= Heapsize())
			return getleftchild(parent); 
		else
		{
			if (msg[getleftchild(parent)].priority < msg[getrightchild(parent)].priority)
				return getleftchild(parent);
			else
				return getrightchild(parent); 
		}
	}
	void PercolateDown(int parent )
	{
				while (parent * 2 <= Heapsize())
				{
					int mc = minChild(parent); 
					if (msg[parent].priority > msg[mc].priority)
					{
						swap(parent, mc); 
						parent = mc; 
					}
				}
	}
	void swap(int child, int parent)
	{
		Message temp = msg[child];
		msg[child] = msg[parent];    // msg[k]= msg[k/2];  
		msg[parent]= temp ; 
	}
	void DisplayHeap() {

		for (int i = 1; i < msg.size ; i++)
		{
			cout << msg[i].msgid<<"   "<< msg[i].priority << "   " << msg[i].scr << "   " << msg[i].dest << "   " << msg[i].message<<"   "<<msg[i].trace <<endl;
		}
	}

	~Heap();
};

