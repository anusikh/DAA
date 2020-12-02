#include<bits/stdc++.h>
#include<list>
using namespace std;


class Graph
{
	int V;
	list<int> *A;
	void DFS_Util(int s, bool visited[]);
public:
	Graph(int V);
	void add_edge(int u, int v);
	void print();
	void DFS(int s);
};

Graph::Graph(int V)
{
	this->V=V;
	A = new list<int>[V];
}

void Graph::add_edge(int u, int v)
{
	A[u].push_back(v);
}

void Graph::print()
{
	for(int i=0;i<V;i++)
	{
		cout<<"The list at vertex "<<i<<"\n head ";
		for(auto j:A[i])
		{
			cout<<" "<<j;
		}

		cout<<"\n";
	}
}

void Graph::DFS_Util(int s, bool visited[])
{
	visited[s]=true;
	cout<<s<<" ";

	for(auto it=A[s].begin();it!=A[s].end();it++)
	{
		if(!visited[*it])
			DFS_Util(*it, visited);
	}
}

void Graph::DFS(int s)
{
	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}

	DFS_Util(s, visited);
}


int main()
{
	Graph g(10);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(1, 4);
	g.add_edge(2, 4);
	g.add_edge(2, 3);
	g.add_edge(4, 3);
	g.add_edge(4, 0);
	g.add_edge(4, 5);
	g.add_edge(5, 6);
	g.add_edge(6, 3);

	//g.print();

	g.DFS(4);
	return 0;
}