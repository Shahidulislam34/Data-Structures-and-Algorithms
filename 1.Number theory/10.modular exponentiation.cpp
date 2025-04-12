#include<iostream>
using namespace std;
const int M = 1e9+7;

///modular expnentiation starts----
int mod_expo(int base, int power, int m) {
    int res = 1;
    while(power) {
        if (power % 2) res = (res % m * base % m) % m, --power;
        else base = (base % m * base % m) % m, power /= 2;
    }
    return res;
}
///ends----

int main(){
    int base, power;
    cin >> base >> power;
    cout << mod_expo(base, power, M) << endl;
    return 0;
}
