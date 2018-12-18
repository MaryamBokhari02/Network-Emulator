#include<iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <iomanip> 
#include"Graph.h"
#include"List.h"
#include"Router.h"
#include"RoutingTable.h"
#include"Stree.h"
#include"Heap.h"
#include"queue.h"
#include "RT.h"

using namespace std;

int coco = 0;
int col = 0;


int Graph::NoOfNesighbourConnections = -1;


void GraphConstruction(Graph N[]) {
	for (int i = 0; i <= N[0].NoOfNesighbourConnections; i++)
	{
		for (int j = 0; j <= N[0].NoOfNesighbourConnections; j++)
		{
			if (N[i].Points[j] != "?")
			{
				N[i].Edges[N[i].TotalEdges] = &N[j];
				N[i].TotalEdges++;
			}
		}
	}
}


int minDistanceance(int *Distance, bool *ShortestPath, int V)
{
	int min = 100000;
	int min_index = 0;

	for (int v = 0; v < V; v++)
	{
		if (ShortestPath[v] == false && Distance[v] <= min)
		{
			min = Distance[v]; min_index = v;
		}
	}
	return min_index;
}
void populatenode(Router *a, string nxt, string des, int coco)
{
	a[coco].enterdata(des, nxt);
	coco++;
}

void SourceToDestinationPath(int* parent, int j, Router* Verta, string *&p)
{
	if (parent[j] == -1)
		return;
	//cout << Verta[j].getRouter() << " ";
	p[col] = Verta[j].getRouter();
	col++;
	SourceToDestinationPath(parent, parent[j], Verta, p);
}
void displaysol(int *Distance, int n, int *parent, Router *NetworkVertex, int des, int src, int* arr)
{
	col = 0;
	string *path = new string[10];
	for (int i = 0; i < n; i++)
	{
		if (src == i)
		{

			//cout << endl << "Verex:" << NetworkVertex[i].getRouter() << "-->" << NetworkVertex[des].getRouter() << "    Distence : " << Distance[i] << " Length.     Path : ";
			SourceToDestinationPath(parent, i, NetworkVertex, path);
			path[col] = NetworkVertex[des].getRouter();
			//cout << path[col] << " ";
			populatenode(NetworkVertex, path[1], NetworkVertex[des].getRouter(), i);
			//sum = 0;
		}
	}
}

