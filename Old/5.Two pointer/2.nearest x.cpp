#include<bits/stdc++.h>
using namespace std;

bool sol(vector<int>&v,int n,int m)
{
    int l,r,sum;
    l=1;
    r=n;
    while(l<r)
    {
        sum=v[l]+v[r];
        if(sum==m)
        {
            cout<<"index:"<<l<<' '<<r<<endl;
            cout<<"val:"<<v[l]<<' '<<v[r]<<endl;
            return true;
        }
        if(sum<m)++l;
        else --r;
    }
    return false;
}

int main()
{
    int n;cin>>n;
    vector<int>v(n+5);
    for(int i=1;i<=n;++i)cin>>v[i];
    sort(v.begin()+1,v.begin()+n+1);
    for(int i=1;i<=n;++i)cout<<v[i]<<' ';cout<<endl;
    int m;
    while(cin>>m)
    {
        if(sol(v,n,m))cout<<"Find"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}
