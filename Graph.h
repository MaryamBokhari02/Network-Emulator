
#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<string>
using namespace std;


class Graph
{
public:
	string NetworkVertex;
	static int NoOfNesighbourConnections;
	Graph *Edges[100];
	string Points[100];
	int TotalEdges;
	Graph();
	Graph(string);
	~Graph();
};

#endif // !GRAPH_H
