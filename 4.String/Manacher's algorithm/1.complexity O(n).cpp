#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

///LPS starts.....complexity O(n).....only for zero base string
pair<int, int> LPS(string s){
    string str;
    str.push_back('#');
    for (auto x : s) str.push_back(x), str.push_back('#');

    int n = str.size();
    vector<int>radius(n, 0);
    int c = 0, r = 0;
    for (int i = 0; i < n; ++i){
        int mirror = 2 * c - i;
        if (i < r) radius[i] = min(radius[mirror], r - i);
        while(i + radius[i] + 1 < n && i - radius[i] - 1 >= 0 && str[i + radius[i] + 1] == str[i - radius[i] - 1])
            ++radius[i];
        if (i + radius[i] > r){
            r = i + radius[i];
            c = i;
        }
    }

    int a = 0, b = 0, mx = 0;
    for (int i = 0; i < n; ++i) {
        if (radius[i] > mx){
            mx = radius[i];
            a = i / 2 - radius[i] / 2;
            b = i / 2 + (radius[i] - 1) / 2;
        }
    }
    return {a, b};
}
/// LPS ends

int main(){
    string str;
    cin >> str;
    pair<int, int>ran = LPS(str);
    cout << ran.first << ' ' << ran.second << endl;
    string res;
    for (int i = ran.first; i <= ran.second; ++i) res.push_back(str[i]);
    cout << res << endl;
    return 0;
}
