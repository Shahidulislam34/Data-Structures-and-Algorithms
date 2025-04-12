#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

///lucas theorem----O(m)
vector<int>Fac, Inv;
int lucas_theorem(int n, int r, int m) {
    if (r == 0) return 1;
    int ni = n % m, ri = r % m;
    if (ni < ri) return 0;
    return (lucas_theorem(n / m, r / m, m) *
            ((Fac[ni] * Inv[ni - ri]) % m * Inv[ri]) % m) % m;
}
int mod_expo(int base, int power, int M) {
    int res = 1;
    while(power) {
        if (power % 2) res = (res % M * base % M) % M, --power;
        else base = (base % M * base % M) % M, power /= 2;
    }
    return res;
}
int nCr(int n, int r, int m) {
    Fac.resize(m + 5);
    Inv.resize(m + 5);
    Fac[0] = 1;
    for (int i = 1; i <= m - 1; ++i) Fac[i] = (Fac[i - 1] * i) % m;
    Inv[m - 1] = mod_expo(Fac[m - 1], m - 2, m);
    for (int i = m - 2; i >= 0; --i) Inv[i] = (Inv[i + 1] * (i + 1)) % m;

    return lucas_theorem(n, r, m);
}
///lucas theorem----

int32_t main(){
    ///calculate nCr % m = ? where m is always prime and m is small

    int n, r, m; cin >> n >> r >> m;
    int res = nCr(n, r, m);
    cout << res << endl;
}





