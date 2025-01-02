#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template <typename T> using o_set = tree<T, null_type,
less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    o_set<int>os;
    os.insert(5);
    os.insert(10);
    os.insert(2);
    os.insert(2);
    for(auto x:os)cout<<x<<' ';cout<<endl;
    cout<<os.size()<<endl;

    auto it=os.find_by_order(2);//for accessing 2 no. index value
    cout<<*it<<endl;

    cout<<os.order_of_key(1)<<endl;//number of element that is strictly less than 1
    it = os.upper_bound(20);
    cout << *it << endl;

    return 0;
}
