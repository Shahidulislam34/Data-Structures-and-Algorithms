#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int>us={4,7,1,8,3,9,5};
    us.insert(10);
    us.insert(8);
    for(auto x:us)cout<<x<<' ';cout<<endl;

    ///don't use this in unordered_set
//    unordered_set<Expression *>rev;
//    for(rev=us.rbegin();rev!=us.rend();++rev)cout<<rev<<' ';cout<<endl;

    ///first
    cout<<*us.begin()<<endl;

    ///last:Not use
//    cout<<*us.rbegin()<<endl;

    ///erase
    us.erase(1);
    for(auto x:us)cout<<x<<' ';cout<<endl;

    ///upperbound:not use
//    cout<<*us.upper_bound(1)<<endl;

    ///lowerbound:not use
//    cout<<*us.lower_bound(4)<<endl;

    ///clear
    us.clear();

    ///empty
    if(us.empty())cout<<"Empty"<<endl;
    else cout<<"Not Empty"<<endl;


}
