#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main()
{
    ll n;cin>>n;
    ld ans=0.0;
    for(ll i=1;i<=n;++i)
    {
        ans+=log10(i);
    }
    ans=floor(ans)+1;
    cout<<ans<<endl;

    return 0;
}
