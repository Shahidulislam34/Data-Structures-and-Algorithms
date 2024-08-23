#include<iostream>
using namespace std;
const int M = 1e9+7;
int main(){
    int base, power;
    cin >> base >> power;
    int res = 1;
    while(power) {
        if (power % 2) res = (1ll * res * base) % M, --power;
        else base = (1ll * base * base) % M, power /= 2;
    }
    cout << res << endl;
}
