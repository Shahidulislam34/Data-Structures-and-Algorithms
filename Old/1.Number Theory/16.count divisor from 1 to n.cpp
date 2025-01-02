#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double



int main()
{
    ll n;cin>>n;
    vector<ll>v[n+5];
    for(ll i=1;i<=n;++i)
    {
        for(ll j=i;j<=n;j+=i)
            v[j].push_back(i);
    }
    for(ll i=1;i<=n;++i)
    {
        cout<<"Divisor of "<<i<<":";
        for(ll j=0;j<v[i].size();++j)cout<<v[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
