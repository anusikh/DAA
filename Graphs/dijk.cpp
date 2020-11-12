//Time complexity of this algo is O(ElogV)
//Short

#include<bits/stdc++.h>
#define INF 32767
using namespace std;

typedef pair<int, int> iPair;

class Graph
{
	int V;
	list<iPair> *A;
public:
	Graph(int V);
	void add_edge(int u, int v, int w);
	void dijkstra(int s);
};

Graph::Graph(int V)
{
	this->V=V;
	A = new list<iPair>[V];
}


void Graph::add_edge(int u, int v, int w)
{
	A[u].push_back(make_pair(v, w));
	A[v].push_back(make_pair(u, w));
}

void Graph::dijkstra(int s)
{
	priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

	vector<int> dist(V, INF);

	pq.push(make_pair(0,s));
	dist[s]=0;

	while(!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		for(auto it=A[u].begin(); it!=A[u].end(); it++)
		{
			int v = it->first;
			int w = it->second;

			if(dist[v] > dist[u]+w)
			{
				dist[v] = dist[u]+w;
				pq.push(make_pair(dist[v], v));
			}
		}
	}

	cout<<"Vertex Distance from source:";
	for(int i=0;i<V;i++)
	{
		cout<<i<<" -> "<<dist[i]<< "\n";
	}
}

int main()
{
	Graph g(9);

	g.add_edge(0, 1, 4); 
    g.add_edge(0, 7, 8); 
    g.add_edge(1, 2, 8); 
    g.add_edge(1, 7, 11); 
    g.add_edge(2, 3, 7); 
    g.add_edge(2, 8, 2); 
    g.add_edge(2, 5, 4); 
    g.add_edge(3, 4, 9); 
    g.add_edge(3, 5, 14); 
    g.add_edge(4, 5, 10); 
    g.add_edge(5, 6, 2); 
    g.add_edge(6, 7, 1); 
    g.add_edge(6, 8, 6); 
    g.add_edge(7, 8, 7); 

    g.dijkstra(0);

    return 0;
}
