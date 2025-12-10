#include<bits/stdc++.h>
using namespace std;
int main() {
    ///complexity is O(1) to move
    //applicable: normal variable, STL, class and objects........
    vector<int>v1 = {1,2,3,4,5,6,7};
    vector<int>v2 = move(v1);//move

    cout << v1.size() << endl;//0
    cout << v2.size() << endl;//7

    for (auto x : v1) cout << x << ' '; cout << endl;
    for (auto x : v2) cout << x << ' '; cout << endl;

    ///but: complexity is O(n) to copy
    vector<int>v3 = {1,2,3,4,5,6, 7};
    vector<int>v4 = v3;//copy
    cout << v3.size() << endl;//7
    cout << v4.size() << endl;//7
    for (auto x : v3) cout << x << ' '; cout << endl;
    for (auto x : v4) cout << x << ' '; cout << endl;

}
