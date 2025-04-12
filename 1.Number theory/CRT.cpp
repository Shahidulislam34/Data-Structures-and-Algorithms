#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int M2 = 998244353;
const int N = (int)1e7;
const int Inf = LLONG_MAX;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

///CRT----O(nlogn)
int egcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gc = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gc;
}
int mva(int a, int b, int m) {
    if (b == 0) return 0ll;
    else if (b == 1) return a;

    int x, y;
    if (b % 2 == 0) x = y = mva(a, b / 2, m);
    else x = mva(a, b - 1, m), y = a;

    if (m - x <= y) return (y - (m - x));
    else return x + y;
}
pair<int, int> crt(vector<int>&mod, vector<int>&rem) {
    int n = mod.size();
    int a1 = rem[0], m1 = mod[0];
    for (int i = 1; i < n; ++i) {
        int a2 = rem[i], m2 = mod[i];
        int gc = __gcd(m1, m2);
        if (a1 % gc != a2 % gc) return {-1, -1};//solution does't exist
        int p, q, lcm = (m1 * m2) / gc;
        int tmp = egcd(m1 / gc, m2 / gc, p, q);
        p = (p % m2 + m2) % m2;
        q = (q % m1 + m1) % m1;
        a1 = (mva(mva(a1, m2 / gc, lcm), q, lcm) + mva(mva(a2, m1 / gc, lcm), p, lcm)) % lcm;
        a1 = (a1 % lcm + lcm) % lcm;
        m1 = lcm;
    }
    return {a1, m1};
}
///CRT----

int32_t main(){
    faster();

    int n; cin >> n;
    vector<int>mod(n), rem(n);
    for (int i = 0; i < n; ++i) cin >> mod[i];
    for (int i = 0; i < n; ++i) cin >> rem[i];
    auto [x, lcm] = crt(mod, rem);
    if (x == -1) cout << "No Solution" << endl;
    else cout << x << ' ' << lcm << endl;

    return 0;
}