void dijkstra(int V, int **graph, int des, int src, Router* NVertax, int *arr)
{
	int *Distance = new int[V];
	bool *ShortestPath = new bool[V];
	int *parent = new int[V];
	for (int i = 0; i < V; i++)
	{
		parent[i] = -1;
		Distance[i] = 10000;
		ShortestPath[i] = false;
	}
	Distance[des] = 0;

	for (int count = 0; count < V - 1; count++)
	{
		int u = minDistanceance(Distance, ShortestPath, V);
		ShortestPath[u] = true;
		for (int v = 0; v < V; v++)

			if (!ShortestPath[v] && graph[u][v] && Distance[u] != 10000 && Distance[u] + graph[u][v] < Distance[v])
			{
				parent[v] = u;
				Distance[v] = Distance[u] + graph[u][v];
			}
	}
	/*for (int x = 0; x < V; x++)
	{
	cout << parent[x] << " " << ShortestPath[x] << " " << Distance[x] << endl;
	}*/
	displaysol(Distance, V, parent, NVertax, des, src, arr);
}
void Directpathprinting(int size, int **graph, Router *all, int * arr)
{
	int c, z, x, y;
	do
	{
		cout << "\nEnter:\n1 for Shortest Path Between two Selected Moniters\n3 for EXIT ";
		cin >> c;
		system("cls");
		switch (c)
		{
		case '1':
			do
			{
				cout << "\nEnter :\n1 for Shortest Path\n2 for EXIT ";
				cin >> z;
				system("cls");
				switch (z)
				{
				case '1':
					cout << "\nSelect Source moniter:\n1 For M1\n2 for M2\n3 for M3\n4 for M4\n5 for M5\n6 for M6\n7 for M7\n8 for M8\n9 for M9\n10 for M10\n11 for M11\n12 for M12\n13 for M13\n14 for M14\n15 for M15";
					cin >> x;
					system("cls");
					cout << "\nSelect Destination moniter:\n1 For M1\n2 for M2\n3 for M3\n4 for M4\n5 for M5\n6 for M6\n7 for M7\n8 for M8\n9 for M9\n10 for M10\n11 for M11\n12 for M12\n13 for M13\n14 for M14\n15 for M15";
					cin >> y;
					system("cls");
					if (x <= size - 5 && y <= size - 5)
					{
						cout << "\nShortest Path\n";
						dijkstra(size, graph, y - 1, x - 1, all, arr);
					}
					else
					{
						cout << "Wrong input . ";
						goto def;
					}
					break;
				case '2':
				def:
					break;
				default:
					cout << "\nWrpng Option Entered. Try Again";
					break;
				}
			} while (z != 3);

			break;
		case '3':
			break;
		default:
			cout << "\nYou Entered Wrong Option. Retry!";
		}
	} while (c != '3');
}
int FileReading(string *&Vertaces, int **&graph, int *&arr) {
	ifstream myfile("network.csv");
	if (myfile.good())
	{
		int number_of_lines = 0;
		string line = "";
		while (getline(myfile, line))
			++number_of_lines;
		myfile.close();
		int size = number_of_lines - 1;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = '?';
			//	cout << arr[i];
		}
		Vertaces = new string[size];
		graph = new int*[size];
		string **array = new string*[size];
		for (int i = 0; i < size; i++)
		{
			graph[i] = new int[size];
			array[i] = new string[size];
		}

		ifstream read;
		read.open("network.csv");
		getline(read, line);
		for (int i = 0; i < size; i++)
		{
			getline(read, Vertaces[i], ',');
			for (int j = 0; j < size; j++)
			{
				if (j == size - 1)
				{
					getline(read, array[i][j]);
					break;
				}
				getline(read, array[i][j], ',');
			}
		}
		read.close();
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				graph[i][j] = atoi(array[i][j].c_str());
				//cout << graph[i][j];
			}
			//cout << endl;
		}
		return size;
	}
	else
	{
		cout << "File not opened Correctly " << endl;
		return 0; 
	}

}
int main()
{
	//RT systems; 
	string *Vertaces; 
	int ** graph; 
	int *arr; 
	int size=FileReading(Vertaces, graph, arr ); 
		string *monitors = new string[0];
		string *router = new string[0];
		int numOfMonitors = 0;
		int numOfRouters = 0;
		for (int a = 0; a < size; a++)
		{

			if (Vertaces[a][0] == 'M')
			{
				string *temp = new string[a + 1];
				for (int x = 0; x <= numOfMonitors; x++)
				{
					temp[x] = Vertaces[x];

				}
				numOfMonitors++;
				//numOfRouters = numOfMonitors;
				delete[] monitors;

				monitors = new string[a + 1];
				for (int i = 0; i < numOfMonitors; i++) {
					monitors[i] = temp[i];
				}
				delete[]temp;
			}

		}
		numOfRouters = 0;
		for (int a = 0; a < size; a++)
		{

			if (Vertaces[a][0] == 'R')
			{
				string *temp1 = new string[a + 1];
				for (int x = 0; x <= numOfRouters; x++)
				{
					temp1[x] = Vertaces[a - x];

				}
				numOfRouters++;
				//numOfRouters = numOfMonitors;
				delete[] router;

				router = new string[a + 1];
				int temp = numOfRouters;
				for (int i = 0; i <= numOfRouters; i++) {
					router[i] = temp1[temp];
					temp--;
					//cout << temp1[i];
				}
				delete[]temp1;
			}
		}
		cout << endl;
		int x = 0;
		int priority;
		int y = 0;
		char z;
		string s;
		Graph *N = new Graph[size];
		int max = -1;
		int max_index = 0;
		char c;
		GraphConstruction(N);
		cout << "\nGraph Constructed!" << endl;
		//Here we will be selecting the Data Structure we want to implement
		cout << "Welcome to construction of Routers " << endl;
		cout << "Enter 1: Linear List " << endl;
		cout << "Enter 2: B Trees  " << endl;
		cout << "Enter 3: Splay Trees " << endl;
		int key;
		cin >> key;
		//RT *final;
		//final = new RT[numOfRouters];
		Router * all = new Router[size];
		for (int i = numOfMonitors; i < size; i++)
		{
		//	final[i].setRouter(all[i]);
		}
		for (x = 0; x < size; x++)
		{
			all[x].setRouterName(Vertaces[x]);
			all[x].setkey(key);

		}
		for (x = 1; x <= size; x++)
		{
			for (int y = 1; y <= size - numOfRouters; y++)
			{
				dijkstra(size, graph, y - 1, x - 1, all, arr);
			}
		}
		// Here we print out the details of the router 
		//cout << all[16].getRouter() << endl;
		//all[16].printrouterdetail();
		
		/* 
		for (int j = 0; j < size; j++)
		{
			all[j].printrouterdetail(); 
			cout << endl; 
		}
		*/
		cout << "All The router are ready : \n";
		//Creating Messages Class here 
		ifstream file;
		Message M;
		cout << "----------Welcome to Network Emulator---------" << endl;
		cout << "Press 1: Enter the messages using file" << endl;
		cout << "Press 2: Enter the messages using command line" << endl;
		cin >> x;
		string msg, pri;
		//cout << M.dest; 
		if (x == 1)
		{
			string filename;
			cout << " Please Enter File name: " << endl;
			cin >> filename;
			file.open(filename, ios::out);
			if (file.is_open())
			{
				while (file.eof() == false)
				{
					getline(file, msg, ',');
					stringstream g(msg);
					g >> M.msgid;
					getline(file, pri, ',');
					stringstream h(pri);
					h >> M.priority;
					getline(file, M.scr, ',');
					getline(file, M.dest, ',');
					getline(file, M.message, ',');
					getline(file, M.trace, '\n');
					//systems.SendMessage(M);
					for (int i = 0; i < numOfMonitors; i++)
					{
						if (M.scr.compare(all[i].getRouter()) == 0 )   
						{
							cout << "Router Name" << endl; 
							cout<< all[i].getRouter(); 
							cout << endl;  
							cout << "Message Next Best:: "<<all[i].getnextbest(M.dest) << endl;
							all[i].printrouterdetail();
						}
					}
				}
			}
			else
			{
				cout << "File does not exist with the current name " << endl;
			}
		}
		else if (x == 2)
		{
			int m = x;
			while (m == x)
			{
				//Getting message through Command line from user  
				cout << "Enter the Message id" << endl;
				cin >> M.msgid;
				cout << "Enter the priority of the message" << endl;
				cin >> M.priority;
				cout << "Enter the source of the message" << endl;
				cin >> M.scr;
				cout << "Enter the Destination of the message" << endl;
				cin >> M.dest;
				cout << "Enter the message of the message" << endl;
				cin >> M.message;
				//systems.SendMessage(M);
				cout << "Press 2: Input another message else Press 3" << endl;
				cin >> m;

			}
		}
		
		cout << "THANK YOU FOR USING OUR NETWORK EMULATOR" << endl; 
	system("pause");

	return 0;
}