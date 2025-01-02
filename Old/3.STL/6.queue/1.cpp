#include<bits/stdc++.h>
using namespace std;



int main()
{
    queue<int>q,q2;

    ///push()
    q.push(2);
    q.push(1);
    q.push(5);
    q.push(6);


    ///pop()
    q.pop();

    ///size()
    cout<<q.size()<<endl;

    ///front()
    cout<<q.front()<<endl;

    ///back()
    cout<<q.back()<<endl;

    ///empty()
    if(q.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;

    ///swap()
    swap(q,q2);

    ///whole queue
    while(!q2.empty())
    {
        cout<<q2.front()<<' ';
        q2.pop();
    }

    return 0;
}
