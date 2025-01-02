#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{

    ll n;cin>>n;
    auto st=clock();
    ll gap=pow((ll)log2(n),2);
    for(ll i=n;i<=n+gap;++i)
    {
        ll flag=0;
        for(ll j=2;j*j<=i;++j)
        {
            if(i%j==0){flag=1;break;}
        }
        if(flag==0){cout<<i<<endl;break;}
    }
    auto en=clock();
    cout<<1.0*(en-st)/CLOCKS_PER_SEC<<endl;
    return 0;
}
