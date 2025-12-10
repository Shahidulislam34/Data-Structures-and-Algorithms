#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

vector<vector<int>>gra, bcc, bct;
vector<int>art, low, dis, stk, id;
int n, e, timer = 0, sz = 0;
void build_bcc(int cn, int anc = 0) {
    low[cn] = dis[cn] = ++timer;
    stk.push_back(cn);
    for (int chi : gra[cn]) {
        if (chi == anc) continue;
        if (dis[chi]) low[cn] = min(low[cn], dis[chi]);
        else {
            build_bcc(chi, cn);
            low[cn] = min(low[cn], low[chi]);
            if (dis[cn] <= low[chi]) {
                art[cn] = dis[cn] > 1 || dis[chi] > 2;
                bcc.push_back({cn});
                while(bcc.back().back() != chi)
                    bcc.back().push_back(stk.back()), stk.pop_back();
            }
        }
    }
}
void build_bct() {
    bct.resize(1);//1 for one base indexing
    for (int i = 1; i <= n; ++i) {
        if (art[i]) bct.push_back({}), id[i] = ++sz;
    }
    for (auto comp : bcc) {
        bct.push_back({});
        ++sz;
        for (auto node : comp) {
            if (art[node] == 0) id[node] = sz;
            else {
                bct[sz].push_back(id[node]);
                bct[id[node]].push_back(sz);
            }
        }
    }
}

void sol(){
    cin >> n >> e;
    gra.resize(n + 5);
    while(e--) {
        int uu, vv; cin >> uu >> vv;
        gra[uu].push_back(vv);
        gra[vv].push_back(uu);
    }

    art.assign(n + 5, 0);
    low.assign(n + 5, 0);
    dis.assign(n + 5, 0);
    build_bcc(1);
    //print bcc: zero base indexing
    for (auto comp : bcc) {
        for (auto node : comp) cout << node << ' '; cout << endl;
    }
    id.resize(n + 5);
    build_bct();
    //print id
    for (int i = 1; i <= sz; ++i) cout << id[i] << ' '; cout << endl;
    //print bct: one base indexing
    for (int i = 1; i <= sz; ++i) {
        cout << "i:" << i << endl;
        for (auto chi : bct[i]) cout << chi << ' '; cout << endl;
    }
}

int32_t main(){
    faster();
    int tt = 1;
//    cin >> tt;
    while(tt--) sol();
    return 0;
}
