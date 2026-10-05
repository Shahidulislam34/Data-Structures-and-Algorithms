#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = (int)3e5;
const int Inf = (int)1e18;

vector<int>dis(N + 5, Inf);
void dijkstra(int n, int src, vector<pair<int, int>>gra[]) {
    for (int i = 1; i <= n; ++i) dis[i] = Inf;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    dis[src] = 0;
    pq.push({0, src});
    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u]) continue;
        for (auto [v, w] : gra[u]) {
            int ncost = dis[u] + w;
            if (ncost < dis[v]) {
                pq.push({ncost, v});
                dis[v] = ncost;
            }
        }
    }
}

void sol(int ttt){
    int n, e; cin >> n >> e;
    vector<pair<int, int>>gra[n + 5];
    while(e--) {
        int uu, vv, ww; cin >> uu >> vv >> ww;
        gra[uu].push_back({vv, ww});
        gra[vv].push_back({uu, ww});
    }
    dijkstra(1, n, gra);
    for (int i = 1; i <= n; ++i) cout << dis[i] << ' '; cout << endl;
}

int32_t main(){
//    faster();
    //freopen("lcm.in", "r", stdin);
    int ttt = 1;
//    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) sol(iii);
    return 0;
}

