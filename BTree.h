#pragma once
#include<iostream>
using namespace std;
#include "BTreeNode.h"
#include<string>

class BTree
{
	BTreeNode *root;
	int t;	//minimum degree of b-tree
public:
	BTree(int _t);
	void traverse();
	BTreeNode *search(Route k);
	void insert(Route k);
	~BTree();
};

