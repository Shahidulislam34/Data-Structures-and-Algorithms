#include<bits/stdc++.h>
using namespace std;
#define int long long
///LCA STARTS ------
const int N = 2e5;
vector<int>gra[N + 5], depth(N + 5);
vector<vector<int>>par;
int level;

void dfs(int cur, int prev) {
    depth[cur] = depth[max(0ll, prev)] + 1;
    par[cur][0] = prev;
    for (auto chi : gra[cur]) {
        if (chi != prev)
            dfs(chi, cur);
    }
}

void pre_compute(int n) {
    for (int i = 1; i <= level; ++i) {
        for (int node = 1; node <= n; ++node) {
            if (par[node][i - 1] != -1)
                par[node][i] = par[par[node][i - 1]][i - 1];
        }
    }
}

int lca(int uu, int vv) {
    if (depth[uu] < depth[vv]) swap(uu, vv);
    int dif = depth[uu] - depth[vv];
    for (int i = 0; i <= level; ++i) {
        if ((dif >> i) & 1)
            uu = par[uu][i];
    }
    if (uu == vv) return uu;
    for (int i = level; i >= 0; --i) {
        if (par[uu][i] != par[vv][i]) {
            uu = par[uu][i];
            vv = par[vv][i];
        }
    }
    return par[uu][0];
}

void init(int n) {
    level = log2(n);
    par.assign(n + 5, vector<int>(level + 5, -1));
    depth[0] = -1;
    dfs(1, -1);
    pre_compute(n);
}
///LCA ENDS----

void sol() {
    int n, e;
    cin >> n; e = n - 1;
    for (int i = 1; i <= n; ++i) gra[i].clear();
    while(e--) {
        int uu, vv;
        cin >> uu >> vv;
        gra[uu].push_back(vv);
        gra[vv].push_back(uu);
    }
    init(n);
    while(1) {
        int uu, vv;
        cin >> uu >> vv;
        cout << lca(uu, vv) << endl;
    }
}

int32_t main() {
    int tt = 1;
    cin >> tt;
    while(tt--)sol();
    return 0;
}
