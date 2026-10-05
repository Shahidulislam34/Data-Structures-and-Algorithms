#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

const int N = 2e5;
vector<int>bit(N + 5);
int n, q;

void update(int idx, int val) {
    while(idx <= n) {
        bit[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += bit[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void sol(){
    cin >> n >> q;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    map<int, int>bef;
    vector<int>nxt(n + 5, 0);
    for (int i = 1; i <= n; ++i) {
        if (bef[v[i]]) nxt[bef[v[i]]] = i;
        else update(i, 1);
        bef[v[i]] = i;
    }

    array<int, 3>que[q + 5];
    for (int i = 1; i <= q; ++i) {
        int a, b; cin >> a >> b;
        que[i] = {a, b, i};
    }
    sort(que + 1, que + q + 1);

    int ini = 1;
    vector<int>res(q + 5);
    for (int i = 1; i <= q; ++i) {
        while(ini < que[i][0]) {
            if (nxt[ini])
                update(nxt[ini], 1);
            ++ini;
        }
        res[que[i][2]] = query(que[i][1]) - query(que[i][0] - 1);
    }
    for (int i = 1; i <= q; ++i) cout << res[i] << endl;
}

int32_t main(){
    faster();
    int tt = 1;
//    cin >> tt;
    while(tt--) sol();
    return 0;
}

//CSES 1734= Distinct Values Queries
