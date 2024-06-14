#include<iostream>
using namespace std;
int main(){
    int n; cin >> n;
    if((n!=2 && (n&1)==0) || (n<2)){
        cout<<"Not Prime"<<endl;
        return 0;
    }

    for(int i=3; i*i<=n; i+=2){
        if(n%i == 0){
            cout << "Not Prime" << endl;
            return 0;
        }
    }
    cout << "Prime" << endl;
}
