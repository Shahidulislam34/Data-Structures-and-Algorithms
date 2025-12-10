#include<bits/stdc++.h>
using namespace std;

int32_t main() {
    int n; cin >> n;
    vector<int>v(n);
    for (auto &x : v) cin >> x;

    int sum = accumulate(v.begin(), v.end(), 3);//initially sum = 3, sum = 3 + v[0] + v[1]..
    cout << sum << endl;

    return 0;
}
