#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int M2 = 998244353;
const int N = 1e6;
const int Inf = 1e18;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

///nCr----
vector<int>Fac(N + 5), Inv(N + 5);
int mod_exp(int base, int power, int M) {
    int res = 1;
    while(power) {
        if (power % 2) res = (res % M * base % M) % M, --power;
        else base = (base % M * base % M) % M, power /= 2;
    }
    return res;
}

void prec(int nn) {
    Fac[0] = 1;
    for (int i = 1; i <= nn; ++i)
        Fac[i] = (Fac[i - 1] % M1 * i % M1) % M1;
    for (int i = 0; i <= nn; ++i)
        Inv[i] = mod_exp(Fac[i], M1 - 2, M1);
}
int nCr(int nn, int rr) {
    if (nn < 0 || rr < 0) return 0;
    if (nn < rr) swap(nn, rr);
    return ((Fac[nn] * Inv[nn - rr]) % M1 * Inv[rr]) % M1;
}
///nCr----

int32_t main(){
    faster();
    prec(N);
    int n, r; cin >> n >> r;
    cout << nCr(n, r) << endl;
    return 0;
}


