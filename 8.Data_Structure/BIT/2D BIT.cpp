#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

///BIT-----1 base
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

///BIT----

void sol(){
    cin >> n >> q;
    int vec[n + 5][n + 5];
    memset(vec, 0, sizeof(vec));
    for (int i = 1; i <= n; ++i) {
        string str; cin >> str;
        for (int j = 0; j < n; ++j) {
            if (str[j] == '*') {
                update(i, j + 1, 1);
                vec[i][j + 1] = 1;
            }
        }
    }
    while(q--) {
        int option;
        cin >> option;
        if (option == 1) {
            int x, y; cin >> x >> y;
            if (vec[x][y] == 0) update(x, y, 1);
            else update(x, y, -1);
            vec[x][y] ^= 1;
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
