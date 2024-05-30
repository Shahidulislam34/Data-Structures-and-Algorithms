#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n+5);
    vector<bool> bul(n+5,false);
    for(int i=3; i*i<=n; i+=2){
        if(bul[i] == 0){
            for(int j=i*i; j<=n; j+=2*i)
                bul[j]=1;
        }
    }
    vector<int> prim;
    prim.push_back(2);
    for(int i=3; i<=n; i+=2){
        if(bul[i] == 0)prim.push_back(i);
    }
    for(auto x:prim)cout << x << ' '; cout << endl;
}
