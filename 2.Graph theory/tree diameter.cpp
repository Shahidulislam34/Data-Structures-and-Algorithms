#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int N = 2e5;
vector<int>Tree[N + 1];
int n;

vector<int>dep;
int diameter(int cn, int anc = 0, int lev = 0) {
    dep[cn] = lev;
    int u = cn;
    for (auto chi : Tree[cn]) if (chi != anc) {
        int v = diameter(chi, cn, lev + 1);
        if (dep[u] < dep[v]) u = v;
    }
    return u;
}

void sol(){
    cin >> n;
    for (int i = 2; i <= n; ++i) {
        int uu, vv; cin >> uu >> vv;
        Tree[uu].push_back(vv);
        Tree[vv].push_back(uu);
    }
    dep.resize(n + 5);
    cout << dep[diameter(diameter(1))] << endl;
}

int32_t main(){
    faster();
    int tt = 1;
//    cin >> tt;
    while(tt--) sol();
    return 0;
}
