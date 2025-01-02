#include<bits/stdc++.h>
using namespace std;


int main()
{
    tuple<int,int,int,int>tp,tp2;
    tp=make_tuple(1,2,3,4);
    tp=make_tuple(6,7,8,9);
    cout<<get<0>(tp)<<' '<<get<1>(tp)<<' '<<get<2>(tp)<<' '<<get<3>(tp)<<endl;

    ///swap,,if size of two tuple are same
    swap(tp,tp2);

    ///invalid
    //if(tp.empty())cout<<"Empty"<<endl;

    ///invalid
    //cout<<tp.size()<<endl;

    ///invalid
    //if(tp.empty())cout<<"Empty"<<endl;
    //else cout<<"Not Empty"<<endl;

    ///invalid
    //tp.insert({1,2,3,4});

    ///invalid
    //tp.push_back({1,2,3,4});


    tuple<int,int,int>tp3[3];
    for(int i=0;i<3;++i)
    {
        cin>>get<0>(tp3[i])>>get<1>(tp3[i])>>get<2>(tp3[i]);
    }
    for(int i=0;i<3;++i)
        cout<<get<0>(tp3[i])<<' '<<get<1>(tp3[i])<<' '<<get<2>(tp3[i])<<endl;

}
