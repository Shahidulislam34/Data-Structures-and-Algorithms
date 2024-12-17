#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int N = 2e5;
vector<int>Tree[N + 1];
int n;

array<int, 2> bfs(int par) {
    vector<int>vis(n + 1), dis(n + 1, 0);
    fill(vis.begin(), vis.begin() + n + 1, false);
    fill(dis.begin(), dis.begin() + n + 1, 0);

    queue<int>qq;
    qq.push(par);
    vis[par] = 1;
    int mx = 0, node = par;
    while(!qq.empty()) {
        par = qq.front();
        qq.pop();
        for (auto chi : Tree[par]) {
            if (vis[chi] == false) {
                vis[chi] = true;
                qq.push(chi);
                dis[chi] = dis[par] + 1;
                mx = dis[chi];
                node = chi;
            }
        }
    }
    return {mx, node};
}

void sol(){
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int uu, vv; cin >> uu >> vv;
        Tree[uu].push_back(vv);
        Tree[vv].push_back(uu);
    }
    array<int, 2>end1 = bfs(1);///lon[0] = mx_distance, lon[1] = node
    array<int, 2>end2 = bfs(end1[1]);
    cout << end2[0] << endl;
}

int32_t main(){
    faster();
    int tt = 1;
//    cin >> tt;
    while(tt--) sol();
    return 0;
}





