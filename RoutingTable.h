#pragma once
#ifndef ROUTINGTABLE_H
#define ROUTINGTABLE_H


#include<iostream>
#include<string>
using namespace std;

class RoutingTable
{
public:
	int x;
	string destiination;
	string nextbest;
	RoutingTable*next;
	RoutingTable();
	RoutingTable(int a);
	~RoutingTable();
};

#endif // !ROUTINGTABLE_H