#include<iostream>
#include<set>
using namespace std;
int main() {
    int n;
    cin >> n;
    set<int>div;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) div.insert(i), div.insert(n / i);
    }
    for (auto x : div) cout << x << ' '; cout << endl;
}
