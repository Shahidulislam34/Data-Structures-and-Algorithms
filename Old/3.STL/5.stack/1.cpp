#include<bits/stdc++.h>
using namespace std;


int main()
{

    stack<int>st,st2;

    ///push()
    st.push(3);
    st.push(6);
    st.push(1);
    st.push(9);

    ///top()
    cout<<st.top()<<endl;


    ///empty()
    if(st.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;

    ///size()
    cout<<st.size()<<endl;

    ///whole print & pop()
    while(!st.empty())
    {
        cout<<st.top()<<' ';
        st.pop();
    }
    cout<<endl;


    ///swap()
    swap(st,st2);

    return 0;
}
