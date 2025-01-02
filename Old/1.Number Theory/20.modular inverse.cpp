#include<bits/stdc++.h>
using namespace std;

int inverse(int base, int power, int mod){
    int ans = 0;
    while(power != 0){
        if(power % 2 == 0) base = (1LL * base * base) % mod, power /= 2;
        else ans = (1LL * ans + base) % mod, --power;
    }
    return ans;
}

int32_t main(){
    int a, b, m;///where gcd(b, m) = 1 & (a / b) % m = ((a % p) * (b^-1) % p) % p = ?
    cin >> a >> b >> m;
    int res = ((a % m) * (inverse(b, m - 2, m) % m)) % m;
    cout << res << endl;
}
