#include<iostream>
#include<vector>
using namespace std;

///Segment tree---O(nlogn)---one base
const int N = 2e5;
vector<int>V(N + 5), Tree(4 * N + 5), Prop(4 * N + 5, 0);
void init_tree(int cn, int li, int ri){
    if (li == ri){
        Tree[cn] = V[li];
        return;
    }
    int mid = (li + ri) / 2;
    int ln = cn * 2, rn = cn * 2 + 1;
    init_tree(ln, li, mid);
    init_tree(rn, mid + 1, ri);
    Tree[cn] = Tree[ln] + Tree[rn];
}

void update_tree(int cn, int li, int ri, int a, int b, int val){
    if (ri < a || li > b) return;
    else if (a <= li && ri <= b){
        Tree[cn] += (ri - li + 1) * val;
        Prop[cn] += val;
        return;
    }
    int mid = (li + ri) / 2;
    int ln = 2 * cn, rn = 2 * cn + 1;
    update_tree(ln, li, mid, a, b, val);
    update_tree(rn, mid + 1, ri, a, b, val);
    Tree[cn] = Tree[ln] + Tree[rn] + Prop[cn] * (ri - li + 1);
}

int get_tree(int cn, int li, int ri, int a, int b, int car){
    if (ri < a || li > b) return 0;
    else if (a <= li && ri <= b){
        return Tree[cn] + car * (ri - li + 1);
    }
    int mid = (li + ri) / 2;
    int ln = 2 * cn, rn = 2 * cn + 1;
    int s1 = get_tree(ln, li, mid, a, b, car + Prop[cn]);
    int s2 = get_tree(rn, mid + 1, ri, a, b, car + Prop[cn]);
    return s1 + s2;
}
///Segment tree---


int main() {
    int n, q, val;
    cin >> n >> q;
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
