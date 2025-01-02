#include<bits/stdc++.h>
using namespace std;



int main()
{
    bitset<10>pos;
    cout<<pos<<endl;

    bitset<10>neg(100);///just 2's compleme nt of 100 in 64 bit
    cout<<neg<<endl;
    for(int i = 0; i < 10; ++i)cout << neg[i] << ' '; cout << endl;

    return 0;
}
