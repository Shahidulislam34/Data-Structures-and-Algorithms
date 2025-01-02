#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<ll>v(100);
bool ok=false;
void init(ll n)
{
    for(ll i=1;i<=n;++i)v[i]=i;
}
ll Find(ll node)
{
    if(v[node]==node)return node;
    else return v[node]=Find(v[node]);
}
void Union(ll a,ll b)
{
    int repa = Find(a);
    int repb = Find(b);
    v[repa] = repb;
}
int main()
{
    ll n,e,a,b;cin>>n>>e;
    init(n);
    while(e--)
    {
        cin>>a>>b;
        Union(a,b);
    }
    for(ll i=1;i<=n;++i)cout<<v[i]<<' ';cout<<endl;
    ll x,y;
    while(1)
    {
        cin>>x>>y;
        if(Find(x)==Find(y))cout<<"Friend"<<endl;
        else cout<<"Not Friend"<<endl;
    }
    return 0;
}
