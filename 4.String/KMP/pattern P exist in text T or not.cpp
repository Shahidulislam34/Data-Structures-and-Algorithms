#include<iostream>
#include<vector>
using namespace std;

///kmp starts.....complexity O(n).....only for zero base string
const int N = 2e5;
vector<int>pi(N + 5);
bool kmp(string T, string P){
    int n = T.size(), m = P.size();
    int now = -1;
    for (int i = 0; i < n; ++i){
        while(now != -1 && P[now + 1] != T[i]) now = pi[now];
        if (P[now + 1] == T[i]) pi[i] = ++now;
        else pi[i] = now = -1;
        if (now == m - 1) return true;
    }
    return false;
}
///kmp ends


int main(){
    string T, P;
    cin >> T >> P;
    if (kmp(T, P)) cout << "exist" << endl;
    else cout << "don't exist" << endl;
    return 0;
}
