#include<bits/stdc++.h>
using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int>v(n + 5);
    v[0] = -1;
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }

    vector<int>tmp;
    vector<int>pre(n + 5, -1);
    tmp.push_back(-1);
    int ind = 0;
    for (int i = 1; i <= n; ++i) {
        auto it = upper_bound(tmp.begin(), tmp.end(), v[i]);
        if (it == tmp.end()) {
            tmp.push_back(v[i]);
            ++ind;
            pre[i] = ind;
        }
        else {
            int plc = it - tmp.begin();
            tmp[plc] = v[i];
            pre[i] = plc;
        }
    }
    vector<int>seq;
    for (int i = n; i >= 1; --i) {
        if (pre[i] == ind) {
            seq.push_back(v[i]);
            --ind;
        }
    }
    reverse(seq.begin(), seq.end());

    cout << (int)seq.size() << endl;
    for (auto x : seq) cout << x << ' '; cout << endl;
}

int main() {
    sol();
    return 0;
}

