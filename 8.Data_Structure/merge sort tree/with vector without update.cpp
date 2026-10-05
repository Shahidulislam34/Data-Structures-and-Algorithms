#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
const int M1 = (int)1e9 + 7;
const int N = 3e5;
const int Inf = 1e18;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

///merge sort tree----using vector
vector<int>Tree[4 * N + 5], V(N + 5);

void merge_node(int cn, int ln, int rn) {
    int sz1 = Tree[ln].size(), sz2 = Tree[rn].size();
    int ind1 = 0, ind2 = 0;
    while(ind1 < sz1 && ind2 < sz2) {
        if (Tree[ln][ind1] <= Tree[rn][ind2])
            Tree[cn].push_back(Tree[ln][ind1]), ++ind1;
        else
            Tree[cn].push_back(Tree[rn][ind2]), ++ind2;
    }
    while(ind1 < sz1) Tree[cn].push_back(Tree[ln][ind1]), ++ind1;
    while(ind2 < sz2) Tree[cn].push_back(Tree[rn][ind2]), ++ind2;
}

void init_tree(int cn, int li, int ri){
    if (li == ri){
        Tree[cn].push_back(V[li]);
        return;
    }
    int mid = (li + ri) / 2;
    int ln = cn * 2, rn = cn * 2 + 1;
    init_tree(ln, li, mid);
    init_tree(rn, mid + 1, ri);
    merge_node(cn, ln, rn);
}

int get_tree(int cn, int li, int ri, int l, int r, int x) {
    if (r < li || ri < l) return 0;
    else if (l <= li && ri <= r) {
        auto it = lower_bound(Tree[cn].begin(), Tree[cn].end(), x);
        return Tree[cn].end() - it;//greater than or equal
    }
    int ln = cn * 2, rn = cn * 2 + 1;
    int mid = (li + ri) / 2;
    int s1 = get_tree(ln, li, mid, l, r, x);
    int s2 = get_tree(rn, mid + 1, ri, l, r, x);
    return s1 + s2;
}
///merge sort tree-----

void sol(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> V[i];

    init_tree(1, 1, n);
    int q; cin >> q;
    while(q--) {
        int l, r, x; cin >> l >> r >> x;/// number of element which is greater than or equal to x in l to r.
        cout << get_tree(1, 1, n, l, r, x) << endl;
    }
}

int32_t main(){
    int tt = 1;
//    cin >> tt;
    while (tt--) sol();
    return 0;
}


