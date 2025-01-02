#include<bits/stdc++.h>
using namespace std;



int main()
{
    deque<int>dq;
    dq.push_back(4);
    dq.push_front(5);
    dq.push_back(10);
    dq.push_front(16);

    dq.erase(dq.begin());

    sort(dq.begin(),dq.end());

    for(int i=0;i<dq.size();++i)cout<<dq[i]<<' ';cout<<endl;

    dq.pop_back();
    dq.pop_front();
    cout<<dq[0]<<' '<<dq[1]<<endl;

    for(auto x:dq)cout<<x<<' ';cout<<endl;

    return 0;
}
