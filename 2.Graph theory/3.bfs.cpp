#include<iostream>
#include<vector>
#include<queue>
using namespace std;
const int N=1e5;
vector<int>grp[N+5];
bool vis[N+5];
int lev[N+5];

void bfs(int cn){
    vis[cn]=1;
    queue<int>que;
    que.push(cn);
    while(!que.empty()){
        cn=que.front();
        que.pop();
        for(auto x: grp[cn]){
            if(!vis[x]){
                vis[x]=1;
                que.push(x);
                lev[x]=lev[cn]+1;
            }
        }
    }
}

int main(){
    int n, e;
    cin>> n >> e;
    while(e--){
        int a, b;
        cin >> a >> b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    bfs(1);
    for(int i=1; i<=n; ++i)
        cout<< i << ':' << lev[i] << endl;
}
