#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int> prim;
const int N=1e6;
int bul[N+5];

void sieve(){
    memset(bul,0,sizeof(bul));
    for(int i=3; i*i<=N; i+=2){
        if(bul[i] == 0){
            for(int j=i*i; j<=N; j+=2*i)
                bul[j]=1;
        }
    }
    prim.push_back(2);
    for(int i=3; i<=N; i+=2)if(bul[i]==0)prim.push_back(i);
}
int main(){
    sieve();
    int a, b;
    cin >> a >> b;
    if(a==1)a=2;
    int n=b-a+1;

    memset(bul, 0, sizeof(bul));
    for(auto x:prim){
        if(x*x<=b){
            int i=(a/x)*x;
            if(i<a)i+=x;
            for(; i<=b; i+=x){
                if(i!=x)
                    bul[i-a+1]=1;
            }
        }
        else
            break;
    }
    vector<int> res;
    for(int i=1; i<=n; ++i){
        if(bul[i] == 0)
           res.push_back(a+i-1);
    }
    for(auto x:res)cout << x << ' '; cout << endl;
}
