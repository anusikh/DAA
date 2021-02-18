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



void get_vertical_order(Node *root, int hd, map<int, std::vector<int>> &m)
{
    if(root==nullptr)
        return;
        
    m[hd].push_back(root->data);
    get_vertical_order(root->l, hd-1, m);
    get_vertical_order(root->r, hd+1, m);
}


void inorder(Node *root)
{
    if(root==nullptr)
        return;
        
    inorder(root->l);
    cout<<root->data<<" ";
    inorder(root->r);
}



void print(Node *root)
{
    map<int, std::vector<int>> m;
    int hd = 0;
    get_vertical_order(root, hd, m);
    
    for(auto it=m.begin();it!=m.end();it++)
    {
        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<" ";
        }
    }
}



//Find Path to a specific Node
bool haspath(Node *root, vector<int> &v, int x)
{
    if(root==nullptr)
        return false;
        
    v.push_back(root->data);
        
    if(root->data==x)
        return true;
        
    if(haspath(root->l, v, x)||haspath(root->r,v,x))
        return true;
        
    v.pop_back();
    return false;
}



void print_path(Node *root, int x)
{
    vector<int> v;
    
    if(haspath(root,v,x))
    {
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" -> ";
        }
        cout<<v[v.size()-1];
    }
    
    else
    {
        cout<<"No path";
    }
}



void travel(Node *root)
{
    if(root==nullptr)
        return;
        
    
    travel(root->r);
    cout<<root->data<<" ";
}



void flip(Node *root)
{
    if(root==nullptr)
        return;
    
    flip(root->l);
    flip(root->r);
    
    Node *temp = root->l;
    root->l = root->r;
    root->r = temp;
}

int main()
{
	Node *root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);
    root->l->l = newNode(4);
    root->l->r = newNode(5);
    cout<<"Output: ";
    //print(root);
    //print_path(root, 5);
    // travel(root);
    
    inorder(root);
    flip(root);
    cout<<endl;
    inorder(root);
    
    
    return 0;
}


