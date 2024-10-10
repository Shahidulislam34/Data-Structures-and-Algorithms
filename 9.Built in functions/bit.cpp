#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    cout << "number of leading zero: " << __builtin_clzll(n) << endl;
    cout << "number of trailing zero: " << __builtin_ctzll(n) << endl;

    cout << "position of leading one: " << (int) log2(n) << endl;
    cout << "position of trailing one: " << (int)log2(n & (-n)) << endl;

    cout << "for leading one power value: " << (n & (-n)) << endl;


    return 0;
}
