#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<vector<pair<int, int>>>gra;
vector<vector<int>>bc;
vector<int>low, dis, stk;
int n, m, timer = 0;
void bridge_components(int cn, int anc = 0) {
    low[cn] = dis[cn] = ++timer;
    stk.push_back(cn);
    for (auto [chi, edge] : gra[cn]) {
        if (chi == anc) continue;
        if (dis[chi]) low[cn] = min(low[cn], dis[chi]);
        else {
            bridge_components(chi, cn);
            low[cn] = min(low[cn], low[chi]);
            if (dis[cn] < low[chi]) {
                bc.push_back({stk.back()});
                stk.pop_back();
                while(bc.back().back() != chi)
                    bc.back().push_back(stk.back()), stk.pop_back();
            }
        }
    }
    //only for root
    if (anc == 0) {
        bc.push_back({});
        while(!stk.empty())
            bc.back().push_back(stk.back()), stk.pop_back();
    }
}

void sol(int ttt){
    cin >> n >> m;
    //initialization part
    gra.resize(n + 5);
    low.assign(n + 5, 0);
    dis.assign(n + 5, 0);

    for (int i = 1; i <= m; ++i) {
        int uu, vv; cin >> uu >> vv;
        gra[uu].push_back({vv, i});
        gra[vv].push_back({uu, i});
    }
    bridge_components(1);
    for (auto comp : bc) {//zero base indexing of bc
        for (auto node : comp) cout << node << ' '; cout << endl;
    }
}

int32_t main(){
    sol(1);
    return 0;
}

