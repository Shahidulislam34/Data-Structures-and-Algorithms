#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

///Lca starts ------root 1
int lg = 22;
vector<vector<int>>tree, up;
vector<int>dep;
void dfs(int cn, int par = 0) {
    dep[cn] = dep[par] + 1;//dep[0] = -1 initially
    up[cn][0] = par;
    for (int i = 1; i <= lg; ++i) up[cn][i] = up[up[cn][i - 1]][i - 1];//na thakle 0
    for (int chi : tree[cn]) {
        if (chi != par) dfs(chi, cn);
    }
}
int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = lg; i >= 0; --i) if (dep[up[a][i]] >= dep[b]) a = up[a][i];
    if (a == b) return a;
    for (int i = lg; i >= 0; --i) if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i];
    return up[a][0];
}
///Lca ends----

void sol(){
    int n, e; cin >> n >> e;
    tree.resize(n + 5);
    while(e--) {
        int uu, vv; cin >> uu >> vv;
        tree[uu].push_back(vv);
        tree[vv].push_back(uu);
    }

    dep.resize(n + 5, -1);
    up.assign(n + 5, vector<int>(lg + 5, 0));
    dfs(1);//root 1

    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
    }

}

int32_t main(){
    faster();
    int tt = 1;
//    cin >> tt;
    while(tt--) sol();
    return 0;
}


