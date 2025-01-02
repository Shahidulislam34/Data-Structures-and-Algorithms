#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5;
int arr[N+5], tree[4*N+5], prop[4*N+5];

void init(ll cn, ll li, ll ri){
    if(li == ri){
        tree[cn]=arr[li];
        return ;
    }
    ll mi=(li+ri)/2;
    ll ln=cn*2, rn=cn*2+1;
    init(ln, li, mi);
    init(rn, mi+1, ri);
    tree[cn]=min(tree[ln], tree[rn]);
}

void updt(ll cn, ll li, ll ri, ll a, ll b, ll val){
    if(ri<a || li>b)return;
    else if(a<=li && ri<=b){
        tree[cn]=tree[cn]+val;
        prop[cn]+=val;
        return ;
    }
    ll mi=(li+ri)/2;
    ll ln=cn*2, rn=cn*2+1;
    updt(ln, li, mi, a, b, val);
    updt(rn, mi+1, ri, a, b, val);
    tree[cn]=min(tree[ln], tree[rn]);
}

ll fnd(ll cn, ll li, ll ri, ll car, ll a, ll b){
    if(ri<a || li>b)return INT_MAX;
    else if(a<=li && b>=ri){
        return tree[cn]+car;
    }
    ll mi=(li+ri)/2;
    ll ln=cn*2, rn=cn*2+1;
    ll x=fnd(ln, li, mi, car+prop[cn], a, b);
    ll y=fnd(rn, mi+1, ri, car+prop[cn], a, b);
    return min(x,y);
}

int main()
{
    ll n;
    cin>>n;
    for(ll i=1; i<=n; ++i)cin>>arr[i];
    init(1, 1, n);
    ll q, a, b, sel, val;
    cin>>q;
    while(q--)
    {
        cin>>sel;
        if(sel == 1)
        {
            cin>>a>>b>>val;
            updt(1, 1, n, a, b, val);
        }
        else
        {
            cin>>a>>b;
            cout<<fnd(1, 1, n, 0, a, b)<<endl;
        }
    }
    return 0;
}
