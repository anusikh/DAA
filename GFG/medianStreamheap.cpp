#include<iostream>
#include<queue>
using namespace std;

void printMedians(double arr[], int n)
{
    priority_queue<double> s; //MAX-HEAP
    priority_queue<double, vector<double>, greater<double>> g; //MIN-HEAP

    double med = arr[0];
    cout<<med<<endl;
    s.push(med);

    for(int i=1;i<n;i++)
    {
        double x = arr[i];

        if(s.size() > g.size())
        {
            if(x<med)
            {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);

            med = (s.top()+g.top())/2.0;
        }

        else if(s.size()==g.size())
        {
            if(x<med)
            {
                s.push(x);
                med = (double)(s.top());
            }
            else
            {
                g.push(x);
                med = (double)(g.top());
            }
        }

        else
        {
            if(x<med)
                s.push(x);
            else
            {
                s.push(g.top());
                g.pop();
                g.push(x);
            }

            med = (s.top()+g.top())/2.0;
        }

        cout<<med<<endl;
    }   

}

//alternate code
/*void printMedians(double *arr, int n)
{
    priority_queue<double> q1; //MAX_HEAP
    priority_queue<double, vector<double>, greater<double>> q2; //MIN_HEAP

    for(int i=0;i<n;i++)
    {
        double num = arr[i];

        if(q1.empty()||q1.top()>num)
            q1.push(num);
        else
            q2.push(num);

        if(q1.size()>q2.size()+1)
        {
            q2.push(q1.top());
            q1.pop();
        }
        else if(q2.size()>q1.size()+1)
        {
            q1.push(q2.top());
            q2.pop();
        }

        if(q1.size()==q2.size())
            cout<<(double)(q1.top()+q2.top())/2.0<<endl;
        else if(q1.size()>q2.size())
            cout<<q1.top()<<endl;
        else
            cout<<q2.top()<<endl;
    }
}*/

int main()
{
    double arr[] = {5, 15, 10, 20, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printMedians(arr, n); 
    return 0; 
}