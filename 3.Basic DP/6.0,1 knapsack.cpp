#include<iostream>
#include<cstring>
#define int long long
using namespace std;
int wt[100+5], val[100000+5], dp[100+5][100000+5], n, tw;

int knap(int item, int weight){
    if(item>=n+1)return 0;
    if(dp[item][weight]!=-1)return dp[item][weight];
    int mx=knap(item+1, weight);
    if(weight+wt[item]<=tw){
        mx=max(mx, knap(item+1, weight+wt[item])+val[item]);
    }
    dp[item][weight]=mx;
    return mx;
}

int32_t main(){
    cin >> n >> tw;///n*tw<=1e7
    for(int i=1; i<=n; ++i)cin >> wt[i];
    for(int i=1; i<=n; ++i)cin >> val[i];
    memset(dp, -1, sizeof(dp));
    cout << knap(1, 0) << endl;
}
