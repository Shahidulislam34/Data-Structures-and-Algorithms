#include<iostream>
#include<vector>
using namespace std;

///KMP STARTS....complexity O(n)....only for zero base string
int N = 2e5;
vector<int>PI(N + 5);
void pre_fun(string P){
    int now = -1, m = P.size();
    PI[0] = -1;
    for (int i = 1; i < m; ++i){
        while(now != -1 && P[now + 1] != P[i]) now = PI[now];
        if (P[now + 1] == P[i]) PI[i] = ++now;
        else PI[i] = now = -1;
    }
}
///kmp ends

int main(){
    string P;
    cin >> P;
    pre_fun(P);
    int n = P.size();
    for (int i = 0; i < n; ++i) cout << PI[i] << ' '; cout << endl;
    return 0;
}


