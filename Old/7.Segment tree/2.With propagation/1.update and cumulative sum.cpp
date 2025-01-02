#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

void init(ll cn,ll li,ll ri,vector<ll>&tree,vector<ll>v)
{
    if(li==ri){tree[cn]=v[li];return;}
    ll mid=(li+ri)/2;
    ll ln=cn*2,rn=cn*2+1;
    init(ln,li,mid,tree,v);
    init(rn,mid+1,ri,tree,v);
    tree[cn]=tree[ln]+tree[rn];
}

///add x between l and r inclusive
void update(ll cn,ll li,ll ri,ll l,ll r,ll x,vector<ll>&tree,vector<ll>&prop)
{
    if(ri<l||li>r)return;
    if(l<=li&&ri<=r)
    {
        tree[cn]+=(r-l+1)*x;
        prop[cn]+=x;
        return;
    }
    ll mid=(li+ri)/2;
    ll ln=cn*2,rn=cn*2+1;
    update(ln,li,mid,l,r,x,tree,prop);
    update(rn,mid+1,ri,l,r,x,tree,prop);
    tree[cn]=tree[ln]+tree[rn]+prop[cn]*(ri-li+1);
}

ll findsum(ll cn,ll li,ll ri,ll a,ll b,ll carry,vector<ll>&tree,vector<ll>&prop)
{
    if(ri<a||li>b)return 0;
    if(a<=li&&ri<=b)return tree[cn]+carry*(ri-li+1);

    ll mid=(li+ri)/2;
    ll ln=cn*2,rn=cn*2+1;
    ll s1=findsum(ln,li,mid,a,b,carry+prop[cn],tree,prop);
    ll s2=findsum(rn,mid+1,ri,a,b,carry+prop[cn],tree,prop);
    return s1+s2;
}

int main()
{
    ll n;cin>>n;
    vector<ll>v(n+5);
    for(ll i=1;i<=n;++i)cin>>v[i];
    vector<ll>tree(4*n),prop(4*n,0);

    init(1,1,n,tree,v);

    ll l,r,x,a,b;
    while(cin>>l>>r>>x>>a>>b)
    {
        update(1,1,n,l,r,x,tree,prop);
        cout<<findsum(1,1,n,a,b,0,tree,prop)<<endl;
    }
    return 0;
}
