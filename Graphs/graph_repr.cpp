#include<bits/stdc++.h>
using namespace std;

//We can also use list instead of vector and basically get the smae result
void add_edge(std::vector<int> *A, int u, int v)
{
	A[u].push_back(v);
	A[v].push_back(u);
}

void print(std::vector<int> *A, int V)
{
	for(int i=0;i<V;i++)
	{
		cout<<"The List at Vertex"<<i<<"\n head";
		for(auto j: A[i])
		{
			cout<<" "<<j;
		}
		printf("\n");
	}
}


int main()
{
	int V=5;
	std::vector<int> Y[5];
	add_edge(Y, 0, 1); 
    add_edge(Y, 0, 4); 
    add_edge(Y, 1, 2); 
    add_edge(Y, 1, 3); 
    add_edge(Y, 1, 4); 
    add_edge(Y, 2, 3); 
    add_edge(Y, 3, 4); 
    print(Y, V);
    return 0;
}
