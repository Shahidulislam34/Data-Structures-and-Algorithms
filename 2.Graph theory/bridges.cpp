#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

///bridges----O(n + e)-----node starts from 1
vector<vector<int>>gra;
vector<int>dis, low;
vector<pair<int, int>>br;
int timer = 0;
void dfs(int cn, int anc = 0){
    dis[cn] = low[cn] = ++timer;
    for (auto chi : gra[cn]){
        if (chi == anc) continue;
        if (dis[chi]) low[cn] = min(low[cn], dis[chi]);//when chi is visited
        else {
            dfs(chi, cn);
            low[cn] = min(low[cn], low[chi]);
            if (dis[cn] < low[chi]) br.emplace_back(cn, chi);
        }
    }
}
///bridges------

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, e;
    cin >> n >> e;

    gra.resize(n + 5);
    dis.assign(n + 5, 0);
    low.assign(n + 5, 0);
    for (int i = 1; i <= n; ++i) gra[i].clear();
    while(e--){
        int a, b;
        cin >> a >> b;
        gra[a].push_back(b);
        gra[b].push_back(a);
    }
    dfs(1);
    cout << "Bridges:" << endl;
    for (auto [uu, vv] : br) cout << uu << ' ' << vv << endl;

    return 0;
}

