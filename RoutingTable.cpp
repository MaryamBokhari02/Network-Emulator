#include "RoutingTable.h"
#include<iostream>
#include<string>
using namespace std;





RoutingTable::RoutingTable()
{
	x = 0;
	next = 0;
	destiination = " "; 
	nextbest = " "; 
}

RoutingTable::RoutingTable(int a=0)
{
	x = a;
	next = 0;
	destiination = " ";
	nextbest = " ";
}

RoutingTable::~RoutingTable()
{
}
