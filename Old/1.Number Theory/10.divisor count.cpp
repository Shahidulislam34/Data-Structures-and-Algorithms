#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n;cin>>n;
    set<ll>s;
    for(ll i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            s.insert(i);
            s.insert(n/i);
        }
    }
    cout<<"Total Divisor:"<<s.size()<<endl;
    for(auto x:s)cout<<x<<' ';cout<<endl;

    return 0;
}
