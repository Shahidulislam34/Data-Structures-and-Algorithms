#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ll n;cin>>n;
    ll ans=0,mul=5;
    while(mul<=n)
    {
        ans+=n/mul;
        mul*=5;
    }
    cout<<ans<<endl;
    return 0;
}
