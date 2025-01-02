#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll  n,ans; cin>>n;
    ans=n;
    for(ll i=2;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
            }
            ans*=(i-1);
            ans/=i;
        }
    }
    if(n!=1)
    {
        ans*=(n-1);
        ans/=n;
    }
    cout<<ans<<endl;


    return 0;
}
