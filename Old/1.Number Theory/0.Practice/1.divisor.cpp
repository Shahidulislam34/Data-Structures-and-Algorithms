#include<bits/stdc++.h>
using namespace std;


int main()
{
    unordered_set<int>us;
    int n;cin>>n;
    for(int i=1;i<=sqrt(n);++i)
    {
        if(n%i==0)
        {
            us.insert(i);
            us.insert(n/i);
        }
    }
    for(auto x:us)cout<<x<<' ';cout<<endl;
}
