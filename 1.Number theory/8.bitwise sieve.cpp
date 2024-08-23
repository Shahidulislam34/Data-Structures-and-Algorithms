#include<iostream>
#include<vector>
using namespace std;
int main(){

    int n;
    cin >> n;
    vector<int> bit(n/32+5,0);
    bit[0]|=(1<<0);
    bit[0]|=(1<<1);
    for(int i=2; i*i<=n; ++i){
        if((bit[i/32]&(1<<(i%32)))==0){
            for(int j=i*i; j<=n; j+=i)
                bit[j/32]|=(1<<(j%32));
        }
    }

    vector<int> prim;
    for(int i=0; i<=n; ++i){
        if((bit[i/32]&(1<<(i%32)))==0){
            prim.push_back(i);
        }
    }
    cout << "Shourov" << endl;
//    for(auto x:prim)cout << x << ' '; cout << endl;

}
