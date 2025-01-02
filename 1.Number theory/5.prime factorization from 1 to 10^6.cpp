#include<iostream>
#include<vector>
using namespace std;

///prime factorization from 1 to n----
const int N = (int)1e6;
vector<int>Spf(N + 1);
vector<pair<int, int>>Pf[N + 1];

void spf(int nn) {
    vector<bool> bul(nn + 1, false);
    for (int i = 1; i <= nn; ++i) Spf[i] = i;
    for (int i = 2; i * i <= nn; ++i){
        if (bul[i] == false){
            for (int j = i * i; j <= nn; j += i){
                Spf[j] = min(Spf[j], i);
                bul[j] = true;
            }
        }
    }
}

void pf(int nn) {
    spf(nn);
    for(int i = 2; i <= nn; ++i){
        int val = i, cnt = 0, factor = Spf[i];
        while(val > 1){
            if (Spf[val] != factor) {
                Pf[i].push_back({factor, cnt});
                cnt = 0;
                factor = Spf[val];
            }
            val /= Spf[val];
            ++cnt;
        }
        Pf[i].push_back({factor, cnt});
    }
}
///prime factorization ends----

int main(){
     int n; cin >> n;
     pf(n);
     for (int i = 1; i <= n; ++i) {
        cout << "i:" << i << endl;
        for (auto [x, y] : Pf[i]) cout << x << ' ' << y << endl;;
        cout << endl;
     }

}
