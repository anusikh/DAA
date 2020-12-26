//Reverse individual words of a sentence.

#include<bits/stdc++.h>
using namespace std;

void rev(string s)
{
	stack<char> st;
	
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!=' ')
		{
			st.push(s[i]);
		}
		else
		{
			while(!st.empty())
			{
				cout<<st.top();
				st.pop();
			}
			cout<<" ";
		}
	}
	
	while(!st.empty())
	{
		cout<<st.top();
		st.pop();
	}
}

int main()
{
	string s = "Hola Amigo";
	rev(s);
	return 0;
}

