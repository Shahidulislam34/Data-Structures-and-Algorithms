#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5;
ll arr[N+5],tree[4*N+5];

void updt(ll cn, ll li, ll ri, ll a, ll b){
    if(ri<a || li>b)return;
    else if(a<=li && ri<=b){
        tree[cn]+=1;
        return;
    }
    ll mi=(li+ri)/2;
    ll ln=cn*2, rn=cn*2+1;
    updt(ln, li, mi, a, b);
    updt(rn, mi+1, ri, a, b);
    tree[cn]=tree[ln]+tree[rn];
}

ll fnd(ll cn, ll li, ll ri, ll a, ll b){
    if(ri<a || li>b)return 0;
    else if(a<=li && ri<=b){
        return tree[cn];
    }
    ll mi=(li+ri)/2;
    ll ln=cn*2, rn=cn*2+1;
    ll x= fnd(ln, li, mi, a, b);
    ll y= fnd(rn, mi+1, ri, a, b);
    return x+y;
}

int main()
{
    ll n;cin>>n;
    for(ll i=1; i<=n; ++i)cin>>arr[i];
    ll ans=0;
    for(ll i=n; i>=1; --i){
        updt(1, 1, n, arr[i], arr[i]);
        ans+=fnd(1, 1, n, 1, arr[i]-1);
    }
    cout<<"Number of inversion:"<<ans<<endl;
    return 0;
}
