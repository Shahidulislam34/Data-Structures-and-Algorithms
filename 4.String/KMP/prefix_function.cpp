#include<iostream>
#include<vector>
using namespace std;

///kmp starts....complexity O(n)....only for zero base string
int N = 2e5;
vector<int>pi(N + 5);
void pre_fun(string P){
    int now = -1, m = P.size();
    pi[0] = -1;
    for (int i = 1; i < m; ++i){
        while(now != -1 && P[now + 1] != P[i]) now = pi[now];
        if (P[now + 1] == P[i]) pi[i] = ++now;
        else pi[i] = now = -1;
    }
}
///kmp ends

int main(){
    string P;
    cin >> P;
    pre_fun(P);
    int n = P.size();
    for (int i = 0; i < n; ++i) cout << pi[i] << ' '; cout << endl;
    return 0;
}


