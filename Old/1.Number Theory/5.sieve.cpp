#include<bits/stdc++.h>
using namespace std;
#define int long long

void sieve(int n,vector<bool>&vis)
{
    vis[0]=vis[1]=true;
    for(int i=2;i*i<=n;++i)
    {
        if(vis[i]==false)
        {
            for(int j=i*i;j<=n;j+=i)vis[j]=true;
        }
    }
}

int32_t main()
{
    int n;cin>>n;
    vector<bool>vis(n+5,false);
    sieve(n,vis);
    cout<<"Aint Prime:"<<endl;
    int cnt=0;
    for(int i=1;i<=n;++i)
    {
        if(vis[i]==false)
        {
            cout<<i<<' ';
            ++cnt;
        }

    }
    cout<<endl;
    cout<<"Total Prime Number:"<<cnt<<endl;
    return 0;
}
