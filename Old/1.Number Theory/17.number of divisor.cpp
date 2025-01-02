#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;cin>>n;
    ll ans=1;
    for(ll i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            ll cnt=0;
            while(n%i==0)
            {
                ++cnt;
                n/=i;
            }
            ans*=(cnt+1);
        }
    }
    if(n!=1)ans*=(1+1);
    cout<<"Number of divisor:"<<ans<<endl;
    return 0;
}
