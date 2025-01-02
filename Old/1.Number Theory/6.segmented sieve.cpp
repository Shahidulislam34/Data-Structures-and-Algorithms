#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> sieve(ll n)
{
    vector<ll>pp;
    vector<bool>vis(n+5,false);
    vis[0]=vis[1]=true;
    for(ll i=3;i*i<=n;i+=2)
    {
        if(vis[i]==false)
        {
            for(ll j=i*i;j<=n;j+=i)
                vis[j]=true;
        }
    }
    pp.push_back(2);
    for(ll i=3;i<=n;i+=2)if(vis[i]==false&&i%2==1)pp.push_back(i);
    return pp;
}

vector<ll> segmented_sieve(ll a,ll b,vector<ll>&pp)
{
    if(a<=1)a=2;
    ll ran,fir;
    ran=b-a+1;
    vector<ll>ans;
    vector<bool>vis(ran+5,false);
    for(auto x:pp)
    {
        fir=(int)(a/x)*x;
        if(fir<a)fir+=x;

        for(ll i=fir;i<=b;i+=x)
        {
            if(i!=x)vis[i-a+1]=true;
        }

    }
    for(ll i=1;i<=ran;++i)if(vis[i]==false)ans.push_back(i-1+a);
    return ans;
}

int main()
{
    ll a,b;
    cin>>a>>b;

    ///sieve:
    vector<ll>pp= sieve(sqrt(b));
    cout<<"siev from 1 to "<<(ll)sqrt(b)<<":";
    for(ll i=0;i<pp.size();++i)cout<<pp[i]<<' ';cout<<endl;

    ///segmented_sieve:
    vector<ll>prim=segmented_sieve(a,b,pp);
    cout<<"segmented_sieve between "<<a<<" ans "<<b<<":";
    for(ll i=0;i<prim.size();++i)cout<<prim[i]<<' ';cout<<endl;

    return 0;
}
