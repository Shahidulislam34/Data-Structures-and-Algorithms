#include<iostream>
#include<vector>
using namespace std;

int r, c;
vector<string>v;
bool vis[10005][10005]={0};

int dx[]={-1, 1, 0, 0};
int dy[]={0, 0, -1, 1};

bool valid(int i, int j){
    if(i>=0 && i<r && j>=0 && j<c)
        return true;
    else
        return false;
}

void dfs(int i, int j){
    if(v[i][j]=='#' || vis[i][j]==1)return;
    vis[i][j]=1;
    for(int k=0; k<4; ++k){
        int ty= i+dy[k];
        int tx= j+dx[k];
        if(valid(ty, tx) && vis[ty][tx]==0 && v[ty][tx]=='.'){
            dfs(ty, tx);
        }
    }
}

int main(){
    cin >> r >> c;
    for(int i=0; i<r; ++i){
        string str;
        cin >> str;
        v.push_back(str);
    }
    int ans=0;
    for(int i=0; i<r; ++i){
        for(int j=0; j<c; ++j){
            if(vis[i][j]==0 && v[i][j]=='.'){
                dfs(i, j);
                ++ans;
//                cout<<"CHECK:"<<i<<' '<<j<<endl;
            }
        }
    }
    cout << ans << endl;

    return 0;

}
