#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int M2 = 998244353;
const int N = (int)2e5;
const int Inf = 1e18;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

int dis_log(int a, int b, int m) {
    a %= m; b %= m;
    int n = sqrtl(m) + 1;
    unordered_map<int, int>dan;//min solution
    int mul = b;
    for (int q = 0; q < n; ++q) {
        dan[mul] = q;
        mul = (1ll * mul * a) % m;
    }
    mul = 1;
    for (int i = 1; i <= n; ++i) {
        mul = (1ll * mul * a) % m;
    }
    int bam = mul;
    for (int p = 1; p <= n; ++p) {
        if (dan.find(bam) != dan.end()) {
            return (n * p - dan[bam]);
        }
        bam = (1ll * bam * mul) % m;
    }
    return -1;
}

void sol(int ttt){
    int a, x, b, m; cin >> a >> b >> m;
    cout << dis_log(a, b, m) << endl;
}

int32_t main(){
    faster();
    //freopen("lcm.in", "r", stdin);
    int ttt = 1;
    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) sol(iii);
    return 0;
}
