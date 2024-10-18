#include<bits/stdc++.h>
using namespace std;
#define int long long

mt19937_64 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
int ran_gen(int x, int y) {
  return uniform_int_distribution<int>(x, y)(rng);
}

int32_t main() {
    int n;
    cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) v[i] = ran_gen(1, n);///for range

    for (int i = 1; i <= n; ++i) cout << v[i] << ' '; cout << endl;
    shuffle(v.begin() + 1, v.begin() + n + 1, rng);
    for (int i = 1; i <= n; ++i) cout << v[i] << ' '; cout << endl;

    int any = rng();/// for any long long value
    cout << any << endl;

    return 0;
}
