#include<bits/stdc++.h>
using namespace std;

//bicolorable or not----
bool bicolorable(int node, vector<vector<int>>&adj) {
    vector<int>col(node + 1, -1);

    for (int i = 1; i <= node; ++i) {
        if (col[i] != -1) continue;
        queue<int>qu;
        qu.push(i);
        col[i] = 1;
        while(!qu.empty()) {
            int ver = qu.front();
            qu.pop();
            for (auto x : adj[ver]) {
                if (col[x] == -1) {
                    qu.push(x);
                    col[x] = col[ver] ^ 1;
                }
                else if (col[x] == col[ver]) return false;
            }
        }
    }
    return true;
}
//bicolorable or not----

int main() {
    int n, e; cin >> n >> e;
    vector<vector<int>>adj(n + 1);
    for (int i = 1; i <= e; ++i) {
        int uu, vv; cin >> uu >> vv;
        adj[uu].push_back(vv);
        adj[vv].push_back(uu);
    }
    if (bicolorable(n, adj)) cout << "Bicolorable" << endl;
    else cout << "Not Bicolorable" << endl;

    return 0;
}
