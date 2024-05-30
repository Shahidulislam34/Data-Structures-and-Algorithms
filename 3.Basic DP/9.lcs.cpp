#include<iostream>
#include<cstring>
using namespace std;
const int N=1000;
int dp[N+5][N+5], n, m;
string a, b;

int lcs(int i, int j){
    if(i==n || j==m)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int mx=lcs(i+1, j);
    mx=max(mx, lcs(i, j+1));
    if(a[i]==b[j]){
        mx=lcs(i+1, j+1)+1;
    }
    return dp[i][j]=mx;
}

void print(int i, int j){
    if(i==n || j==m)return;
    if(a[i]==b[j]){
        cout << a[i];
        print(i+1, j+1);
        return;
    }
    int u=lcs(i+1, j);
    int d=lcs(i, j+1);
    if(u>=d)
        print(i+1, j);
    else
        print(i, j+1);
}

int32_t main(){
    cin >> n >> m;///n*m<=1e6
    cin >> a >> b;
    memset(dp, -1, sizeof(dp));
    cout << "Length: " << lcs(0, 0) << endl;
    print(0, 0);
    return 0;
}
