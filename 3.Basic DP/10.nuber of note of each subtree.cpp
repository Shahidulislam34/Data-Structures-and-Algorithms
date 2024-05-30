#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=2e5;
vector<int>tree[N+5];
int dp[N+5], n, e, vis[N+5];

int subtree(int cn){
    if(dp[cn]!=-1)return dp[cn];
    vis[cn]=1;
    int mx=1;
    for(auto x:tree[cn]){
        if(!vis[x])
            mx+=subtree(x);
    }
    return dp[cn]=mx;
}

int32_t main(){
    cin >> n >> e;
    while(e--){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ///root 1
    memset(dp, -1, sizeof(dp));
    memset(vis, 0, sizeof(vis));
    subtree(1);
    for(int i=1; i<=n; ++i)cout << i << ":" << dp[i] << endl;
}
