#include<iostream>
#include<vector>
using namespace std;
const int N=2e5;
vector<int>grp[N+5];
int main(){
    int n, e, a, b;
    cin>> n >> e;
    while(e--){
        cin >> a >> b;
        grp[a].push_back(b);
        grp[b].push_back(a);
    }
    for(int i=1; i<=n; ++i){
        cout << i << ':';
        for(auto x:grp[i]){
            cout << x << ' ';
        }
        cout << endl;
    }
}
