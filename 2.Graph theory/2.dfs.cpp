#include<iostream>
#include<vector>
using namespace std;

const int N=1e5;
vector<int>grp[N+5];
bool vis[N+5];
void dfs(int cn){
    vis[cn]=1;
    cout<< cn << ' ';
    for(auto x:grp[cn]){
        if(!vis[x]){
            dfs(x);
        }
    }
}

int main(){
    int n, e, a, b;
    cin>> n >> e;
    while(e--){
        cin>> a >> b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    dfs(1);
}
