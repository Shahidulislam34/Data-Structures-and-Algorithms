#include<iostream>
#include<vector>
using namespace std;
const int N=2e5;
bool vis[N+5];
int n, e;
vector<int>tree[N+5];

struct blackwhite{
    int black, white;
}node[N+5];

void ways(int cn){
    vis[cn]=1;
    node[cn].black=1;
    node[cn].white=1;
    for(auto x:tree[cn]){
        if(!vis[x]){
            ways(x);
            node[cn].white*=node[x].white+node[x].black;
            node[cn].black*=node[x].white;
        }

    }
}

int32_t main(){
    cin >> n;
    e=n-1;
    while(e--){
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ways(1);
    cout << node[1].white+node[1].black << endl;
    return 0;
}
