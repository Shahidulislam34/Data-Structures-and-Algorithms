#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int n;cin>>n;
    vector<int>bit(n/32+5,0);
    bit[0]|=1;
    bit[0]|=(1<<1);
    for(int i=3;i<=sqrt(n);i+=2)
    {
        if(bit[i/32]&(1<<((i%32)))==0)
        for(int j=i*i;j<=n;j+=2*i)
        {
            bit[j/32]|=(1<<((j%32)));
        }
    }
    for(ll i=0;i<=n/32;++i)if(i%2!=0&&(bit[i/32]&(1<<32)==0))cout<<i<<' ';



    return 0;
}
