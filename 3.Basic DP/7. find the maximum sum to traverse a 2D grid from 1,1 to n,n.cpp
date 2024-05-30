#include<iostream>
#include<cstring>
using namespace std;
const int r=1e3,c=1e3;
int arr[r+5][c+5], dp[r+5][c+5];
int n,m;

int grid(int i, int j){
    if(i>n || j>m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];

    int mx=grid(i+1, j)+arr[i][j];
    mx=max(mx, grid(i, j+1)+arr[i][j]);
    return dp[i][j]=mx;
}

void path(int i, int j){
    if(i>n || j>m)return;
    cout << "(" << i << "," << j << ")" << ' ';
    int d= grid(i+1, j);
    int r= grid(i, j+1);
    if(d>r){
        path(i+1, j);
    }
    else {
        path(i, j+1);
    }

}

int32_t main(){
    cin >> n >> m;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<=m; ++j){
            cin >> arr[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << grid(1, 1) << endl;
    path(1, 1);
}
