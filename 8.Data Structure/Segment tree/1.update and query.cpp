#include<iostream>
#include<vector>
using namespace std;

///SEGMENT TREE STARTS-----O(nlogn)-----one base indexing
const int N = 2e5;
vector<int>V(N + 5), TREE(4 * N + 5), PROP(4 * N + 5, 0);
void init_tree(int cn, int li, int ri){
    if (li == ri){
        TREE[cn] = V[li];
        return;
    }
    int mid = (li + ri) / 2;
    int ln = cn * 2, rn = cn * 2 + 1;
    init_tree(ln, li, mid);
    init_tree(rn, mid + 1, ri);
    TREE[cn] = TREE[ln] + TREE[rn];
}

void update_tree(int cn, int li, int ri, int a, int b, int val){
    if (ri < a || li > b) return;
    else if (a <= li && ri <= b){
        TREE[cn] += (ri - li + 1) * val;
        PROP[cn] += val;
        return;
    }
    int mid = (li + ri) / 2;
    int ln = 2 * cn, rn = 2 * cn + 1;
    update_tree(ln, li, mid, a, b, val);
    update_tree(rn, mid + 1, ri, a, b, val);
    TREE[cn] = TREE[ln] + TREE[rn] + PROP[cn] * (ri - li + 1);
}

int get_val(int cn, int li, int ri, int a, int b, int car){
    if (ri < a || li > b) return 0;
    else if (a <= li && ri <= b){
        return TREE[cn] + car * (ri - li + 1);
    }
    int mid = (li + ri) / 2;
    int ln = 2 * cn, rn = 2 * cn + 1;
    int s1 = get_val(ln, li, mid, a, b, car + PROP[cn]);
    int s2 = get_val(rn, mid + 1, ri, a, b, car + PROP[cn]);
    return s1 + s2;
}
///SEGMENT TREE ENDS-------


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
            cout << get_val(1, 1, n, a, b, 0) << endl;
        }
    }
    return 0;
}
