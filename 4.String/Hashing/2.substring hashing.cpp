#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define endl '\n'
///HASHING STARTS--------------Only for zero base string
const int B1 = 283, B2 = 293, M1 = 1e9 + 87, M2 = 1e9 + 93, N = 2e5;
pair<int, int>PRE[N + 5], POW[N + 5], IPOW[N + 5];

int big_mod(int base, int power, int mod){
    int res = 1;
    while (power != 0){
        if (power % 2 == 0) base = (1LL * base * base) % mod, power /= 2;
        else res = (1LL * res * base) % mod, --power;
    }
    return res;
}

void prec_hash(){
    POW[0] = {1, 1};
    for (int i = 1; i <= N; ++i){
        POW[i].first = (1LL * POW[i - 1].first * B1) % M1;
        POW[i].second = (1LL * POW[i - 1].second * B2) % M2;
    }
    int ip1 = big_mod(B1, M1 - 2, M1);
    int ip2 = big_mod(B2, M2 - 2, M2);
    IPOW[0] = {1, 1};
    for (int i = 1; i <= N; ++i){
        IPOW[i].first = (1LL * IPOW[i - 1].first * ip1) % M1;
        IPOW[i].second = (1LL * IPOW[i - 1].second * ip2) % M2;
    }
}

void init_hash(string str){
    PRE[0] = {str[0], str[0]};
    int ZZ = str.size();
    for (int i = 1; i < ZZ; ++i){
        PRE[i].first = PRE[i - 1].first + (1LL * str[i] * POW[i].first) % M1;
        PRE[i].first %= M1;
        PRE[i].second = PRE[i - 1].second + (1LL * str[i] * POW[i].second) % M2;
        PRE[i].second %= M2;
    }
}

pair<int, int> get_hash(int l, int r){
    pair<int, int>res;
    res.first = PRE[r].first;
    if (l) res.first = (1LL * (res.first - PRE[l - 1].first + M1) * (IPOW[l].first)) % M1;
    res.second = PRE[r].second;
    if (l) res.second = (1LL * (res.second - PRE[l - 1].second + M2) * (IPOW[l].second)) % M2;
    return res;
}
///HASHING ENDS------------

int32_t main(){
    string str;
    cin >> str;
    prec_hash();
    init_hash(str);
    int q, a, b;
    cin >> q;
    while(cin >> a >> b){
        pair<int, int>val = get_hash(a, b);
        cout << val.first << ' ' << val.second << endl;
    }
    return 0;
}
