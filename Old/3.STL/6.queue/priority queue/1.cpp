#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    queue<ll>qq;
    qq.push(10);
    qq.push(20);
    qq.push(15);

    cout<<qq.back()<<endl;

    while(!qq.empty())
    {
        cout<<qq.front()<<' ';qq.pop();
    }cout<<endl;

    priority_queue<int,vector<int>,greater<int>>pq;
    pq.push(10);
    pq.push(5);
    pq.push(18);
    pq.push(44);


    while(!pq.empty())
    {
        cout<<pq.top()<<' ';
        pq.pop();
    }




    return 0;
}
