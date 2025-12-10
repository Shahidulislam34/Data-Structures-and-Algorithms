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

