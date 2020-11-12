#include<bits/stdc++.h>
#include<map>
using namespace std;

struct Node{
	int data;
	Node *l, *r;
};


Node* newNode(int key)
{
	Node* node = new Node;
	node->data=key;
	node->l=nullptr;
	node->r=nullptr;
	return node;
}


void getVerticalOrder(Node *root, int hd, map<int, vector<int>> &m)
{
	if(root==nullptr)
		return;

	m[hd].push_back(root->data);
	getVerticalOrder(root->l, hd-1, m);
	getVerticalOrder(root->r, hd+1, m);
}

void print(Node *root)
{
	map<int, vector<int>> m;
	int hd=0;
	getVerticalOrder(root, hd, m);

	for(auto it = m.begin();it!=m.end();it++)
	{
		for(int i=0;i<it->second.size();i++)
		{
			cout<<it->second[i]<<" ";
		}
		cout<<endl;	
	}
}

int main()
{
	Node *root = newNode(1);
	root->l = newNode(2);
    root->r = newNode(3);
    root->l->l = newNode(4);
    root->l->r = newNode(5);
    root->r->l = newNode(6);
    root->r->r = newNode(7);
    root->r->l->r = newNode(8);
    root->r->r->r = newNode(9);
    cout<<"Output: ";
    print(root);
    return 0;
}