#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    string s1,s2;cin>>s1>>s2;
    ll n=s1.size(),m=s2.size(),cnt=0,pos;
    vector<ll>pi(n+5);
    pos=-1;
    for(ll i=0;i<n;++i)
    {
        while(pos!=-1&&s2[pos+1]!=s1[i])pos=pi[pos];

        if(s2[pos+1]==s1[i])pi[i]=++pos;
        else pi[i]=pos=-1;

        if(pi[i]+1==m)
        {
            ++cnt;
            break;
            pos=pi[pos];
            while(pos!=-1&&s2[pos+1]!=s1[i])pos=pi[pos];
        }
    }
    cnt=0;
    for(ll i=0;i<n;++i)if(pi[i]==m-1)++cnt;
    cout<<"Number of s2 in s1="<<cnt<<endl;
    return 0;
}
