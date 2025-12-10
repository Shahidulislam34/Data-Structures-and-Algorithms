#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define ff first
#define ss second
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int M2 = 998244353;
const int N = (int)300;
const int Inf = INT_MAX;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

///persistent segment tree----O(nlogn)
struct node {
    int val;
    node *lc, *rc;
};
vector<node*>version, nodes;
node* init_tree(int li, int ri) {
    node *newnode = new node();
//    nodes.push_back(newnode);
    if (li == ri) {
        newnode->val = 0;
        newnode->lc = NULL;
        newnode->rc = NULL;
        return newnode;
    }
    int mid = (li + ri) / 2;
    newnode->lc = init_tree(li, mid);
    newnode->rc = init_tree(mid + 1, ri);
    newnode->val = newnode->lc->val + newnode->rc->val;
    return newnode;
}

node* update_tree(node *cn, int li, int ri, int ind, int val) {
    node *newnode = new node();
//    nodes.push_back(newnode);
    if (li == ri) {
        newnode->val = cn->val + val;
        newnode->lc = NULL;
        newnode->rc = NULL;
        return newnode;
    }
    int mid = (li + ri) / 2;
    if (ind <= mid) {
        newnode->lc = update_tree(cn->lc, li, mid, ind, val);
        newnode->rc = cn->rc;
    }
    else {
        newnode->lc = cn->lc;
        newnode->rc = update_tree(cn->rc, mid + 1, ri, ind, val);
    }
    newnode->val = newnode->lc->val + newnode->rc->val;
    return newnode;
}

int get_tree(node *cn, int li, int ri, int a, int b) {
    if (ri < a || b < li) return 0;
    else if (a <= li && ri <= b) return cn->val;

    int mid = (li + ri) / 2;
    return get_tree(cn->lc, li, mid, a, b) + get_tree(cn->rc, mid + 1, ri, a, b);
}
///persistent segment tree----

void sol(int ttt){
    //range sum query using persistent segment tree:

    int n; cin >> n;
    vector<int>v(n + 5);
    for (int i = 1; i <= n; ++i) cin >> v[i];

    //create all version:
    version.resize(n + 5);
    version[0] = init_tree(1, n);

    for (int i = 1; i <= n; ++i) {
        version[i] = update_tree(version[i - 1], 1, n, i, v[i]);
    }


    int q; cin >> q;
    while(q--) {
        int a, b; cin >> a >> b;
        cout << get_tree(version[b], 1, n, a, b) << endl;
    }
    /*delete nodes:
    for (auto nd : nodes) delete nd;
    nodes.clear();
    */
}

int32_t main(){
    faster();
    //freopen("lcm.in", "r", stdin);
    int ttt = 1;
//    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) sol(iii);
    return 0;
}
