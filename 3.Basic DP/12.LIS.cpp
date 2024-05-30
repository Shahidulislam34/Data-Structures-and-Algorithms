#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int32_t main(){
    int n;
    cin >> n;///n<=1e3

    string str;
    cin >> str;
    str='0'+str;///1 base

    int dp[n+5];
    for(int i=1; i<=n; ++i)dp[i]=1;
    for(int i=1; i<=n; ++i){
        for(int j=1; j<i; ++j){
            if(str[j]<str[i]){
                dp[i]=max(dp[i], dp[j]+1);
            }
        }
    }
    int len=*max_element(dp+1, dp+n+1);
    cout << len << endl;

    string seq;
    int cnt=1;
    for(int i=1; i<=n; ++i){
        if(dp[i]==cnt){
            seq.push_back(str[i]);
            ++cnt;
        }
    }
    cout << seq << endl;
}
