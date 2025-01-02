#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int N = 3e5;
const int Inf = 1e18;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};


///monotonic increasing----O(n)
vector<int>V(N + 5);
vector<int> mon_inc(int nn) {
    deque<int>dq;
    vector<int>pre_smallest(nn + 5);
    for (int i = 1; i <= nn; ++i) {
        while(!dq.empty() && V[dq.back()] > V[i]) dq.pop_back();
        if (!dq.empty()) pre_smallest[i] = dq.back();
        else pre_smallest[i] = 0;
        dq.push_back(i);
    }
    return pre_smallest;
}
///monotonic increasing----

void sol(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> V[i];
    vector<int>pre_smallest = mon_inc(n);
    for (int i = 1; i <= n; ++i) cout << pre_smallest[i] << ' '; cout << endl;
}

int32_t main(){
    faster();
    int tt = 1;
//    cin >> tt;
    while(tt--) sol();
    return 0;
}



