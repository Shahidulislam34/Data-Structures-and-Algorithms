#include<bits/stdc++.h>
using namespace std;
#define int long long

void sol() {
    ///hexadecimal to decimal
    string hexa; cin >> hexa;
    int dec = stoll(hexa, 0, 16);
    cout << dec << endl;

    ///decimal to hexadecimal:
    int dec2; cin >> dec2;
    //cann't store:
    printf("%x\n", dec2);//lowercase
    printf("%X\n", dec2);//uppercase
    cout << hex << dec2 << endl;
    //stored:
    stringstream ss;
    ss << hex << dec2;
    string hexa2 = ss.str();
    cout << hexa2 << endl;

    ///octal to decimal:
    string octa; cin >> octa;
    int dec3 = stoll(octa, 0, 8);
    cout << dec3 << endl;

    ///decimal to octal:
    //cann't store:
    printf("%o\n", dec3);
    cout << oct << dec3 << endl;
    //stored:
    stringstream ss3;
    ss3 << oct << dec3;
    string octa3 = ss3.str();
    cout << octa3 << endl;

//    int deci; cin >> deci;
//    string bina = format("{:b}", deci);
//    cout << bina << endl;
}

int32_t main() {
    int tt = 1;
    cin >> tt;
    while(tt--) sol();
}
