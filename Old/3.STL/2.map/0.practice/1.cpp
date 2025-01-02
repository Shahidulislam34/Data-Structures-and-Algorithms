#include<bits/stdc++.h>
using namespace std;


int main()
{
    unordered_map<int,int>um;
    um[3]=4;
    um[1]=5;
    um[3]=5;

    for(auto x:um)cout<<x.first<<' '<<x.second<<endl;
}
