#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define endl '\n'

int32_t main() {
    stack<int>st;
    st.push(10);
    st.push(15);
    st.push(5);
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
    cout << endl;
}