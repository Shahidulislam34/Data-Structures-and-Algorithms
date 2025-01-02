#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll bin(ll l,ll r,ll n)
{
    if(n==0||n==1)return n;
    ll mid,ans;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(mid*mid<=n){ans=mid;l=mid+1;}
        else r=mid-1;
    }
    return ans;
}

int main()
{
    ll n;cin>>n;
    ll ans=bin(1,n,n);
    cout<<ans<<endl;

    return 0;
}
