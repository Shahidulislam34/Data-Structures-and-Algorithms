#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int B1 = 283, B2 = 293, M1 = 1e9 + 87, M2 = 1e9 + 93;
static const int N = 2e5;
int POW1[N + 5], POW2[N + 5];
string str;
void hash_power(){
    int m1 = 1, m2 = 1;
    POW1[0] = POW2[0] = 1;
    for(int i = 1; i <= N; ++i){
        m1 = (1LL * m1 * B1) % M1;
        m2 = (1LL * m2 * B2) % M2;
        POW1[i] = m1;
        POW2[i] = m2;
    }
}

pair<int, int> hash_value(int l, int r){
    int val1 = 0, val2 = 0;
    for(int i = l; i <= r; ++i){
        val1 += (1LL * str[i] * POW1[i]) % M1;
        val1 %= M1;
        val2 += (1LL * str[i] * POW2[i]) % M2;
        val2 %= M2;
    }
    return {val1, val2};
}


int32_t main(){
    hash_power();
    int q;
    cin >> q;
    while(q--){
        cin >> str;
        pair<int, int>val = hash_value(0, (int)str.size());
        cout << val.first << ' ' << val.second << endl;
    }
    return 0;
}
