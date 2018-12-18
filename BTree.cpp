#include "BTree.h"
#include<iostream>
#include<string>
using namespace std;




BTree::BTree(int _t)
{
	root = NULL;
	t = _t;
}

void BTree::traverse()
{
	if (root != NULL) {
		root->traverse();
		 
	}
}

BTreeNode * BTree::search(Route k)
{
	return (root == NULL) ? NULL : root->search(k);
}

void BTree::insert(Route k)
{
	if (root == NULL) {
		root = new BTreeNode(t, true);
		root->keys[0] = k;
		root->n = 1;
	}
	else {
		if (root->n == 2 * t - 1) {
			BTreeNode *s = new BTreeNode(t, false);
			s->C[0] = root;
			s->splitChild(0, root);
			int i = 0;
			if (s->keys[0].destinations.compare(k.destinations) < 0) {
				i++;
			}
			s->C[i]->insertNonFull(k);
			root = s;

		}
		else {
			root->insertNonFull(k);
		}
	}
}

BTree::~BTree()
{
}
		