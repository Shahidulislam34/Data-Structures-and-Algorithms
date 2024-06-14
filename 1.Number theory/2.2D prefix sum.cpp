#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int r, c;
    cin>>r>>c;
    int v[r+5][c+5], pre[r+5][c+5];
    memset(pre,0,(r+5)*(c+5)*sizeof(int));
    for(int i=1; i<=r; ++i)
        for(int j=1; j<=c; ++j)
            cin>>v[i][j];

    for(int i=1; i<=c; ++i)pre[1][i]=pre[1][i-1]+v[1][i];
    for(int i=1; i<=r; ++i)pre[i][1]=pre[i-1][1]+v[i][1];

    for(int i=2; i<=r; ++i)
        for(int j=2; j<=c; ++j)
            pre[i][j]=v[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
    for(int i=1; i<=r; ++i){
        for(int j=1; j<=c; ++j){
            cout<<pre[i][j]<<' ';
        }
        cout<<endl;
    }

    int x1, y1, x2, y2;
    cin >> x1 >> y1>> x2 >>y2;

    ///only for uper left corner = (x1, y1) & bottom right corner = (x2, x2):
    cout<<pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1]<<endl;

    ///sum of rectangle for any case:
    if (x1 > x2) swap(x1, x2), swap(y1, y2);
    if (y1 > y2) swap(y1, y2);

    cout<<pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1]<<endl;
}
