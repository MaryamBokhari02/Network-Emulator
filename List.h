#pragma once
#ifndef LIST_H
#define LIST_H


#include<iostream>
using namespace std;
#include<string>
#include "RoutingTable.h"
class List
{
	RoutingTable*head;
	RoutingTable*tail;

public:
	List();
	void insertatstart(string val, string val2);
	RoutingTable* InsertNode(int pos, string val3, string val4);
	string FindNode(string des); 
	void printroutingtable(); 
	~List();
};

#endif // !LIST_H