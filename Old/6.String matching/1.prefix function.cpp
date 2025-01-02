#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    string str;
    cin>>str;
    int n=str.size();

    vector<ll>pi(n+5);
    int pos;
    pi[0]=pos=-1;

    for(int i=1;i<n;++i)///here i start from 1 && for kmp i start from 0
    {
        while(pos!=-1&&str[pos+1]!=str[i])pos=pi[pos];
        if(str[pos+1]==str[i])pi[i]=++pos;
        else pi[i]=pos=-1;
    }
    for(ll i=0;i<n;++i)cout<<pi[i]<<' ';cout<<endl;
}

