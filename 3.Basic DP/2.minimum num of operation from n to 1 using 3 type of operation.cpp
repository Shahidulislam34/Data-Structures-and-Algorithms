#include<iostream>
#include<cstring>
using namespace std;
#define int long long
const int N=1e5+5;
int stor[N];
int min_oper(int n){
    if(n==1)return 0;
    if(stor[n]!=-1)return stor[n];
    int mn=min_oper(n-1)+1;
    if((n%2)==0){
        mn=min(mn, min_oper(n/2)+1);
    }
    if((n%3)==0){
        mn=min(mn, min_oper(n/3)+1);
    }
    stor[n]=mn;
    return stor[n];
}

int32_t main(){
    int n;
    cin >> n;
    memset(stor, -1, sizeof(stor));
    cout << min_oper(n) << endl;
    return 0;
}
