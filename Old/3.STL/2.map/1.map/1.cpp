#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int>m;
    m[3]=13;
    m[4]=14;

    ///use dot(.)
    for(auto x:m)cout<<x.first<<' '<<x.second<<endl;

    ///use ->
    for(auto x=m.begin();x!=m.end();++x)cout<<x->first<<' '<<x->second<<endl;

    ///reverse print
    for(auto x=m.rbegin();x!=m.rend();++x)cout<<x->first<<' '<<x->second<<endl;

    ///all index value are initially zero
    cout<<m[9]<<endl;
//    cout<<m[100000000000000]<<endl;

    for(int i=1;i<=10;++i)
        m[i]=rand()%10;
    cout<<endl;
    for(auto x:m)
        cout<<x.first<<' '<<x.second<<endl;

    ///first
    cout<<m.begin()->first<<' '<<m.begin()->second<<endl;

    ///last
    cout<<m.rbegin()->first<<' '<<m.rbegin()->second<<endl;

    ///erase index
    cout<<"Erase:"<<endl;
    m.erase(1);
    m.erase(2);
    for(auto x:m)cout<<x.first<<' '<<x.second<<endl;

    ///all clear
    m.clear();

    ///empty
    if(m.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;

    ///size
    cout<<m.size()<<endl;


    map<int,int>m2;
    m2.insert({3,5});
    m2.insert({6,1});
    m2.insert({2,9});
    m2.insert({5,4});
    m2.insert({5,0});///2nd same key is not insert
    for(auto x:m2)cout<<x.first<<' '<<x.second<<endl;

}
