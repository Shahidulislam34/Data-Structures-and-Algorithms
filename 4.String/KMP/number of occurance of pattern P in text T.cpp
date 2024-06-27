#include<iostream>
#include<vector>
using namespace std;

///KMP STARTS....complexity O(n)....only for zero base string
const int N = 2e5;
int PI[N + 5];
void pre_fun(string P){
    int m = P.size();
    int now = -1;
    PI[0] = -1;
    for (int i = 1; i < m; ++i){
        while(now != -1 && P[now + 1] != P[i]) now = PI[now];
        if (P[now + 1] == P[i]) PI[i] = ++now;
        else PI[i] = now = -1;
    }
}
int kmp(string T, string P){
    int n = T.size(), m = P.size();
    int now = -1, res = 0;
    for (int i = 0; i < n; ++i){
        while(now != -1 && P[now + 1] != T[i]) now = PI[now];
        if (P[now + 1] == T[i]) ++now;
        else now = -1;
        if (now == m - 1) ++res, now = PI[now];
    }
    return res;
}
///KMP ENDS

int main(){
    string T, P;
    cin >> T >> P;
    pre_fun(P);
    int res = kmp(T, P);
    cout << res << endl;
}
