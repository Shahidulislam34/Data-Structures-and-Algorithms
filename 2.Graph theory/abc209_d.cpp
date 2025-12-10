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

vector<vector<int>>tree;
vector<int>col;
void dfs(int cn, int par = 0) {
    col[cn] = col[par] ^ 1;
    for (auto chi : tree[cn]) {
        if (chi != par) dfs(chi, cn);
    }
}

void sol(int ttt){
    int n, q; cin >> n >> q;
    tree.resize(n + 5);
    for (int i = 1; i <= n; ++i) tree[i].clear();
    for (int i = 1; i <= n - 1; ++i) {
        int uu, vv; cin >> uu >> vv;
        tree[uu].push_back(vv);
        tree[vv].push_back(uu);
    }

    col.assign(n + 5, 0);
    dfs(1);

    while(q--) {
        int uu, vv; cin >> uu >> vv;
        if (col[uu] == col[vv]) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
}

int32_t main(){
    faster();
    //freopen("lcm.in", "r", stdin);
    int ttt = 1;
//    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) sol(iii);
    return 0;
}
