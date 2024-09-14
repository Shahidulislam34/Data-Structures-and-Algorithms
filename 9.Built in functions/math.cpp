#include<bits/stdc++.h>
using namespace std;
const long double pi = acos(-1.0);

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min({a, b, c, d}) << endl;///containing any number of elements
    cout << max({a, b, c, d}) << endl;

    long long int lli;
    cin >> lli;
    cout << llround(pow(lli, 2)) << endl;
    cout << floor(sqrt(lli)) << endl;
    cout << ceil(sqrt(lli)) << endl;
    cout << floor(sqrtl(lli)) << endl;
    cout << floor(cbrt(lli)) << endl;
    cout << abs(lli) << endl;
    cout << log(lli) << endl;
    cout << log10(lli) << endl;
    cout << floor(log2(lli)) << endl;
    cout << sin((lli * pi) / 180) << endl;
    cout << cos((lli * pi) / 180) << endl;
    cout << tan((lli * pi) / 180) << endl;

    double dd;
    cin >> dd;
    cout << ceil(dd) << endl;
    cout << floor(dd) << endl;
    cout << round(dd) << endl;
    cout << llround(dd) << endl;
    cout << setprecision(10) << dd << endl;
    cout << fixed << setprecision(10) << dd << endl;
    cout << setprecision(0);
    cout << fabs(dd) << endl;
    cout << (180 * asin(dd)) / pi << endl;
    cout << (180 * acos(dd)) / pi << endl;
    cout << (180 * atan(dd)) / pi << endl;

}
