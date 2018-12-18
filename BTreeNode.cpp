#include "BTreeNode.h"
#include<iostream>
#include<string>
using namespace std;



BTreeNode::BTreeNode(int t1, bool leaf1)
{
	t = t1;
	leaf = leaf1;
	keys = new Route[2 * t - 1];
	C = new BTreeNode *[2 * t];
	n = 0;
}
/*
void BTreeNode::getNextBest(BTreeNode *B)
{
	return 
}
*/
void BTreeNode::insertNonFull(Route k)
{
	int i = n - 1;
	if (leaf == true) {
		while (i >= 0 && keys[i].destinations.compare(k.destinations) > 0 ) {
			keys[i + 1] = keys[i];
			i--;
		}
		keys[i + 1] = k;
		n = n + 1;
	}
	else {
		while (i >= 0 && keys[i].destinations.compare(k.destinations) > 0) {
			i--;
		}

		if (C[i + 1]->n == 2 * t - 1) {
			splitChild(i + 1, C[i + 1]);
			if (keys[i + 1].destinations.compare(k.destinations) < 0) {
				i++;
			}
		}
		C[i + 1]->insertNonFull(k);
	}
}

void BTreeNode::splitChild(int i, BTreeNode * y)
{
	BTreeNode *z = new BTreeNode(y->t, y->leaf);
	z->n = t - 1;

	for (int i = 0; i < t - 1; i++) {
		z->keys[i] = y->keys[i + t];
	}
	if (y->leaf == false)
	{
		for (int j = 0; j < t; j++)
			z->C[j] = y->C[j + t];
	}

	y->n = t - 1;

	for (int j = n; j >= i + 1; j--) {
		C[j + 1] = C[j];
	}
	C[i + 1] = z;
	for (int j = n - 1; j >= i; j--)
		keys[j + 1] = keys[j];

	keys[i] = y->keys[t - 1];

	n = n + 1;

}

void BTreeNode::traverse()
{
	int i;
	for (i = 0; i < n; i++) {
		if (leaf == false) {
			C[i]->traverse();
			cout << endl;
		}
		cout << "Destination: " << keys[i].destinations << "   ";
		cout << "Next Best: " << keys[i].nextbest << endl;
		
	}
	if (leaf == false) {
		C[i]->traverse();
	}

	
}



BTreeNode * BTreeNode::search(Route &k)
{
	int i = 0;
	while (i<n && k.destinations.compare(keys[i].destinations) > 0) {
		i++;
	}
	if (keys[i].destinations == k.destinations) {
		return this;
	}
	if (leaf == true) {
		return nullptr;
	}
	return C[i]->search(k);
	
}

string BTreeNode::getNextBest()
{
	string a = keys[0].nextbest;
	return a;
}

BTreeNode::~BTreeNode()
{
}
