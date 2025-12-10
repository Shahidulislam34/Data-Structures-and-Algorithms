#include<iostream>
using namespace std;
//#define int long long
const int M = 998244353;

///modular expnentiation starts----
int mod_expo(int base, int power, int m) {
    int res = 1;
    while(power) {
        if (power % 2) res = (1ll * res % m * base % m) % m, --power;
        else base = (1ll * base % m * base % m) % m, power /= 2;
    }
    return res;
}
///ends----

int flt(int a, int m) {
    return mod_expo(a, m - 2, m) % m;
}

int32_t main(){
    cout << (1ll * 24 * mod_expo(7, M-2, M)) % M << endl;
    int base, power;
    cin >> base >> power;
    cout << mod_expo(base, power, M) << endl;
    return 0;
}
