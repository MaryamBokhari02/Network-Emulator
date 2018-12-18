#pragma once
#include<iostream>
#include<string>

using namespace std;

struct Route {
	string destinations;
	string nextbest;

};
class BTreeNode
{
	Route *keys;
	int t;	//range of no of keys
	BTreeNode **C;	//array of children
	int n;//current keys
	bool leaf;
public:
	BTreeNode(int _t,bool _leaf);
	void insertNonFull(Route k);
	void splitChild(int i, BTreeNode *y);
	void traverse();
	BTreeNode *search(Route &k);
	string getNextBest();
	friend class BTree;
	~BTreeNode();
};

