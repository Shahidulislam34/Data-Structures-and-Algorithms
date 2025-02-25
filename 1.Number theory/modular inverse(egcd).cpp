#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int M2 = 998244353;
const int N = (int)1e7;
const int Inf = LLONG_MAX;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

///egcd----logn
void egcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    int x1, y1;
    egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
}
///egcd----

int32_t main(){
    //find (1/a) % M = ? where gcd(a, M) = 1;
    //ans: ax + by = 1 (%M) where b = M... find x & y...where (1/a) % M = x;

    int a, M;
    cin >> a >> M; //b = M; c = 1; of the equation ax + by = c (% M).

    int x, y;
    egcd(a, M, x, y);

    cout << "Inverse modulo of " << a << " is: " << (x % M + M) % M << endl;
    return 0;
}



