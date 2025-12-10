#include<bits/stdc++.h>
using namespace std;
#define int long long

int dp[1005][1005];
void nCr(int n, int m) {
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % m;
        }
    }
}

void sol(){
    nCr(1000, 998244353);
    int n, r; cin >> n >> r;
    cout << dp[n][r] << endl;
}

int32_t main(){
    sol();
    return 0;
}
