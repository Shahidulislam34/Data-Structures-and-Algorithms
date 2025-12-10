#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<pair<int, int>>>gra;
vector<vector<int>>bt;
vector<int>low, dis, stk, id;
vector<bool>isbridge;
int n, m, timer = 0, sz = 0;
void finding_bridges(int cn, int anc = 0) {
    low[cn] = dis[cn] = ++timer;
    stk.push_back(cn);
    for (auto [chi, edge] : gra[cn]) {
        if (chi == anc) continue;
        if (dis[chi]) low[cn] = min(low[cn], dis[chi]);
        else {
            finding_bridges(chi, cn);
            low[cn] = min(low[cn], low[chi]);
            if (dis[cn] < low[chi]) {
                isbridge[edge] = true;
                ++sz;
                while(stk.back() != chi)
                    id[stk.back()] = sz, stk.pop_back();
                id[stk.back()] = sz;
                stk.pop_back();
            }
        }
    }
    //only for root
    if (anc == 0) {
        ++sz;
        while(!stk.empty())
            id[stk.back()] = sz, stk.pop_back();
    }
}
void build_tree() {
    bt.resize(1);//for one base indexing
    for (int i = 1; i <= sz; ++i) bt.push_back({});
    for (int i = 1; i <= n; ++i) {
        for (auto [chi, edge] : gra[i]) {
            if (isbridge[edge]) bt[id[chi]].push_back(id[i]);
            //it will be bidirectional after ending the processes
        }
    }
}

void sol(int ttt){
    cin >> n >> m;
    //initialization part
    gra.resize(n + 5);
    low.assign(n + 5, 0);
    dis.assign(n + 5, 0);
    id.resize(n + 5);
    isbridge.assign(m + 5, false);//size of edges

    for (int i = 1; i <= m; ++i) {
        int uu, vv; cin >> uu >> vv;
        gra[uu].push_back({vv, i});
        gra[vv].push_back({uu, i});
    }
    finding_bridges(1);
    build_tree();
    //print tree:
    for (int i = 1; i <= sz; ++i) {
        cout << "adjacent of :" << i << endl;
        for (auto node : bt[i]) cout << node << ' '; cout << endl;
    }
}

int32_t main(){
    sol(1);
    return 0;
}
