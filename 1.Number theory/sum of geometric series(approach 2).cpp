#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ///(x^1 + x^2 + x^3 + ..... + x^n) % M = ?

    int x, n, m;
    cin >> x >> n >> m;
    cout << sum_of_gs(x, n) << endl;
    return 0;
}

