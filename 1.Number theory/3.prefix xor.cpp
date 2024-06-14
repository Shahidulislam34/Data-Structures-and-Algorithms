#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n; cin >> n;
    vector<int> v(n + 5), pre(n + 5, 0);
    for(int i = 1; i <= n; ++i) cin >> v[i];

    for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] ^ v[i];
    for(int i = 1; i <= n; ++i) cout << pre[i] << ' '; cout << endl;

    int a, b;
    cin >> a >> b;
    cout << (pre[b] ^ pre[a-1]) << endl;

    ///try to get xor of a rectangle something similar to 2D prefix sum
}
