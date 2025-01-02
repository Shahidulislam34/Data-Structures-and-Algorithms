#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
vector<ll>v(6000000),tree(6000000),pro(6000000);

void init(ll cn,ll li,ll ri)
{
    if(li==ri){tree[cn]=v[li];return;}
    ll mid=(li+ri)/2;
    ll ln=cn*2,rn=cn*2+1;
    init(ln,li,mid);
    init(rn,mid+1,ri);
    tree[cn]=tree[ln]+tree[rn];
}

void update(ll cn,ll li,ll ri,ll a,ll b,ll val)
{
    if(li>b||ri<a)return;
    if(a<=li&&ri<=b)
    {
        tree[cn]+=(ri-li+1)*val;
        pro[cn]+=val;
        return;
    }
    ll mid=(li+ri)/2;
    ll ln=cn*2,rn=cn*2+1;
    update(ln,li,mid,a,b,val);
    update(rn,mid+1,ri,a,b,val);
    tree[cn]=tree[ln]+tree[rn]+(ri-li+1)*pro[cn];
}

ll findsum(ll cn,ll li,ll ri,ll a,ll b,ll carry)
{
    if(li>b||ri<a)return 0;
    if(a<=li&&ri<=b)return tree[cn]+carry*(ri-li+1);
    ll mid=(li+ri)/2;
    ll ln=cn*2,rn=cn*2+1;
    ll s1=findsum(ln,li,mid,a,b,carry+pro[cn]);
    ll s2=findsum(rn,mid+1,ri,a,b,carry+pro[cn]);
    return s1+s2;
}

int main()
{
    ll n;cin>>n;
    for(ll i=1;i<=n;++i)cin>>v[i];
    init(1,1,n);
    ll l,r,val,a,b;
    while(cin>>l>>r>>val>>a>>b)
    {
        update(1,1,n,l,r,val);
        cout<<findsum(1,1,n,a,b,0)<<endl;
    }
    return 0;
}
