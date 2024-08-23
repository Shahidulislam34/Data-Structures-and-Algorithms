#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res = 1;
    for (int i = 2; i * i <= n; ++i) {
        int cnt = 0;
        while(n % i == 0) {
            ++cnt;
            n /= i;
        }
        res *= (cnt + 1);
    }
    if (n > 1) res *= 2;
    cout << res << endl;
}
