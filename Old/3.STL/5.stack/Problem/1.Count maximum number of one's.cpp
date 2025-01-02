#include<bits/stdc++.h>
using namespace std;
#define ll long long


void sol()
{
    ll r,c;cin>>r>>c;
    int v[r+5][c+5];
    for(ll i=1;i<=r;++i)
        for(ll j=1;j<=c;++j)
            cin>>v[i][j];


    int cnt[r+5][c+5];
    ll num=0;
    for(ll i=1;i<=c;++i)
    {
        num=0;
        for(ll j=1;j<=r;++j)
        {
            if(v[j][i]==1)++num;
            else num=0;
            cnt[j][i]=num;
        }
    }
    for(ll i=1;i<=r;++i)
    {
        for(ll j=1;j<=c;++j)
            cout<<cnt[i][j]<<' ';
        cout<<endl;
    }

    ll ans=0;

    for(ll i=1;i<=r;++i)
    {
        stack<ll>st;
        for(ll j=1;j<=c;++j)
        {
            if(st.empty()||(cnt[i][j]!=0&&cnt[i][st.top()]<=cnt[i][j]))st.push(j);
            else
            {
                ll lst=st.top(),fst;
                while(!st.empty()&&cnt[i][st.top()]>cnt[i][j])
                {
                    fst=st.top();
                    ans=max(ans,(lst-fst+1)*cnt[i][fst]);
                    if(cnt[i][fst]>=cnt[i][j])
                        ans=max(ans,(j-fst+1)*cnt[i][j]);
                    st.pop();
                    cout<<i<<' '<<j<<' '<<fst<<' '<<lst<<' '<<ans<<endl;
                }
                if(cnt[i][j]!=0)
                st.push(j);

            }
        }
    }
    cout<<ans<<endl;


}


int main()
{
    ll t=1;cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}
