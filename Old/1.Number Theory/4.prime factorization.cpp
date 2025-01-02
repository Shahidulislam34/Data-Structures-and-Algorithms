#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,cnt; cin>>n;
    vector<pair<int,int>>pv;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            cnt=0;
            while(n%i==0)
            {
                ++cnt;
                n/=i;
            }
            pv.push_back({i,cnt});
        }
    }
    if(n!=1)pv.push_back({n,1});
    for(int i=0;i<pv.size();++i)cout<<pv[i].first<<"^"<<pv[i].second<<' ';
    cout<<endl;
    return 0;
}
