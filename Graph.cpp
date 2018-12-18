#include "Graph.h"






Graph::Graph(string s=" ")
{
	NetworkVertex = s;
	NoOfNesighbourConnections++;
	TotalEdges = 0;
}

Graph::Graph()
{
	NetworkVertex = " ";
	NoOfNesighbourConnections++;
	TotalEdges = 0;
}

Graph::~Graph()
{
}
