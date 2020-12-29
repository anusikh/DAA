//Complexity : O(EV)
//Single source shortest path for weighted directed graphs
//Works with negative edge too


#include<bits/stdc++.h>
using namespace std;

struct edge
{
	int src, des, wt;
};

int V, E;

void bellman(vector<edge>& Edges)
{
	int parent[V];
	int cost[V];
	vector<int> value(V,INT_MAX);

	parent[0]=-1;
	value[0]=0;

	bool updated;
	for(int i=0;i<V-1;i++)
	{
		updated=false;
		for(int j=0;j<E;j++)
		{
			int u = Edges[j].src;
			int v = Edges[j].des;
			int wt = Edges[j].wt;
			if(value[u]!=INT_MAX && value[u]+wt<value[v])
			{
				value[v] = value[u]+wt;
				parent[v] = u;
				cost[v] = value[v];
				updated = true;
			}
		}

		if(updated==false)
			break;
	}


	for(int j=0;j<E;j++)
	{
		int u = Edges[j].src;
		int v = Edges[j].des;
		int wt = Edges[j].wt;
		if(value[u]!=INT_MAX and value[u]+wt<value[v])
		{
			cout<<"Graph has -ve cycle weight";
			return ;
		}
	}

	for(int i=0;i<V;i++)
		cout<<"U->V: "<<parent[i]<<"->"<<i<<"  Cost to reach "<<parent[i]<<"from source 0 = "<<value[i]<<"\n";
}



int main()
{
	cout<<"Enter The vertices and edges:"<<endl;
	cin>>V;
	cin>>E;

	int src; int des; int wt;
	vector<edge> Edges(E);

	for(int i=0;i<E;i++)
	{
		cout<<"Enter Source ,Destination and weight:";
		cin>>src>>des>>wt;
		Edges[i].src = src;
		Edges[i].des = des;
		Edges[i].wt = wt;
	}

	bellman(Edges);

	return 0;
}