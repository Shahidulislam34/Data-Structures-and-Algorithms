#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int>v(n);
    for (auto &x : v) cin >> x;
    ///remove consecutive duplicate value
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto x : v) cout << x << ' '; cout << endl;

    return 0;
}
