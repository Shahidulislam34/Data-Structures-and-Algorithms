#include<iostream>
using namespace std;
#include<bitset>
int main() {
    ///bitset declare
    bitset<10>bs1;
    bitset<10>bs2(232);
    bitset<10>bs3(string{"100111"});
    bitset<10>bs4("01101");
    string s = "10001111";
    bitset<10>bs5(s);
    cout << bs1 << endl;
    cout << bs2 << endl;
    cout << bs3 << endl;
    cout << bs4 << endl;
    cout << bs5 << endl;


    ///index update
    bs1[5] = 1;
    bs1[1] = 1;
    bs1[8] = 1;
    bs1.set(0);
    bs1.reset(0);
    cout << bs1 << endl;


    ///count set and unset bits
    cout << "set bit:" << bs1.count() << endl;
    cout << "Unset bit:" << bs1.size() - bs1.count() << endl;


    ///check it zero or not
    if (bs1.any()) cout << "Atleast one bit is set" << endl;
    else cout << "All bit is zero" << endl;
    if (bs1.none()) cout << "All bit is zero" << endl;
    else cout << "Atleast one bit is set" << endl;


    ///all bit is set or not
    if (bs1.all()) cout << "All bit are set" << endl;
    else cout << "All bit are not set" << endl;


    ///flip
    cout << bs1 << endl;
    bs1.flip();
    cout << bs1 << endl;


    ///bitset to integer
    unsigned long long val = bs1.to_ullong();
    cout << val << endl;
    unsigned long val2 = bs1.to_ulong();
    cout << val2 << endl;


    ///bitset to string
    string str = bs1.to_string();
    cout << str << endl;


    ///left shift and right shift
    cout << bs1 << endl;
    bs1 >>= 2;
    cout << bs1 << endl;
    bs1 <<=2;
    cout << bs1 << endl;

    return 0;
}
