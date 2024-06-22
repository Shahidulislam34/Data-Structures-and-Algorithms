#include<iostream>
#include<vector>
using namespace std;

///kmp starts....complexity O(n)....only for zero base string
int N = 2e5;
vector<int>pi(N + 5);
void kmp(string str){
    int now = -1, n = str.size();
    pi[0] = -1;
    for (int i = 1; i < n; ++i){
        while(now != -1 && str[now + 1] != str[i]) now = pi[now];
        if (str[now + 1] == str[i]) pi[i] = ++now;
        else pi[i] = now = -1;
    }
}
///kmp ends

int main(){
    string str;
    cin >> str;
    kmp(str);
    int n = str.size();
    for (int i = 0; i < n; ++i) cout << pi[i] << ' '; cout << endl;
    return 0;
}

