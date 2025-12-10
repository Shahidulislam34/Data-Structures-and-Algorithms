#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

///nCr----O(n)
int N = 1e6;
vector<int>Fac(N + 5), Inv(N + 5);
const int M1 = (int)1e9 + 7;
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
    Inv[nn] = mod_exp(Fac[nn], M1 - 2, M1);
    for (int i = nn - 1; i >= 0; --i)
        Inv[i] = (Inv[i + 1] * (i + 1)) % M1;
}

int nCr(int nn, int rr) {
    if (nn < 0 || rr < 0 || nn < rr) return 0;
    return ((Fac[nn] * Inv[nn - rr]) % M1 * Inv[rr]) % M1;
}
///nCr----

void sol(){
    ///calculate the value of nCr % M = ?. M always prime & 1 <= n,r <= 1e6.
    prec(N);

    ///query = O(1)
    while(1) {
        int n, r; cin >> n >> r;
        cout << nCr(n, r) << endl;
    }
}

int32_t main(){
    sol();
    return 0;
}




