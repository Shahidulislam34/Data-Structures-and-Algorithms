#include<bits/stdc++.h>
using namespace std;

//segment tree.....O(nlogn)
struct node {
    int sum;
    node() {
        sum = 0;
    }
};
vector<node>Tree, Prop;
vector<int>V;

void init_tree(int cn, int li, int ri) {
    if (li == ri) {
        Tree[cn].sum = V[li];
        return;
    }
    int mid = (li + ri) / 2, ln = cn * 2, rn = cn * 2 + 1;
    init_tree(ln, li, mid);
    init_tree(rn, mid + 1, ri);
    Tree[cn].sum = Tree[ln].sum + Tree[rn].sum;
}

void update_tree(int cn, int li, int ri, int a, int b, int val) {
    if (ri < a || b < li) return;
    else if (a <= li && ri <= b) {
        Tree[cn].sum += (ri - li + 1) * val;
        Prop[cn].sum += val;
    }
    int mid = (li + ri) / 2, ln = cn * 2, rn = cn * 2 + 1;
    update_tree(ln, li, mid, a, b, val);
    update_tree(rn, mid + 1, ri, a, b, val);
    Tree[cn].sum = Tree[ln].sum + Tree[rn].sum + Prop[cn].sum * (ri - li + 1);
}

int get_tree(int cn, int li, int ri, int a, int b, int car) {
    if (ri < a || b < li) return 0;
    else if (a <= li && ri <= b) {
        return Tree[cn].sum + (ri - li + 1) * car;
    }
    int mid = (li + ri) / 2, ln = cn * 2, rn = cn * 2 + 1;
    int s1 = get_tree(ln, li, mid, a, b, car + Prop[cn].sum);
    int s2 = get_tree(rn, mid + 1, ri, a, b, car + Prop[cn].sum);
    return s1 + s2;
}
//segment tree........


int main() {
    int n, q, val;
    cin >> n >> q;

    Tree.clear();Prop.clear();V.clear();

    Tree.assign(4 * n + 5, node());
    Prop.assign(4 * n + 5, node());
    V.resize(n + 5);

    for (int i = 1; i <= n; ++i) cin >> V[i];

    init_tree(1, 1, n);
    while(q--){
        int choose, a, b;
        cin >> choose >> a >> b;
        if (choose){
            cin >> val;
            update_tree(1, 1, n, a, b, val);
        }
        else {
            cout << get_tree(1, 1, n, a, b, 0) << endl;
        }
    }
    return 0;
}
