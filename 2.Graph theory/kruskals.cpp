#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int>rep;
void init_rep(int n) {
    rep.clear();
    rep.resize(n + 5);
    for (int i = 1; i <= n; ++i) rep[i] = i;
}

int find_rep(int m) {
    if (rep[m] == m) return m;
    return rep[m] = find_rep(rep[m]);
}

void update_rep(int a, int b) {
    int rp1 = find_rep(a);
    int rp2 = find_rep(b);
    rep[rp1] = rp2;
}

void sol(int ttt){
    int n, e; cin >> n >> e;
    vector<array<int, 3>>edge;
    while(e--) {
        int uu, vv, ww;
        cin >> uu >> vv >> ww;
        edge.push_back({ww, uu, vv});
    }
    sort(edge.begin(), edge.end());

    vector<pair<int, int>>mst[n + 5];

    int mn = 0;
    init_rep(n);
    for (auto x : edge) {
        if (find_rep(x[1]) == find_rep(x[2])) continue;
        mst[x[1]].push_back({x[2], x[0]});
        mst[x[2]].push_back({x[1], x[0]});
        mn += x[0];
        update_rep(x[1], x[2]);
    }
    cout << mn << endl;
}

int32_t main(){
    sol(1);
    return 0;
}
