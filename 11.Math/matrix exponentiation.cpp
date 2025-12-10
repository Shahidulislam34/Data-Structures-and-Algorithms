#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl '\n'
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
const int M1 = (int)1e9 + 7;
const int M2 = 998244353;
const int N = (int)2e5;
const int Inf = 1e18;
int Dx[] = {-1, 0, 1, 0};
int Dy[] = {0, 1, 0, -1};

typedef vector<vector<int>> matrix;
matrix mat_mul(matrix mat1, matrix mat2, int m) {
    int r1 = mat1.size(), c1 = mat1[0].size(), r2 = mat2.size(), c2 = mat2[0].size();
    matrix prod(r1, vector<int>(c2, 0));
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < r2; ++k) {
                prod[i][j] += (1ll * mat1[i][k] * mat2[k][j]) % m;
                prod[i][j] %= m;
            }
        }
    }
    return prod;
}


matrix mat_expo(matrix ba, int po, int m) {
    int r1 = ba.size(), c1 = ba[0].size();
    matrix res(r1, vector<int>(c1, 0));
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c1; ++j) {
            if (i == j) res[i][j] = 1;
        }
    }
    while(po) {
        if (po & 1) res = mat_mul(res, ba, m), --po;
        else ba = mat_mul(ba, ba, m), po /= 2;
    }
    return res;
}

int32_t main(){
    int r1, c1, r2, c2;

    cin >> r1 >> c1;
    matrix mat1(r1, vector<int>(c1));
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            cin >> mat1[i][j];

    cin >> r2 >> c2;
    matrix mat2(r2 + 5, vector<int>(c2 + 5));
    for (int i = 0; i < r2; ++i)
        for (int j = 0; j < c2; ++j)
            cin >> mat2[i][j];
    if (c1 != r2) cout << "Multiplication does't exist." << endl;
    else {
        matrix prod = mat_mul(mat1, mat2, M1);
        for (int i = 0; i < r1; ++i) {
            for (int j = 0; j < c2; ++j)
                cout << prod[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}

