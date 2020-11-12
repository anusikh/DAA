#include<bits/stdc++.h>
using namespace std;

void add_edge(std::vector<pair<int, int>> *A, int u , int v, int w)
{
	A[u].push_back(make_pair(v, w));
	A[v].push_back(make_pair(u, w));
}

void print(std::vector<pair<int, int>> *A, int V)
{
	int v, w;
	for(int i=0;i<V;i++)
	{
		cout<<"The list at vertex "<<i<<"\n head";
		for(auto it=A[i].begin(); it!=A[i].end(); it++)
		{
			v = it->first;
			w = it->second;
			cout<<" "<<"("<<v<<", "<<w<<" )"<<"\n";
		}
		cout<<"\n";       
	}
}


int main()
{
	int V = 5;
	std::vector<pair<int,int>> A[V];
	add_edge(A, 0, 1, 10); 
    add_edge(A, 0, 4, 20); 
    add_edge(A, 1, 2, 30); 
    add_edge(A, 1, 3, 40); 
    add_edge(A, 1, 4, 50); 
    add_edge(A, 2, 3, 60); 
    add_edge(A, 3, 4, 70); 
    print(A, V);
    return 0;
}