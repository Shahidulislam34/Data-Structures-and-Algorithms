#include<iostream>
#include<vector>
using namespace std;

///kmp starts....complexity O(n)....only for zero base string
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

bool kmp(string T, string P){
    int n = T.size(), m = P.size();
    int now = -1;
    for (int i = 0; i < n; ++i){
        while(now != -1 && P[now + 1] != T[i]) now = PI[now];
        if (P[now + 1] == T[i]) ++now;
        else now = -1;
        if (now == m - 1) return true;
    }
    return false;
}
///kmp ends

int main(){
    string T, P;
    cin >> T >> P;
    pre_fun(P);
    if (kmp(T, P)) cout << "Exist" << endl;
    else cout << "Not exist" << endl;
    return 0;
}

