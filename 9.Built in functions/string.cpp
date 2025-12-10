#include<bits/stdc++.h>
using namespace std;

int main() {
    string str = "abcDEF89";
    //2(0 base) is position, 4 is length
    cout << str.substr(2, 4) << endl;

    if (isalpha(str[3])) cout << "alphabet" << endl;
    else cout << "not alphabet" << endl;

    if (isdigit(str[6])) cout << "digit" << endl;
    else cout << "not digit" << endl;

    if (islower(str[3])) cout << "lower" << endl;
    else if (isupper(str[3])) cout << "upper" << endl;

    str[2] = (char)toupper(str[2]);
    str[3] = (char)tolower(str[3]);
    cout << str << endl;

    string dig = "12344444";///only for integer
    cout << stoi(dig) << endl;
    dig = "123445674333223";
    cout << stoll(dig) << endl;///for long long

    //Supported types: int, long, long long, float, double, long double
    string st = to_string(123434343423434.550);
    cout << st << endl;

    string st2; cin >> st2;
    cin.ignore();//delete newline from buffer

    string s;
    getline(cin, s);
    stringstream ss;
    ss << s;
    string s1;
    while(ss >> s1) {
        cout << s1 << endl;
    }

}
