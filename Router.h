#pragma once
#ifndef ROUTER_H
#define ROUTER_H

#include"List.h"
#include "Stree.h"
#include "BTree.h"
#include "BTreeNode.h"
#include<iostream>
#include<string>
using namespace std;

class Router
{
	int count;
	string routername;
	List a;
	Stree S; 
	BTree B; 
	int key; 
public:
	Router();
	Router(string x);
	void setRouterName(string);
	string getRouter();
	void enterdata(string, string);
	string getnextbest(string destination); 
	void setkey(int); 
	int getkey(); 
	void printrouterdetail(); 

	~Router();
};


#endif // !ROUTER_H