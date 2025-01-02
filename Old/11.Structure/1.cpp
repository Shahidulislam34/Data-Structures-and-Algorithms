#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct arr
{
    int one,two,three;
};

int main()
{
    ll n;cin>>n;
    struct arr v[n+5];
    ll a,b,c;
    for(ll i=1;i<=n;++i)
    {
        cin>>a>>b>>c;
        v[i].one=a;
        v[i].two=b;
        v[i].three=c;
    }
    for(ll i=1;i<=n;++i)
    {
        cout<<v[i].one<<' '<<v[i].two<<' '<<v[i].three<<endl;
    }
}
