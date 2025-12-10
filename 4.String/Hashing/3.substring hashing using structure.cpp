#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'

const int B1 = 283, B2 = 293, M1 = 1e9 + 87, M2 = 1e9 + 93, N = 2e6;
pair<int, int>Pow[N + 5], IPow[N + 5];
int big_mod(int base, int Power, int mod){
    int res = 1;
    while (Power != 0){
        if (Power % 2 == 0) base = (1LL * base * base) % mod, Power /= 2;
        else res = (1LL * res * base) % mod, --Power;
    }
    return res;
}
void prec_hash(){
    Pow[0] = {1, 1};
    for (int i = 1; i <= N; ++i){
        Pow[i].first = (1LL * Pow[i - 1].first * B1) % M1;
        Pow[i].second = (1LL * Pow[i - 1].second * B2) % M2;
    }
    int ip1 = big_mod(B1, M1 - 2, M1);
    int ip2 = big_mod(B2, M2 - 2, M2);
    IPow[0] = {1, 1};
    for (int i = 1; i <= N; ++i){
        IPow[i].first = (1LL * IPow[i - 1].first * ip1) % M1;
        IPow[i].second = (1LL * IPow[i - 1].second * ip2) % M2;
    }
}
struct hashing {
    vector<pair<int, int>>pre;
    hashing(int n) {
        pre.resize(n);
    }
    void init_hash(string str){
        pre[0] = {str[0], str[0]};
        int ZZ = str.size();
        for (int i = 1; i < ZZ; ++i){
            pre[i].first = pre[i - 1].first + (1LL * str[i] * Pow[i].first) % M1;
            pre[i].first %= M1;
            pre[i].second = pre[i - 1].second + (1LL * str[i] * Pow[i].second) % M2;
            pre[i].second %= M2;
        }
    }
    pair<int, int> get_hash(int l, int r){
        pair<int, int>res;
        res.first = pre[r].first;
        if (l) res.first = (1LL * (res.first - pre[l - 1].first + M1) * (IPow[l].first)) % M1;
        res.second = pre[r].second;
        if (l) res.second = (1LL * (res.second - pre[l - 1].second + M2) * (IPow[l].second)) % M2;
        return res;
    }
};

void sol(int ttt){
    string a, b;
    cin >> a >> b;
    hashing oba(a.size()), obb(b.size());
    oba.init_hash(a);
    obb.init_hash(b);

    int l, r;
    while(cin >> l >> r) {
        pair<int, int> val1 = oba.get_hash(l, r);
        pair<int, int> val2 = obb.get_hash(l, r);
        cout << val1.first << ' ' << val1.second << endl;
        cout << val2.first << ' ' << val2.second << endl;
    }
}
int32_t main(){
    prec_hash();
    //freopen("lcm.in", "r", stdin);
    int ttt = 1;
//    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) sol(iii);
    return 0;
}
