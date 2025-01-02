#include<bits/stdc++.h>
using namespace std;
int main()
{
    pair<int,int>pp,pp3;


    ///don't empty function
//    if(pp.empty())cout<<"Empty"<<endl;
//    else cout<<"Not Empty"<<endl;

    ///don't insert
    //pp.insert(2,3);

    pp=make_pair(2,3);
    pp=make_pair(3,4);///second element exist
    cout<<pp.first<<' '<<pp.second<<endl;

    ///swap function exist if both datatype & size are same
    pp3=make_pair(5,6);
    swap(pp,pp3);

    ///don't size
    //cout<<pp.size()<<endl;


    pair<int,int>pp2[10],pp4[10];
    for(int i=0;i<5;++i)
    {
        cin>>pp2[i].first>>pp2[i].second;
    }
    for(int i=0;i<5;++i)
    {
        cout<<pp2[i].first<<' '<<pp2[i].second<<endl;
    }

    swap(pp2,pp4);

    ///don't push_back
//    pp.push_back({2,3});

    return 0;
}
