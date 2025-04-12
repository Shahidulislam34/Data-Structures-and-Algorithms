#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

///nCr % m---m is prime or not----m <= 1e6----O(m)
vector<pair<int, int>>Pf;
vector<int>Spf;
int egcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return x;
    }
    int x1, y1;
    int gc = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return x;
}
int mul_via_add(int a, int b, int m) {
    if (b == 0) return 0ll;
    else if (b == 1) return a;

    int x, y;
    if (b % 2 == 0) x = y = mul_via_add(a, b / 2, m);
    else x = mul_via_add(a, b - 1, m), y = a;

    if (m - x <= y) return (y - (m - x));
    else return x + y;
}
int crt(vector<int>&mod, vector<int>&rem, int n) {
    int prod = 1, res = 0;
    for (int i = 0; i < n; ++i) prod *= mod[i];

    for (int i = 0; i < n; ++i) {
        int Mi = prod / mod[i], x, y;
        x = egcd(Mi, mod[i], x, y);
        int inv = (x % mod[i] + mod[i]) % mod[i];
        res += mul_via_add((rem[i] * Mi) % prod, inv, prod);
        res %=prod;
    }
    return res;
}
int mod_expo(int base, int power, int m) {
    int res = 1;
    while(power) {
        if (power % 2) res = (res % m * base % m) % m, --power;
        else base = (base % m * base % m) % m, power /= 2;
    }
    return res;
}
int inverse(int a, int m) {
    int x, y;
    if (__gcd(a, m) != 1) return -1;
    else return(egcd(a, m, x, y) % m + m) % m;
}
int factMod(int n, int pi, int m) {
    ///calculate n! % m = ? without any factor pi
    int f[m + 5];
    f[0] = 1 % m;
    for (int i = 1; i <= m; ++i) f[i] = (f[i - 1] * (i % pi == 0 ? 1 : i)) % m;
    int res = 1 % m;
    while(n > 1) {
        res = (res * f[n % m]) % m;
        res = (res * mod_expo(f[m], n / m, m)) % m;
        n /= pi;
    }
    return res;
}
int multiplicity(int m, int f) {
    int cnt = 0, mul = f;
    while(mul <= m) {
        cnt += (m / mul);
        mul *= f;
    }
    return cnt;
}
pair<int, int> ncrPiai(int n, int r, int pi, int ai) {
    int x = multiplicity(r, pi), y = multiplicity(n - r, pi), z = multiplicity(n, pi);
    int m = 1;
    for (int i = 1; i <= ai; ++i) m *= pi;
    if (z - x - y >= ai) return {m, 0};
    else {
        int res =((factMod(n, pi, m) * inverse(factMod(r, pi, m), m) % m) * inverse(factMod(n - r, pi, m), m)) % m;
        res = (res * mod_expo(pi, z - x - y, m)) % m;
        return {m, res};
    }
}
void pf(int n) {
    int val = n, cnt = 0, factor = Spf[n];
    while(val > 1){
        if (Spf[val] != factor) {
            Pf.push_back({factor, cnt});
            cnt = 0;
            factor = Spf[val];
        }
        val /= Spf[val];
        ++cnt;
    }
    Pf.push_back({factor, cnt});
}
int ncr(int n, int r, int m) {
    if (n < r || r < 0 || m == 1) return 0;
    Pf.clear();
    pf(m);
    vector<int>mi, ai;
    for (auto [pj, aj] : Pf) {
        auto val = ncrPiai(n, r, pj, aj);
        mi.push_back(val.first);
        ai.push_back(val.second);
    }
    return crt(mi, ai, mi.size());
}
void spf(int n) {
    Spf.resize(n + 5);
    for (int i = 1; i <= n; ++i) Spf[i] = i;
    for (int i = 2; i <= n; ++i) {
        if (Spf[i] == i) {
            for (int j = i; j <= n; j += i)
                Spf[j] = min(Spf[j], i);
        }
    }
}
///nCr % m----

int32_t main(){
    ///calculate nCr % m = ?---m is any value(prime or not)---1 <= n, r <= 1e18 and 1 <= m <= 1e6
    spf((int)1e6);

    int n, r, m; cin >> n >> r >> m;
    cout << ncr(n, r, m) << endl;
}
