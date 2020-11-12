#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
	list<int> *A;
	void topoutil(int v, bool *visited, stack<int> &st);
public:
	Graph(int V);
	void add_edge(int u, int v);
	void topo();
};


Graph::Graph(int V)
{
	this->V = V;
	A = new list<int>[V];
}

void Graph::add_edge(int u, int v)
{
	A[u].push_back(v);
}

void Graph::topoutil(int v, bool *visited, stack<int> &st)
{
	visited[v] = true;

	for(auto it = A[v].begin();it!=A[v].end(); it++)
	{
		if(visited[*it]==false)
			topoutil(*it, visited, st);
	}

	st.push(v);
}

void Graph::topo()
{
	stack<int> st;

	bool *visited = new bool[V];
	for(int i=0;i<V;i++)
	{
		visited[i]=false;
	}

	for(int i=0;i<V;i++)
	{
		if(visited[i]==false)
			topoutil(i, visited, st);
	}

	while(!st.empty())
	{
		cout<< st.top()<<" ";
		st.pop();
	}
}


int main()
{
	Graph g(6);
	g.add_edge(5, 2); 
    g.add_edge(5, 0); 
    g.add_edge(4, 0); 
    g.add_edge(4, 1); 
    g.add_edge(2, 3); 
    g.add_edge(3, 1); 
    g.topo();
    return 0;
}
