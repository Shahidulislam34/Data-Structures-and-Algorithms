#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll bin_exponentiation(ll base,ll pow)
{
    ll ans=1;
    while(pow)
    {
        if(pow%2==1)
        {
            ans*=base;
            --pow;
        }
        else
        {
            base*=base;
            pow/=2;
        }
    }
    return ans;
}

int main()
{
    ll bas,pow;
    cin>>bas>>pow;
    ll ans=bin_exponentiation(bas,pow);
    cout<<ans<<endl;

    return 0;
}
