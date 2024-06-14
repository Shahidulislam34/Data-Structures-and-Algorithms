#include<iostream>
#include<vector>
using namespace std;
int main(){
    ///for 1 base indexing
    int n;cin>>n;
    vector<int>v(n+5), pre(n+5,0);
    for(int i=1; i<=n; ++i)cin>>v[i];

    for(int i=1; i<=n; ++i)pre[i]=pre[i-1]+v[i];
    for(int i=1; i<=n; ++i)cout<<pre[i]<<' '; cout<<endl;

    int a, b;
    cin>>a>>b;
    cout<<pre[b]-pre[a-1]<<endl;

    ///for zero base indexing
    int m;
    cin >> m;
    vector<int>v2(m), pre2(m, 0);
    for (int i = 0; i < m; ++i) cin >> v2[i];

    pre2[0] = v2[0];
    for (int i = 1; i < m; ++i) pre2[i] = pre2[i - 1] + v2[i];
    for (int i = 0; i < m; ++i) cout << pre2[i] << ' '; cout << endl;

    int l, r;
    cin >> l >> r;
    int val = pre2[r];
    if (l > 0) val -= pre2[l - 1];
    cout << val << endl;

    return 0;
}
