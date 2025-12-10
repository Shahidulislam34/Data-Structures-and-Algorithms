#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int M2 = 998244353;
const int N = (int)3e5;
const int Inf = (int)1e18;
const double pi = acos(-1.0);
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

void floyd_warshall(int n, vector<vector<int>>&cost) {
    for (int i = 1; i <= n; ++i) cost[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (cost[i][k] != Inf && cost[k][j] != Inf) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
    }
}

void sol(int ttt){
    //don't work for negative cycle
    int n, e; cin >> n >> e;
    vector<vector<int>>cost(n + 5, vector<int>(n + 5, Inf));
    while(e--) {
        int uu, vv, ww; cin >> uu >> vv >> ww;
        cost[uu][vv] = min(cost[uu][vv], ww);
        cost[vv][uu] = min(cost[vv][uu], ww);
    }
    floyd_warshall(n, cost);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << cost[i][j] << ' ';
        }
        cout << endl;
    }
}

int32_t main(){
    sol(1);
    return 0;
}
