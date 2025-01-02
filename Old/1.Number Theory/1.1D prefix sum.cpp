#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vll     vector<ll>

void prefix(vll &v,ll n)
{
    for(ll i=2;i<=n;++i)v[i]+=v[i-1];
}


int main()
{
    ll n;cin>>n;
    vll v(n+5);
    for(ll i=1;i<=n;++i)cin>>v[i];
    prefix(v,n);
    for(ll i=1;i<=n;++i)cout<<v[i]<<' ';cout<<endl;
    return 0;
}
