#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
vector<pair<int, int>>graph[N + 5];
vector<int>dis(N + 5);

void zero_one_bfs(int sou) {
    deque<int>dq;
    dq.push_front(sou);
    dis[sou] = 0;
    while(!dq.empty()) {
        int node = dq.front();
        dq.pop_front();
        for(auto [x, y] : graph[node]) {
            if (dis[x] > dis[node] + y) {
                dis[x] = dis[node] + y;
                if (y == 0) dq.push_front(x);
                else dq.push_back(x);
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 1; i <= n; ++i) graph[i].clear(), dis[i] = INT_MAX;
    while(e--) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].emplace_back(b, w);
        graph[b].emplace_back(a, w);
    }
    zero_one_bfs(1);
    for (int i = 1; i <= n; ++i) cout << dis[i] << ' '; cout << endl;
    return 0;
}
