#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    multiset<ll>ms;
    ms.insert(3);
    ms.insert(3);
    ms.insert(6);
    for(auto x:ms)cout<<x<<' ';cout<<endl;
    ll ub=*ms.upper_bound(6);
    ll lb=*ms.lower_bound(6);

    cout<<lb<<endl;
    cout<<ub<<endl;

    vector<ll>v={5,6,7,7,9};
    cout<<*upper_bound(v.begin(),v.end(),10)<<endl;


    for(auto x=v.rbegin();x!=v.rend();++x)cout<<*x<<' ';cout<<endl;

}
