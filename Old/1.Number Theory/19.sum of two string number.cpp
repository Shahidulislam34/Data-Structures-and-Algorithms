#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    string s1,s2,ans;
    cin>>s1>>s2;
    ll sz1,sz2,mxsz,d1,d2,carry=0,sum;
    sz1=s1.size();sz2=s2.size();

    for(ll i=sz1-1,j=sz2-1;i>=0||j>=0;--i,--j)
    {
        if(i>=0&&j>=0)
        {
            d1=s1[i]-'0';
            d2=s2[j]-'0';
            sum=(d1+d2+carry)%10;
            carry=(d1+d2+carry)/10;
            ans+=(sum+'0');
            cout<<sum<<' '<<carry<<' '<<d1<<' '<<d2<<' '<<1<<endl;
        }
        else if(i>=0)
        {
            d1=s1[i]-'0';
            sum=(d1+carry)%10;
            carry=(d1+carry)/10;
            ans+=(sum+'0');
            cout<<sum<<' '<<carry<<' '<<d1<<' '<<d2<<' '<<2<<endl;
        }
        else
        {
            d2=s2[j]-'0';
            sum=(d2+carry)%10;
            carry=(d2+carry)/10;
            ans+=(sum+'0');
            cout<<sum<<' '<<carry<<' '<<d1<<' '<<d2<<' '<<3<<endl;
        }
    }
    if(carry!=0)ans+=(carry+'0');

    for(string::reverse_iterator x=ans.rbegin();x!=ans.rend();++x)cout<<*x;
    cout<<endl;

    return 0;

}
