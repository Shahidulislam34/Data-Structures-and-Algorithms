#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int M2 = 998244353;
const int N = 2e6;
const int Inf = 1e18;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

///catalan numbers----from 1 to n----nlogn
vector<int>Fac(N + 5), Inv(N + 5), Cat(N + 5);
int mod_exp(int base, int power, int M) {
    int res = 1;
    while(power) {
        if (power % 2) res = (res % M * base % M) % M, --power;
        else base = (base % M * base % M) % M, power /= 2;
    }
    return res;
}

void prec(int nn) {
    Fac[0] = 1;
    for (int i = 1; i <= nn; ++i)
        Fac[i] = (Fac[i - 1] % M1 * i % M1) % M1;
    for (int i = 0; i <= nn; ++i)
        Inv[i] = mod_exp(Fac[i], M1 - 2, M1);
}

void cat(int nn) {
    prec(nn);
    for (int i = 1; i <= nn / 2; ++i)
        Cat[i] = (((Fac[2 * i] % M1 * Inv[i] % M1) % M1) * (Inv[i + 1] % M1)) % M1;
}
///catalan numbers----

int32_t main(){
    faster();
    cat(N);
    for (int i = 1; i <= 10; ++i) cout << Cat[i] << ' '; cout << endl;
    return 0;
}



