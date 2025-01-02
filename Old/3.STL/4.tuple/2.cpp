#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    vector<tuple<ll,ll,ll>>v(100);
    get<0>(v[0])=10;
    get<1>(v[0])=20;
    cout<<get<0>(v[0])<<endl;
}
