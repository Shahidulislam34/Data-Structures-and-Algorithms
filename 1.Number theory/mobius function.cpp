#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

///mobius starts----nlogn
const int N = (int)1e7;
vector<int>Mob(N + 1);
void mobius(int nn) {
    for (int i = 1; i <= nn; ++i) Mob[i] = 1;
    vector<bool>vis(nn + 1, false);
    for (int i = 2; i <= nn; ++i) {
        if (vis[i] == false) {
            for (int j = i; j <= nn; j += i) {
                Mob[j] *= -1;
                vis[j] = true;
            }
            for (int j = i * i; j <= nn; j += i * i)
                Mob[j] = 0;
        }
    }
}
///mobius ends----

int32_t main() {
    int n; cin >> n;
    mobius(n);
    for (int i = 1; i <= n; ++i) cout << Mob[i] << ' '; cout << endl;

    return 0;
}
