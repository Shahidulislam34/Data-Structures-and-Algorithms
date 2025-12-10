#include<iostream>
#include<math.h>
using namespace std;
#include<bitset>
int main() {
    ///indexing from right to left(....2,1,0)
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
    bs1[3] = 1;
    bs1[8] = 1;
    bs1.set(3);
    bs1.set();
    bs1.reset(2);
    bs1.reset();
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
    bs1[1].flip();
    cout << "Flip:" << bs1 << endl;

    ///bitset to integer
    unsigned long long val = bs1.to_ullong();
    cout << val << endl;
    unsigned long val2 = bs1.to_ulong();
    cout << val2 << endl;
    long long val3 = (long long)bs1.to_ullong();
    cout << "ll:" << val3 << endl;

    ///bitset to string
    string str = bs1.to_string();
    cout << str << endl;

    ///left shift and right shift
    cout << bs1 << endl;
    bs1 >>= 2;
    cout << bs1 << endl;
    bs1 <<=2;
    cout << bs1 << endl;

    ///Left and right shift of k bits
    int sz = bs1.size();
    int k = 2;
    cout << ((bs1 << k) | (bs1 >> (sz - k))) << endl;//left shift
    cout << ((bs1 >> k) | (bs1 << (sz - k))) << endl;//right shift

    long long n;
    cin >> n;
    cout << "number of leading zero: " << __builtin_clzll(n) << endl;
    cout << "number of trailing zero: " << __builtin_ctzll(n) << endl;

    cout << "position of leading one: " << (int) log2(n) << endl;
    cout << "position of trailing one: " << (int)log2(n & (-n)) << endl;

    cout << "for leading one power value: " << (n & (-n)) << endl;

    if ((n & -n) == 0) cout << "All bit is set" << endl;
    else cout << "Atleast one bit is unset" << endl;

    return 0;
}
