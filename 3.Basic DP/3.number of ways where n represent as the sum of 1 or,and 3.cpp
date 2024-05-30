#include<iostream>
#include<cstring>
using namespace std;
const int M=1e9+7,N=1e5+5;
int mem[N];
int ways(int n){
    if(n==1)return 1;
    if(n==2)return 1;
    if(n==3)return 2;
    if(mem[n]!=-1)return mem[n];
    mem[n]=(ways(n-1) + ways(n-3))%M;
    return mem[n];
}

int32_t main(){
    int n; //n<=1e5,solve with O(n).
    cin >> n;
    memset(mem, -1, sizeof(mem));
    cout << ways(n) << endl;
    return 0;
}
