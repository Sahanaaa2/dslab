#include <bits/stdc++.h>
using namespace std;
class Graph 
{
	int V;
	list<int>* adj;
	
	void DFS(int v, bool visited[]);
	public:
		Graph(int V);
		~Graph();
		void addEdge(int v, int w);
		void connectedComponents();
		int NumberOfconnectedComponents();
};

void Graph::connectedComponents()
{
	bool* visited = new bool[V];	
	for (int v = 0; v < V; v++)
	visited[v] = false;
	for (int v = 0; v < V; v++) 
	{
		if (visited[v] == false) 
		{
			DFS(v, visited);
			cout<<"\n";
		}
	}
	delete[] visited;
}
int Graph::NumberOfconnectedComponents()
	{ 
		 void connectedComponents();
		 int count = 0;
		 count = count + 1;
		 return count;
	}
void Graph::DFS(int v, bool visited[])
{
	visited[v] = true;
	cout << v << " ";
	
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	if (!visited[*i])
	DFS(*i, visited);
}
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
Graph::~Graph() 
{ 
	delete[] adj; 
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
	adj[w].push_back(v);
}

int main()
{
	Graph g(6);
	g.addEdge(0,1);
	g.addEdge(2, 5);
	g.addEdge(3, 4);
	cout << "Following are connected components \n";
	g.connectedComponents();cout<<"Number of connected components:";
	cout << g.NumberOfconnectedComponents();
	
}
