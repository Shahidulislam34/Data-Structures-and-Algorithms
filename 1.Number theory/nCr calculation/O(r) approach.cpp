#include<bits/stdc++.h>
using namespace std;
#define int long long

///ncr---O(r)
int nCr(int n, int r) {
    ///calculate exact value of nCr(without mod).Ans should be in the limit of long long
    int res = 1;
    for (int i = 1; i <= r; ++i) {
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}
///nCr----

void sol(){
    ///calculate exact value of nCr = ?(without mod)
    int n, r; cin >> n >> r;
    int res = nCr(n, r);
    cout << res << endl;
}

int32_t main(){
    sol();
    return 0;
}



