#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
    ///question: Is s2 present in s1?
    string s1,s2;
    cin>>s1>>s2;
    ll n=s1.size(),m=s2.size(),pos,flag=0;
    vector<ll>pi(n+5);
    pos=-1;
    for(ll i=0;i<n;++i)///i start from 0
    {
        while(pos!=-1&&s2[pos+1]!=s1[i])pos=pi[pos];

        if(s2[pos+1]==s1[i])pi[i]=++pos;
        else pi[i]=pos=-1;

        if(pi[i]+1==m){flag=1;break;}
    }
    if(flag==1)cout<<"Found"<<endl;
    else cout<<"Not Found"<<endl;

    return 0;
}
