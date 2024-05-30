#include<iostream>
#include<cstring>
using namespace std;
const int N=1e5+5;
int mem[N];
int fibo(int n){
    if(mem[n]!=-1)return mem[n];
    if(n==0)return 0;
    else if(n==1)return 1;
    mem[n]=fibo(n-1)+fibo(n-2);
    return mem[n];
}

int main(){
    int n;
    cin >> n;
    memset(mem, -1, sizeof(mem));
    cout << fibo(n) << endl;
    return 0;
}
