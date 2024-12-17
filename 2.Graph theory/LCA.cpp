#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

///Lca starts ------root 1
const int N = 2e5;
vector<int>Gra[N + 5], Depth(N + 5);
vector<vector<int>>Par;
int Level;

void dfs(int cur, int prev) {
    Depth[cur] = Depth[max(0ll, prev)] + 1;
    Par[cur][0] = prev;
    for (auto chi : Gra[cur]) {
        if (chi != prev)
            dfs(chi, cur);
    }
}

void pre_compute(int n) {
    for (int i = 1; i <= Level; ++i) {
        for (int node = 1; node <= n; ++node) {
            if (Par[node][i - 1] != -1)
                Par[node][i] = Par[Par[node][i - 1]][i - 1];
        }
    }
}

int bin_jump(int node, int up) {
    for (int i = 0; i <= Level; ++i) {
        if ((up >> i) & 1)
            node = Par[node][i];
        if (node == -1)break;
    }
    return node;
}

int lca(int uu, int vv) {
    if (Depth[uu] < Depth[vv]) swap(uu, vv);
    int dif = Depth[uu] - Depth[vv];
    uu = bin_jump(uu, dif);
    if (uu == vv) return uu;
    for (int i = Level; i >= 0; --i) {
        if (Par[uu][i] != Par[vv][i]) {
            uu = Par[uu][i];
            vv = Par[vv][i];
        }
    }
    return Par[uu][0];
}

void init(int n) {
    Level = log2(n);
    Par.assign(n + 5, vector<int>(Level + 5, -1));
    Depth[0] = -1;
    dfs(1, -1);
    pre_compute(n);
}
///Lca ends----


void sol(){
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) Gra[i].clear();
    for (int i = 2; i <= n; ++i) {
        int node; cin >> node;
        Gra[node].push_back(i);
        Gra[i].push_back(node);
    }
    init(n);
    while(q--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }
}

int32_t main(){
    faster();
    int tt = 1;
//    cin >> tt;
    while(tt--) sol();
    return 0;
}


