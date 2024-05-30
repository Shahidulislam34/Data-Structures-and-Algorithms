#include<iostream>
#include<cstring>
using namespace std;
const int M=1e9+7, N=1e5+5;
int mem[N],pre[N];

int ways(int n){
    if(n==0){
        pre[n]=0;
        return 1;
    }
    if(n==1){
        pre[n]=1;
        return 1;
    }
    if()


    for(int i=1; i<=n; ++i){
        sum=(sum+ways(n-i))%M;
    }
    pre[n]=pre

}

int main(){
    int n;
    cin >> n;

    cout << ways(n) << endl;
    return 0;
}
