#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;cin>>n;
    ll ans=1;
    for(ll p=2;p<=sqrt(n);++p)
    {
        if(n%p==0)
        {
            ll a=0;
            while(n%p==0)
            {
                ++a;
                n/=p;
            }
            ans*=(pow(p,a+1)-1);
            ans/=(p-1);
        }
    }
    if(n!=1)
    {
        ans*=(pow(n,1+1)-1);
        ans/=(n-1);
    }
    cout<<ans<<endl;

    return 0;
}
