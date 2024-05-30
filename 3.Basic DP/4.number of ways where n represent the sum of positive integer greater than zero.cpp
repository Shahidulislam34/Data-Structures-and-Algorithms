#include<iostream>
#include<cstring>
using namespace std;
const int M=1e9+7,N=1e3+5;
int mem[N];

int ways(int n){
    if(n==0)return 1;
    if(n==1)return 1;
    if(mem[n]!=-1)return mem[n];
    int sum=0;
    for(int i=1; i<=n; ++i){
        sum=(sum + ways(n-i))%M;
    }
    mem[n]=sum;
    return mem[n];
}

int32_t main(){
    int n;
    cin >> n;//n<=1e3, solve with O(n2)
    memset(mem, -1, sizeof(mem));
    cout << ways(n) << endl;
    return 0;
}
