#include<iostream>
#include<vector>
using namespace std;

int main()
{
  int n,q;
  cin>>n>>q;
  vector<vector<int>> v(n, vector<int>());
  int lastanswer = 0;
  for(int i=0;i<q;i++)
  {
    int t,x,y;
    cin>>t>>x>>y;

    if(t==1)
      v[(x^lastanswer)%n].push_back(y);
    else{
      lastanswer = v[(x^lastanswer)%n][y%v[(x^lastanswer)%n].size()];
      cout<<lastanswer<<endl;
    }
  }


  return 0;
}
