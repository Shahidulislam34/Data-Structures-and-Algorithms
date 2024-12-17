#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

///2D BIT-----1 base
const int N = 1e3;
int bit[N + 5][N + 5];
int n, q;

void update(int xx, int yy, int val) {
    for (int i = xx; i <= n; i += (i & -i))
        for (int j = yy; j <= n; j += (j & -j))
            bit[i][j] += val;
}

int query(int xx, int yy) {
    int sum = 0;
    for (int i = xx; i > 0; i -= (i & -i))
        for (int j = yy; j > 0; j -= (j & -j))
            sum += bit[i][j];
    return sum;
}
///2D BIT----

void sol(){
    cin >> n >> q;//n * n grid
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int val; cin >> val;
            update(i, j, val);
        }
    }
    while(q--) {
        int option;
        cin >> option;
        if (option == 1) {
            int x, y, val; cin >> x >> y >> val;
            update(x, y, val);
        }
        else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int res = query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
            cout << res << endl;
        }
    }
}

int32_t main(){
    faster();
    int tt = 1;
//    cin >> tt;
    while(tt--) sol();
    return 0;
}
