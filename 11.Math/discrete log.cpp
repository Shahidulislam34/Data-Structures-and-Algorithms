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
    if (b == 1) return 0;
    int n = sqrtl(m);//n is fixed, length of portions
    unordered_map<int, int>jiant;
    int mul = b;
    for (int q = 0; q < n; ++q) {
        jiant[mul] = q;
        mul = (1ll * mul * a) % m;
    }
    mul = 1;
    for (int i = 1; i <= n; ++i) {
        mul = (1ll * mul * a) % m;
    }
    int baby = mul;
    for (int p = 1; p <= n + 1; ++p) {
        if (jiant.find(baby) != jiant.end()) {
            return (n * p - jiant[baby]);
        }
        baby = (1ll * baby * mul) % m;
    }
    return -1;
}

void sol(int ttt){
    int a, b, m; cin >> a >> b >> m;//if a^x = b (mod m) then x = ?
    //if gcd(a, m) == 1,then always atleast one x is exist.otherwise exist or not.
    int x = dis_log(a, b, m);
    cout << x << endl;
}

int32_t main(){
//    faster();
    //freopen("lcm.in", "r", stdin);
    int ttt = 1;
    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) sol(iii);
    return 0;
}
