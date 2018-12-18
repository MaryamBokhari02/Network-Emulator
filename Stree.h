#pragma once
typedef struct tree_node Tree;

#include<iostream>
using namespace std; 
#include<string>
struct tree_node {
	Tree * left, *right;
	string destination;
	string nextbest;
};
class Stree
{
public:
	Tree *root;
	int sizeoftree;
	Stree();
	Tree * splay(string des, Tree * t);
	Tree * insert(string des, string nb, Tree * t);
	string FindNode(string, Tree *&); 
	string getdestination(Tree *t);
	string getnextbest(Tree *t);
	// * deleteit(Route &i, Tree * t); 
	void Preorder_display(Tree * r);

	~Stree();
};

