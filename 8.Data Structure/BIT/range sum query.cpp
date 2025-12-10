#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

///BIT-----1 base
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
///BIT----
update(ind, val);
val = query(b) - query(a - 1);

void sol(){
    cin >> n >> q;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i], update(i, v[i]);

    while(q--) {
        int a, b; cin >> a >> b;
        cout << query(b) - query(a - 1) << endl;
    }
}

int32_t main(){
//    faster();
    int tt = 1;
//    cin >> tt;
    while(tt--) sol();
    return 0;
}


