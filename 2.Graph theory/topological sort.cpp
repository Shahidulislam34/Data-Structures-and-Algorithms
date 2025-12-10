#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

///topological sorting--O(n)--node starting from 1
int n, e;
vector<vector<int>>gra;
vector<int>vis;
vector<int>srt;
//finding cycle
bool dfs1(int cn) {
    if (vis[cn] == 1) return false;
    else if (vis[cn] == 2) return true;
    vis[cn] = 1;
    for (auto chi : gra[cn]) {
        if (dfs1(chi) == false) return false;
    }
    vis[cn] = 2;
    return true;
}
bool iscycle() {
    vis.assign(n + 5, 0);
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0 && dfs1(i) == false) return false;
    }
    return true;
}
//finding order
void dfs(int cn) {
    if (vis[cn] == 1) return;
    vis[cn] = 1;
    for (auto chi : gra[cn]) {
        dfs(chi);
    }
    srt.push_back(cn);
}
void topsort() {
    vis.assign(n + 5, 0);
    srt.clear();
    for (int i = 1; i <= n; ++i) {
        if (vis[i] == 0) dfs(i);
    }
    reverse(srt.begin(), srt.end());
}
///topological sorting----

int32_t main() {
    cin >> n >> e;
    gra.resize(n + 5);
    while(e--) {
        int aa, bb; cin >> aa >> bb;
        gra[aa].push_back(bb);
    }
    if(iscycle() == false) cout << "Impossible" << endl;
    else {
        topsort();
        cout << "Possible" << endl;
        for (auto x : srt) cout << x << ' '; cout << endl;
    }

    return 0;
}
