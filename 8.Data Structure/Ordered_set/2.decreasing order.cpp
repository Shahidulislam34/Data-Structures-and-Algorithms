#include<bits/stdc++.h>
using namespace std;

///ordered_set------zero base index-----only for 'int' data type
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type,
greater<T>, rb_tree_tag, tree_order_statistics_node_update>;
///ordered_set-------


int main(){
    ///initialization:
    o_set<int>os;

    ///size:
    cout << os.size() << endl;

    ///insert:
    os.insert(4);
    os.insert(1);
    os.insert(3);
    os.insert(3);
    os.insert(6);
    for (auto x : os) cout << x << ' '; cout << endl;

    ///index access:
    cout << *os.find_by_order(2) << endl;//value of index 2
    cout << *os.find_by_order(6) << endl;

    ///number of element that strictly greater than k:
    cout << os.order_of_key(4) << endl;
    cout << os.order_of_key(1) << endl;

    ///lower_bound:
    cout << *os.lower_bound(3) << endl;
    cout << *os.lower_bound(5) << endl;
    //int ind = (os.lower_bound(3) - os.begin());// never access

    ///upper_bound:
    cout << *os.upper_bound(3) << endl;
    cout << *os.upper_bound(5) << endl;
    //int ind = (os.lower_bound(3) - os.begin());// never access

    return 0;
}

