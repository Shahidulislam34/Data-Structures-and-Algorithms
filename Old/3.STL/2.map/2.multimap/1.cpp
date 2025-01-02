#include<bits/stdc++.h>
using namespace std;
int main()
{
    multimap<int,int>mp;///more than one insert in one key
    mp.insert({3,4});
    mp.insert({2,5});
    mp.insert({3,4});
    mp.insert({5,3});
    for(auto x:mp)cout<<x.first<<' '<<x.second<<endl;

    cout<<"Decreasing order:"<<endl;
    for(auto x=mp.rbegin();x!=mp.rend();++x)cout<<x->first<<' '<<x->second<<endl;

    ///first
    cout<<mp.begin()->first<<' '<<mp.begin()->second<<endl;

    ///last
    cout<<mp.rbegin()->first<<' '<<mp.rbegin()->second<<endl;

    ///erase key
    mp.erase(3);

    ///empty
    if(mp.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;

    ///clear
    mp.clear();
    if(mp.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;

}
