#include<bits/stdc++.h>
#include <list>

using namespace std;

class Graph
{

	int V;
	list<int> *A;

public:
	Graph(int V);
	void add_edge(int u, int v);
	void BFS(int s);
	void print();
};

Graph::Graph(int V)
{
	this->V = V;
	A = new list<int >[V];
}

void Graph::add_edge(int u, int v)
{
	A[u].push_back(v);
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];
	for (int i=0;i<V;i++)
	{
		visited[i]=false;
	}

	list<int> q;

	//list<int >::iterator it;

	visited[s] = true;
	q.push_back(s);

	while(!q.empty())
	{
		s = q.front();
		cout<<s<<" ";
		q.pop_front();

		for(auto it=A[s].begin();it!=A[s].end();it++)
		{
			if(!visited[*it])
			{
				visited[*it] = true;
				q.push_back(*it);
			}

		}

	}
}

void Graph::print()
{
	for(int i=0;i<V;i++)
	{
		cout<<"The list at vertex "<<i<<"\n head";
		for(auto j:A[i])
		{
			cout<<" "<<j;
		}
		cout<<"\n";
	}
}

int main()
{
	Graph g(4);
	g.add_edge(0, 1);
	g.add_edge(0, 2);
	g.add_edge(1, 2);
	g.add_edge(2, 0);
	g.add_edge(2, 3);
	g.add_edge(3, 3);

	//g.print();

	g.BFS(2);
	return 0;
}






























