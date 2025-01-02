#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int>ms1={4,5,1,4,5,2};
    for(auto x:ms1)cout<<x<<' ';cout<<endl;

    ///reverse print
    for(auto x=ms1.rbegin();x!=ms1.rend();++x)cout<<*x<<' ';cout<<endl;

    multiset<int,greater<int>>ms2={5,2,7,1,9,1,6,5};
    for(auto x:ms2)cout<<x<<' ';cout<<endl;

    ///reverse print
    multiset<int,greater<int>>::reverse_iterator rev_it;
    for(rev_it=ms2.rbegin();rev_it!=ms2.rend();++rev_it)
        cout<<*rev_it<<' ';
    cout<<endl;

    ///upperbound
    cout<<*ms2.upper_bound(9)<<endl;

    ///lowerbound
    cout<<*ms2.lower_bound(4)<<endl;

    ///first digit
    cout<<*ms2.begin()<<endl;

    ///last digit
    cout<<*ms2.rbegin()<<endl;

    ///clear
    ms1.clear();

    ///empty
    if(ms1.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;

    ///erase all occurance
    ms2.erase(1);
    for(auto x:ms2)cout<<x<<' ';cout<<endl;

    multiset<int,greater<int>>::reverse_iterator rev_it2;
    for(rev_it2=ms2.rbegin();rev_it2!=ms2.rend();++rev_it2)
        cout<<*rev_it2<<' ';cout<<endl;

    multiset<int>ms3 = {5,5,2,7,3,7};

    ///erase first element
    auto st = ms3.begin();
    ms3.erase(st);

    ///erase last element
    auto en = ms3.end();
    --en;
    ms3.erase(en);

    for(auto x : ms3) cout << x << ' '; cout << endl;


}
