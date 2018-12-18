#include "Router.h"
#include<iostream>
#include<string>
using namespace std;

Router::Router():B(3)
{
	key = 0;
	routername = " ";
	count = 0;
 
}
Router::Router(string x):B(3)
{
	key = 0;
	routername = x; 
	count = 0;

}
void Router::setRouterName(string x)
{
	routername = x;
}
string Router::getRouter()
{
	return routername;
}
void Router::setkey(int m)
{
	key = m;
}
int Router::getkey() { return key; }
string Router::getnextbest(string ds) {
	//Linear List 
	if (key == 1)
	{
		return a.FindNode(ds); 
	}
	//B Trees 
	else if (key == 2)
	{
		Route x; 
		x.destinations = ds; 
		BTreeNode *m; 
		m=B.search(x);
		return m->getNextBest();
		//return x.nextbest; 
	}
	// Splay Trees 
	else if (key == 3)
	{
		S.root = S.splay(ds, S.root); 
		return S.getnextbest(S.root); 
		//return S.FindNode(ds, S.root); 
	}
	else
		cout << "No Data Structure currently being used for insertion" << endl;
}
void Router::enterdata(string des, string nexbes)
{
	//Linear List 
	if (key == 1)
	{
		a.InsertNode(count, des, nexbes);
		count++;
	}
	//B Trees 
	else if (key == 2)
	{
		Route m; 
		m.destinations = des; 
		m.nextbest = nexbes; 
		B.insert(m); 
	}
	// Splay Trees 
	else if (key == 3)
	{
		S.root = S.insert(des, nexbes, S.root);
		count++;
	}
	else
		cout << "No Data Structure currently being used for insertion" << endl;

}
void Router::printrouterdetail()
{
	//Linear List 
	if (key == 1)
	{
		a.printroutingtable();
	}
	//B Trees 
	else if (key == 2)
	{
		B.traverse(); 
	}
	// Splay Trees 
	else if (key == 3)
	{
		S.Preorder_display(S.root);
	}
	else
		cout << "No Data Structure currently being used for insertion" << endl;

}

Router::~Router() {}