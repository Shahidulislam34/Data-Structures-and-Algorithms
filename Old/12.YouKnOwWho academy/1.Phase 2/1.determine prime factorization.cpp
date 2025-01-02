#include<bits/stdc++.h>
using namespace std;

///ordered_set------zero base index-----only for 'int' data type
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <typename T> using o_set = tree<T, null_type,
//less<T>, rb_tree_tag, tree_order_statistics_node_update>;
///ordered_set-------

#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int inf = LLONG_MAX;
const int M1 = 1e9 + 7;
int xor_range(int m) {
    if (m % 4 == 0) return m;
    else if (m % 4 == 1) return 1;
    else if (m % 4 == 2) return m + 1;
    else return 0;
}

///prime factor from 1 to 1e6----nlogn
const int N = 1e6;
vector<pair<int, int>>pv[N + 1];
void prime_factor() {
    vector<int>tmp(N + 1);
    for (int i = 1; i <= N; ++i) tmp[i] = i;
    for (int i = 2; i * i <= N; ++i) {
        for (int j = i * i; j <= N; j += i)
            tmp[j] = min(tmp[j], i);
    }
    pv[1].push_back({1, 0});
    for (int i = 2; i <= N; ++i) {
        int val = i, base = tmp[val], cnt = 0;
        while(val > 1) {
            if (tmp[val] != base) {
                pv[i].push_back({base, cnt});
                cnt = 0;
            }
            base = tmp[val];
            val /= base;
            ++cnt;
        }
        pv[i].push_back({base, cnt});
    }
}
///prime factor ends----

int32_t main(){
    faster();
    prime_factor();

    for (int i = 1; i <= 10; ++i) {
        cout << "prime factor of i:" << i << endl;
        for (auto [x, y] : pv[i]) cout << x << "^" << y << "*";
        cout << endl;
    }

    return 0;
}



