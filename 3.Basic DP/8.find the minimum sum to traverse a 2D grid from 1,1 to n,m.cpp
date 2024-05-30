#include<iostream>
#include<cstring>
using namespace std;
const int N=1e3, M=1e3;
int arr[N+5][M+5], dp[N+5][M+5], n, m;

int grid(int i, int j){
    if(i==n && j==m){
        dp[i][j]=arr[i][j];
        return dp[i][j];
    }
    if(i>n || j>m)return 1e9+7;
    if(dp[i][j]!=-1)return dp[i][j];
    int mn=arr[i][j]+min(grid(i+1, j), grid(i, j+1));
    dp[i][j]=mn;
    return mn;
}

void path(int i, int j){
    if(i>n || j>m)return;
    cout << "(" << i << "," << j << ")" << ' ';
    int d= grid(i+1, j);
    int r= grid(i, j+1);
    if(d<r){
        path(i+1, j);
    }
    else {
        path(i, j+1);
    }
}

int32_t main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=n; ++j){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << grid(1, 1) << endl;
    path(1, 1);
}
