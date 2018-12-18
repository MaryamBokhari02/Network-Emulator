#include "Stree.h"

Stree::Stree()
{
	sizeoftree = 0;
	root = NULL;
}
Tree * Stree::splay(string i, Tree * t) {
	/* Simple top down splay, not requiring i to be in the tree t.  */
	/* What it does is described above.                             */
	Tree N, *l, *r, *y;
	if (t == NULL) return t;
	N.left = N.right = NULL;
	l = r = &N;

	for (;;) {
		if (i.compare(t->destination) < 0) {
			if (t->left == NULL) break;
			if (i.compare(t->destination) < 0) {
				y = t->left;                           /* rotate right */
				t->left = y->right;
				y->right = t;
				t = y;
				if (t->left == NULL) break;
			}
			r->left = t;                               /* link right */
			r = t;
			t = t->left;
		}
		else if (i.compare(t->destination) > 0) {
			if (t->right == NULL) break;
			if (i.compare(t->destination) > 0) {
				y = t->right;                          /* rotate left */
				t->right = y->left;
				y->left = t;
				t = y;
				if (t->right == NULL) break;
			}
			l->right = t;                              /* link left */
			l = t;
			t = t->right;
		}
		else {
			break;
		}
	}
	l->right = t->left;                                /* assemble */
	r->left = t->right;
	t->left = N.right;
	t->right = N.left;
	return t;
}
string Stree::FindNode(string des, Tree *&t)
{
	t = splay(des, t);
	if (t->destination.compare(des) == 0)
	{
		return t->nextbest;
	}

	else if (t->right != NULL)
	{
		t = t->right; 
		return t->nextbest; 
	}
	else if (t->left!=NULL)
	{
		t = t->left; 
		return t->nextbest; 
	}
	else
		return " "; 
}
string Stree::getdestination(Tree *t)
{
	return t->destination; 
}
string Stree::getnextbest(Tree *t)
{
	return t->nextbest; 
}
Tree * Stree::insert(string des, string nb, Tree * t) {
	/* Insert i into the tree t, unless it's already there.    */
	/* Return a pointer to the resulting tree.                 */
	Tree * neww;

	neww = new Tree[200];
	/*
	neww = (Tree *)malloc(sizeof(Tree));
	if (neww == NULL) {
	printf("Ran out of space\n");
	exit(1);
	}
	*/

	neww->destination = des;
	neww->nextbest = nb;
	if (t == NULL) {
		neww->left = neww->right = NULL;
		sizeoftree = 1;
		return neww;
	}

	t = splay(des, t);
	if (neww->destination.compare(t->destination) < 0) {
		neww->left = t->left;
		neww->right = t;
		t->left = NULL;
		sizeoftree++;
		return neww;
	}
	else if (neww->destination.compare(t->destination) > 0) {
		neww->right = t->right;
		neww->left = t;
		t->right = NULL;
		sizeoftree++;
		return neww;
	}
	else { /* We get here if it's already in the tree */
		   /* Don't add it again                      */
		free(neww);
		return t;
	}
}

void Stree::Preorder_display(Tree * r)
{
	if (r == NULL)
	{
		return;
	}
	cout << "Destination:" << r->destination << "       Next Best: " << r->nextbest << endl;
	Preorder_display(r->left);
	Preorder_display(r->right);

}


Stree::~Stree()
{
}