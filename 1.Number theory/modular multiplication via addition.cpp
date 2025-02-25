#include<iostream>
#include<vector>
using namespace std;
#define int long long
const int N = (int)1e6;

///modular multiplication via addition----blogb
int mul_via_add(int a, int b, int m) {
    if (b == 0) return 0ll;
    else if (b == 1) return a;

    int x, y;
    if (b % 2 == 0) x = y = mul_via_add(a, b / 2, m);
    else x = mul_via_add(a, b - 1, m), y = a;

    if (m - x <= y) return (y - (m - x));
    else return x + y;
}
///modular multiplication via addition----

int32_t main(){
    /// (a * b) % m = ?...where 1 <= a, b, c <= LLONG_MAX;
    int a, b, m; cin >> a >> b >> m;
    cout << mul_via_add(a % m, b % m, m) << endl;

    return 0;
}


