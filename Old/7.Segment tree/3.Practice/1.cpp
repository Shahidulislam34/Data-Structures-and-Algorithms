#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<ll>v(6000000),tree(24000000);

void init(ll cn,ll li,ll ri)
{
    if(li==ri){tree[cn]=v[li];return;}
    ll mid=(li+ri)/2;
    ll ln=cn*2,rn=cn*2+1;
    init(ln,li,mid);
    init(rn,mid+1,ri);
    tree[cn]=min(tree[ln],tree[rn]);
}

ll findsum(ll cn,ll li,ll ri,ll a,ll b)
{
    if(li>b||ri<a)return INT_MAX;
    if(a<=li&&ri<=b)return tree[cn];
    ll mid=(li+ri)/2;
    ll ln=cn*2,rn=cn*2+1;
    ll s1=findsum(ln,li,mid,a,b);
    ll s2=findsum(rn,mid+1,ri,a,b);
    return min(s1,s2);
}

void update(ll cn,ll li,ll ri,ll ind,ll val)
{
    if(li>ind||ri<ind)return;
    if(li==ind&&ri==ind){tree[cn]=val;return;}
    ll mid=(li+ri)/2;
    ll ln=cn*2,rn=cn*2+1;
    update(ln,li,mid,ind,val);
    update(rn,mid+1,ri,ind,val);
    tree[cn]=min(tree[ln],tree[rn]);
}

int main()
{
    ll n;cin>>n;
    for(ll i=1;i<=n;++i)cin>>v[i];
    init(1,1,n);
    ll a,b,ind,val;
    while(cin>>ind>>val>>a>>b)
    {
        update(1,1,n,ind,val);
        cout<<findsum(1,1,n,a,b)<<endl;
    }
    return 0;
}
