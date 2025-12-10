#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

struct manachers {
    vector<int>rad;
    int n;
    void run_manachers(string str) {
        n = str.size();
        rad.assign(n, 0);
        int l = 0, r = 0;
        for (int i = 0; i < n; ++i) {
            int mir = r - i + l;
            if (i < r) rad[i] = min(r - i, rad[mir]);
            while(i - rad[i]  - 1 >= 0 && i + rad[i] + 1 < n && str[i - rad[i] - 1] == str[i + rad[i] + 1])
                ++rad[i];
            if (i + rad[i] > r) {
                l = i - rad[i];
                r = i + rad[i];
            }
        }
    }

    void build(string ss) {
        string str;
        for (auto x : ss) str += string("#") + x;
        str += string("#");
        run_manachers(str);
    }
    pair<int, int> lps() {
        int a = 0, b = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            if (rad[i] > mx) {
                mx = rad[i];
                a = i / 2 - rad[i] / 2;
                b = i / 2 + (rad[i] - 1) / 2;
            }
        }
        return {a, b};
    }
    bool check_palin(int l, int r) {
        int a = l * 2 + 1, b = r * 2 + 1;
        int cen = (a + b) / 2;
        if (rad[cen] >= (b - a) / 2) return true;
        else return false;
    }
}obj;

int main(){
    string str;
    cin >> str;
    obj.build(str);
    auto [x, y] = obj.lps();
    string res;
    for (int i = x; i <= y; ++i) res.push_back(str[i]);
    cout << res << endl;
    return 0;
}
