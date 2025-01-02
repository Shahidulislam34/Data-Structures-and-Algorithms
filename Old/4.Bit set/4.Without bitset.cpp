#include<bits/stdc++.h>
using namespace std;
#define ll long  long


int main()
{
    ll n;cin>>n;
    bitset<32>bit(n);
    cout<<bit<<endl;
    cout<<"Number of leading zero:"<<__builtin_clz(n)<<endl;

    cout<<"Number of trailing zero:"<<__builtin_ctz(n)<<endl;

    cout<<"Number of one's:"<<__builtin_popcount(n)<<endl;

    cout<<"Position of last one:"<<32-__builtin_clz(n)<<endl;


    ///conversion a positive number to a negative number:
    ll neg;
    neg=~n+1;
    cout<<neg<<endl;


    return 0;
}
