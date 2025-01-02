#include<iostream>
#include<vector>
using namespace std;

///sieve----nloglogn
vector<int>prime;
void sieve(int nn) {
    vector<bool>vis(nn + 5, false);
    if (nn >= 2) prime.push_back(2);
    for (int i = 3; i * i <= nn; i += 2) {
        if (!vis[i]) {
            for (int j = i * i; j <= nn; j += 2 * i)
                vis[j] = true;
        }
    }
    for (int i = 3; i <= nn; i += 2) {
        if (vis[i] == false) prime.push_back(i);
    }
}
///sieve----

int main(){
    int n;
    cin >> n;
    sieve(n);
    for (auto x : prime) cout << x << ' '; cout << endl;
    return 0;
}
