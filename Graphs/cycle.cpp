#include<bits/stdc++.h>
#include<list>
#include<queue>
using namespace std;

class Graph
{
	int V;
	list<int > *A;
public:
	Graph(int V)
	{
		this->V = V;
		A = new list<int>[V];
	}

	void add_edge(int u, int v)
	{
		A[u].push_back(v);
	}

	bool iscycle();
};

bool Graph::iscycle()
{
	vector<int> in_degree(V, 0);

	for(int i=0;i<V;i++)
	{
		for(auto j:A[i])
			in_degree[j]++;
	}

	queue<int> q;
	for(int i=0;i<V;i++)
	{
		if(in_degree[i]==0)
			q.push(i);
	}

	int cnt=0;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();


		for(auto it=A[u].begin(); it!=A[u].end(); it++)
		{
			if(--in_degree[*it]==0)
				q.push(*it);
		}

		cnt++;
	}

	if(cnt!=V)
		return true;
	else
		return false;
}


int main()
{
	Graph g(6);
	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(2,0);
	g.add_edge(3,4);
	g.add_edge(4,5);
	
	if(g.iscycle())
		cout<<"Yes";
	else 
		cout<<"No";

	return 0;
}
