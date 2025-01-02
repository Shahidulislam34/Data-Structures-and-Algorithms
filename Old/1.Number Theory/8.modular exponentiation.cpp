#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll mod_exponentiation(ll base,ll pow,ll mod)
{
    ll ans=1;
    while(pow)
    {
        if(pow&1==1)
        {
            ans=(ans*base)%mod;
            --pow;
        }
        else
        {
            base=(base*base)%mod;
            pow/=2;
        }
    }
    return ans;
}

int main()
{
    ll base,pow,mod;
    cin>>base>>pow>>mod;

    ll ans=mod_exponentiation(base,pow,mod);
    cout<<ans<<endl;

    return 0;
}
