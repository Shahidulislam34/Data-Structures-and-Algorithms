#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'


///merge sort tree----starts with vector
const int N = 2e5;
vector<int>tree[4 * N + 5], v(N + 5);
int n;

void merge_node(int cn, int ln, int rn) {
    int sz1 = tree[ln].size(), sz2 = tree[rn].size();

    int ind1 = 0, ind2 = 0;
    while(ind1 < sz1 && ind2 < sz2) {
        if (tree[ln][ind1] <= tree[rn][ind2])
            tree[cn].push_back(tree[ln][ind1]), ++ind1;
        else
            tree[cn].push_back(tree[rn][ind2]), ++ind2;
    }
    while(ind1 < sz1) tree[cn].push_back(tree[ln][ind1]), ++ind1;
    while(ind2 < sz2) tree[cn].push_back(tree[rn][ind2]), ++ind2;
}

void init_tree(int cn, int li, int ri){
    if (li == ri){
        tree[cn].push_back(v[li]);
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
        auto it = upper_bound(tree[cn].begin(), tree[cn].end(), x);
        return tree[cn].end() - it;
    }
    int ln = cn * 2, rn = cn * 2 + 1;
    int mid = (li + ri) / 2;
    int s1 = get_tree(ln, li, mid, l, r, x);
    int s2 = get_tree(rn, mid + 1, ri, l, r, x);
    return s1 + s2;
}
///merge sort tree-----

void sol(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];

    init_tree(1, 1, n);
    int q; cin >> q;
    while(q--) {
        int l, r, x; cin >> l >> r >> x;
        cout << get_tree(1, 1, n, l, r, x) << endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int tt = 1;
//    cin >> tt;
    while (tt--) sol();
    return 0;
}


