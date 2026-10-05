#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int>dq;
    deque<int>dqq[10];
    deque<int>dqqq[10][10];
    ///push_back()
    dq.push_back(3);//O(1)
    dq.push_back(4);
    dq.push_back(6);

    ///pop_back()
    dq.pop_back();//O(1)

    ///push_front()
    dq.push_front(9);
    dq.push_front(10);
    dq.push_front(11);//O(1)

    ///pop_front()
    dq.pop_front();//O(1)

    ///front()
    cout<<dq.front()<<endl;//O(1)

    ///back()
    cout<<dq.back()<<endl;//O(1)

    ///invalid
    //cout<<dq.top()<<endl;

    ///while print
    for(auto x:dq)cout<<x<<' ';cout<<endl;

    ///single index print
    cout<<dq[0]<<endl;//O(1)

    ///reverse()
    reverse(dq.begin(),dq.end());//(n)

    ///sort()
    sort(dq.begin(),dq.end());///O(nlogn)

    ///erase
    dq.erase(dq.begin(),dq.begin()+2);//O(n)
    for(auto x:dq)cout<<x<<' ';cout<<endl;

    ///size()
    cout<<dq.size()<<endl;

    return 0;
}

