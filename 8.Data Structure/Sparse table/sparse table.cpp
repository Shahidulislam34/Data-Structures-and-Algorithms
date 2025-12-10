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
//const int N = (int)300;
const int Inf = INT_MAX;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

///sparse table----O(nlogn)
const int N = 3000005;
int Table[N + 5][22];
vector<int>Log(N + 5);
void log2_floor(int n) {
    Log[1] = 0;
    for (int i = 2; i <= n; ++i) Log[i] = Log[i / 2] + 1;
}
void init_table(vector<int>&v, int n) {
    for (int i = 1; i <= n; ++i) Table[i][0] = v[i];
    for (int j = 1; j <= Log[n]; ++j) {
        for (int i = 1; i <= (n - (1 << j) + 1); ++i) {
            Table[i][j] = __gcd(Table[i][j - 1], Table[i + (1 << (j - 1))][j - 1]);///Modifiable
        }
    }
}

int get_table(int a, int b) {
    int lg = Log[b - a + 1];
    return __gcd(Table[a][lg], Table[b - (1 << lg) + 1][lg]);///Modifiable
}
///sparse table----

void sol(int ttt){
    int n; cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    init_table(v, n);

    int q; cin >> q;
    while(q--) {
        int a, b;
        cout << get_table(a, b) << endl;
    }
}

int32_t main(){
    faster();
    log2_floor(N);
    //freopen("lcm.in", "r", stdin);
    int ttt = 1;
//    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) sol(iii);
    return 0;
}


