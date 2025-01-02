#include<bits/stdc++.h>
using namespace std;



int main()
{
    bitset<64>bt(31);

    ///any()
    if(bt.any())cout<<"Find set bit"<<endl;
    else cout<<"Not Find Set bit"<<endl;

    ///none()
    if(bt.none())cout<<"Not Find set bit"<<endl;
    else cout<<"Find set bit"<<endl;

    int cnt=bt.count();
    cout<<"Number of set bit:"<<cnt<<endl;



}
