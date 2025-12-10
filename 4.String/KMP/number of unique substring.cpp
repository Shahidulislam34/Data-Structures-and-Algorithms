#include<iostream>
#include<vector>
using namespace std;

///KMP STARTS
const int N = 2e5;
int PI[N + 5];
string P;
int n;
void pre_fun(int st){
    int now = -1;
    PI[0] = -1;
    for (int i = st + 1; i < n; ++i){
        while(now != -1 && P[now + 1 + st] != P[i]) now = PI[now];
        if (P[now + 1 + st] == P[i]) PI[i - st] = ++now;
        else PI[i - st] = now = -1;
    }
}

int main(){
    cin >> P;
    n = P.size();
    int res = 0;
    for (int i = 0; i < n; ++i){
        pre_fun(i);
        for (int j = 0; j < n - i; ++j) cout << PI[j] << ' '; cout << endl;
        int mx = -1;
        for (int j = 0; j <= i; ++j) mx = max(mx, PI[j]);
        res += (n - i - (mx + 1));
    }
    cout << res << endl;
}
