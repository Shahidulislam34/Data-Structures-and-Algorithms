#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

vector<int> segmented_sieve(int a, int b){
    int n = ceil(1.0 * sqrtl(b));
    vector<int>bul(n + 5, 0);
    for(int i=3; i*i<=n; i+=2){
        if(bul[i] == 0){
            for(int j=i*i; j<=n; j+=2*i)
                bul[j]=true;
        }
    }
    vector<int>prim;
    prim.push_back(2);
    for(int i=3; i<=n; i+=2)if(bul[i]==0)prim.push_back(i);

    if(a==1)a=2;
    int m=b-a+1;
    bul.assign(m + 5, 0);
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
    for(int i=1; i<=m; ++i){
        if(bul[i] == 0)
           res.push_back(a+i-1);
    }
    return res;
}

int main(){
    int a, b;
    cin >> a >> b;
    vector<int>res = segmented_sieve(a, b);
    for (auto x : res) cout << x << ' '; cout << endl;

    return 0;
}
