#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(n+5);
    for(int i=1; i<=n; ++i)v[i]=i;
    vector<bool> bul(n+5, false);
    for(int i=2; i*i<=n; ++i){
        if(bul[i] == 0){
            for(int j=i; j<=n; j+=i){
                v[j]= min(v[j], i);
                bul[j]=1;
            }
        }
    }
    for(int i=2; i<=n; ++i){
        int val=i;
        vector<int> fac;
        while(val>1){
            fac.push_back(v[val]);
            val/=v[val];
        }
        cout << "Prime factors of " << i << ':';
        for(auto x: fac)cout << x << ' ';
        cout << endl;
    }
}
