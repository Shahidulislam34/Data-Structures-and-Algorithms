#include<iostream>
#include<vector>
using namespace std;

///dsu starts ----
const int N = 2e5;
int n, e;
vector<int>rep(N + 5);
void init_rep() {
    for (int i = 1; i <= n; ++i) rep[i] = i;
}

int find_rep(int m) {
    if (rep[m] == m) return m;
    return rep[m] = find_rep(rep[m]);
}

void update_rep(int a, int b) {
    int rp1 = find_rep(a);
    int rp2 = find_rep(b);
    rep[rp1] = rp2;
}
///dsu ends------

int main() {
    cin >> n >> e;
    init_rep();
    while(e--) {
        int a, b;
        cin >> a >> b;
        update_rep(a, b);
    }
    int a, b;
    while(cin >> a >> b) {
        if (find_rep(a) == find_rep(b)) cout << "Same set" << endl;
        else cout << "Different set" << endl;
    }
    return 0;
}
