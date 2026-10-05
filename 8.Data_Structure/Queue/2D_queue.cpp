#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 10;
    queue<int>q[n];
    q[0].push(1);
    q[0].push(2);
    q[0].push(0);
    q[5].push(5);
    q[2].push(2);
     for (int i = 0; i < 10; ++i) {
        cout << "size:" << q[i].size() << endl;
        while(!q[i].empty()) cout << q[i].front() << ' ', q[i].pop();
        cout << endl;
    }
    return 0;
}

