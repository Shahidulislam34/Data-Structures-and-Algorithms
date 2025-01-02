#include<bits/stdc++.h>
using namespace std;
#define ll long long

void update(ll ind,ll val,ll n,vector<ll>&tree)
{
    while(ind<=n)
    {
        tree[ind]+=val;
        ind+=ind&(-ind);
    }
}

ll findsum(ll r,vector<ll>tree)
{
    ll sum=0;
    while(r>0)
    {
        sum+=tree[r];
        r-=r&(-r);
    }
    return sum;
}

int main()
{
    int n,q,a,b,s1,s2,ind,val;cin>>n>>q;
    vector<ll>v(n+5),tree(n+5,0);
    for(ll i=1;i<=n;++i)cin>>v[i];

    for(ll i=1;i<=n;++i)
        update(i,v[i],n,tree);

    for(ll i=1;i<=n;++i)cout<<i<<":"<<tree[i]<<endl;

    while(q--)
    {
        cin>>ind>>val;
        update(ind,val,n,tree);
        cin>>a>>b;
        s2=findsum(b,tree);
        s1=findsum(a-1,tree);
        cout<<s2-s1<<endl;
    }
    return 0;
}
