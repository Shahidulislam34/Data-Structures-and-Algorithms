#include<iostream>
#include<vector>
using namespace std;

///phi function from 1 to n----nlogn
const int N = (int)1e6;
vector<int>Phi(N + 5);
void phi(int nn) {
    for (int i = 1; i <= nn; ++i) Phi[i] = i;
    for (int i = 2; i <= nn; ++i) {
        if (Phi[i] == i) {
            for (int j = i; j <= nn; j += i) {
                Phi[j] = (Phi[j] * (i - 1)) / i;
            }
        }
    }
}
///phi function----

int main(){
    int n; cin >> n;
    phi(n);
    for (int i = 1; i <= n; ++i) cout << Phi[i] << ' '; cout << endl;
    return 0;
}

