#include<bits/stdc++.h>
using namespace std;
#define int long long

///sum of geometric series----nlogn
int mod_expo(int base, int power, int M) {
    int res = 1;
    while(power) {
        if (power % 2) res = (res % M * base % M) % M, --power;
        else base = (base % M * base % M) % M, power /= 2;
    }
    return res;
}

int sum_of_gs(int x, int n, int m) {
    if (n == 0) return 1 % m;
    else if (n == 1) return x % m;

    if (n % 2 == 0) return (sum_of_gs(x, n / 2, m) * (1 + mod_expo(x, n / 2, m))) % m;///f(n/2) * (1 + x^(n/2))
    else return (sum_of_gs(x, n - 1, m) + mod_expo(x, n, m)) % m;///f(n - 1) + x^n
}
///sum of geometric series----

int32_t main() {
    ///(x^1 + x^2 + x^3 + ..... + x^n) % M = ?

    int x, n, m;
    cin >> x >> n >> m;
    cout << sum_of_gs(x, n, m) << endl;
    return 0;
}
