#include<bits/stdc++.h>
using namespace std;


int main()
{
    priority_queue<int>pq;

    ///push()
    pq.push(3);
    pq.push(5);
    pq.push(8);
    pq.push(8);
    pq.push(10);

    ///pop()
    pq.pop();

    ///size()
    cout<<pq.size()<<endl;

    ///top()
    cout<<pq.top()<<endl;


    ///empty()
    if(pq.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;

    ///invalid
    //for(auto x:pq)cout<<x<<' ';cout<<endl;

    while(!pq.empty())
    {
        cout<<pq.top()<<' ';
        pq.pop();
    }
    cout<<endl;

    ///descending order
    priority_queue<int,vector<int>,greater<int>>pq2;
    pq2.push(10);
    pq2.push(3);
    pq2.push(10);
    pq2.push(5);

    while(!pq2.empty())
    {
        cout<<pq2.top()<<' ';
        pq2.pop();
    }
    cout<<endl;


    return 0;
}
