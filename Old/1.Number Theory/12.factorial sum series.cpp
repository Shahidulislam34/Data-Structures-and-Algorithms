#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld  long double

ll factorial(ll n)
{
    ll ans=1;
    for(ll i=1;i<=n;++i)
        ans*=i;
    return ans;
}

int main()
{
    /// 1/1! + 1/2! + 1/3! + ......... 1/n!  =   ?
    ll  n,fac,tmp,div=1;
    cin>>n;
    fac=factorial(n);
    tmp=fac;

    ld ans=0.0;
    for(ll i=n;i>=1;--i)
    {
        ans+=fac/tmp;
        div*=i;
        tmp=fac/div;
    }
    ans=ans/fac;
    cout<<ans<<endl;

    return 0;
}
