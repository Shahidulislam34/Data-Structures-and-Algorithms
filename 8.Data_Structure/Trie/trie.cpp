#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

struct Trie {
    int n, ends, cp;//cp = count prefix
    vector<Trie*>chi;
    Trie() {
        n = 32;
        cp = ends = 0;
        chi.resize(n);
        for (int i = 0; i < n; ++i) chi[i] = nullptr;
    }
    int char_to_index(char ch) {
        return ch - 'a';
    }
    void add_word(string str, int inc = 1) {
        Trie* cur = this;
        for (auto ch : str) {
            int ind = char_to_index(ch);
            if (cur->chi[ind] == nullptr)
                cur->chi[ind] = new Trie();
            cur = cur->chi[ind];
            cur->cp += inc;
        }
        cur->ends += inc;
    }
    int count_pref(string str) {
        Trie * cur = this;
        for (auto ch : str) {
            int ind = char_to_index(ch);
            if (cur->chi[ind] == nullptr)
                return 0;
            cur = cur->chi[ind];
        }
        return cur->cp;
    }
    int count_word(string str) {
        Trie* cur = this;
        for (auto ch : str) {
            int ind = char_to_index(ch);
            if (cur->chi[ind] == nullptr)
                return false;
            cur = cur->chi[ind];
        }
        return cur->ends;
    }
};

int32_t main() {
    struct Trie root;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        string str; cin >> str;
        root.add_word(str);
    }
    string str;
    while(cin >> str) {
        cout << "Number of word:" << root.count_word(str) << endl;
        cout << "Number of prefix:" << root.count_pref(str) << endl;
    }

    return 0;
}
