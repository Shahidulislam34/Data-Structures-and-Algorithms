#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int M2 = 998244353;
const int N = (int)1e6;
const int Inf = 1e18;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

struct node{
    int sum, upd, lazy, val;
    node() {
        sum = 0;
        upd = -1;
        lazy = 0;
        val = 0;
    }
};
vector<node>Tree;
vector<int>V;

void init_tree(int cn, int li, int ri) {
    if (li == ri) {
        Tree[cn].sum = V[li];
        Tree[cn].lazy = 0;
        Tree[cn].upd = V[li];
        return;
    }
    int ln = cn * 2, rn = cn * 2 + 1, mid = (li + ri) / 2;
    init_tree(ln, li, mid);
    init_tree(rn, mid + 1, ri);
    Tree[cn].sum = Tree[ln].sum + Tree[rn].sum;
    Tree[cn].lazy = 0;
    Tree[cn].upd = -1;
}

void update_tree(int cn, int li, int ri, int a, int b, int val, int ss, int up) {
    if (ri < a || b < li) {
        if (up == -1) {
            Tree[cn].lazy += ss;
            Tree[cn].sum += ss * (ri - li + 1);
        }
        else {
            Tree[cn].lazy = ss;
            Tree[cn].upd = up;
            Tree[cn].sum = (Tree[cn].lazy + Tree[cn].upd) * (ri - li + 1);
        }
        return;
    }
    else if (a <= li && ri <= b) {
        Tree[cn].lazy = 0;
        Tree[cn].upd = val;
        Tree[cn].sum = Tree[cn].upd * (ri - li + 1);
        return;
    }

    int ln = cn * 2, rn = cn * 2 + 1, mid = (li + ri) / 2;
    if (up == -1) ss += Tree[cn].lazy, up = Tree[cn].upd;
    update_tree(ln, li, mid, a, b, val, ss, up);
    update_tree(rn, mid + 1, ri, a, b, val, ss, up);
    Tree[cn].sum = Tree[ln].sum + Tree[rn].sum;
    Tree[cn].lazy = 0;
    Tree[cn].upd = -1;
}

void increase_tree(int cn, int li, int ri, int a, int b, int val, int ss, int up) {
    if (ri < li) return;
    if (ri < a || b < li) {
        if (up == -1) {
            Tree[cn].lazy += ss;
            Tree[cn].sum += (ss * (ri - li + 1));
        }
        else {
            Tree[cn].lazy = ss;
            Tree[cn].upd = up;
            Tree[cn].sum = (Tree[cn].lazy + Tree[cn].upd) * (ri - li + 1);
        }
        return;
    }
    else if (a <= li && ri <= b) {
        if (up == -1) {
            Tree[cn].lazy += (val + ss);
            Tree[cn].sum += ((val + ss) * (ri - li + 1));
        }
        else {
            Tree[cn].lazy = ss + val;
            Tree[cn].upd = up;
            Tree[cn].sum = ((Tree[cn].lazy + Tree[cn].upd) * (ri - li + 1));
        }
        return;
    }

    int ln = cn * 2, rn = cn * 2 + 1, mid = (li + ri) / 2;
    if (up == -1) ss += Tree[cn].lazy, up = Tree[cn].upd;
    increase_tree(ln, li, mid, a, b, val, ss, up);
    increase_tree(rn, mid + 1, ri, a, b, val, ss, up);
    Tree[cn].sum = Tree[ln].sum + Tree[rn].sum;
    Tree[cn].lazy = 0;
    Tree[cn].upd = -1;
}

int get_tree(int cn, int li, int ri, int a, int b, int ss, int up) {
    if (ri < a || b < li) return 0;
    else if (a <= li && ri <= b) {
        if (up == -1) return Tree[cn].sum + (ss * (ri - li + 1));
        else return (up + ss) * (ri - li + 1);
    }
    int ln = cn * 2, rn = cn * 2 + 1, mid = (li + ri) / 2;
    if (up == -1) ss += Tree[cn].lazy, up = Tree[cn].upd;
    int sum1 = get_tree(ln, li, mid, a, b, ss, up);
    int sum2 = get_tree(rn, mid + 1, ri, a, b, ss, up);
    return sum1 + sum2;
}

void sol(int ttt){
    //CSES 1735
    int n, q; cin >> n >> q;
    Tree.assign(4 * n + 5, node());
    V.resize(n + 5);
    for (int i = 1; i <= n; ++i) cin >> V[i];

    init_tree(1, 1, n);

    while(q--) {
        int ch; cin >> ch;
        if (ch == 1) {
            int a, b, val; cin >> a >> b >> val;
            increase_tree(1, 1, n, a, b, val, 0, -1);
        }
        else if (ch == 2) {
            int a, b, val; cin >> a >> b >> val;
            update_tree(1, 1, n, a, b, val, 0, -1);
        }
        else {
            int a, b; cin >> a >> b;
            cout << get_tree(1, 1, n, a, b, 0, -1) << endl;
        }
    }
}

int32_t main(){
    faster();
    //freopen("lcm.in", "r", stdin);
    int ttt = 1;
//    cin >> ttt;
    for (int iii = 1; iii <= ttt; ++iii) sol(iii);
    return 0;
}

