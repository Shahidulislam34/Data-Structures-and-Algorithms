#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {2, 3, 1};
    sort(arr, arr + 3);

    for (int i = 0; i < 3; ++i) cout << arr[i] << ' '; cout << endl;
    cout << "next permutation:" << endl;
    do {
        for (int i = 0; i < 3; ++i) cout << arr[i] << ' '; cout << endl;
    }while(next_permutation(arr, arr + 3));

    sort(arr, arr + 3, greater<int>());
    cout << endl;
    for (int i = 0; i < 3; ++i) cout << arr[i] << ' '; cout << endl;
    cout << "prev permutation:" << endl;
    do {
        for (int i = 0; i < 3; ++i) cout << arr[i] << ' '; cout << endl;
    }while(prev_permutation(arr, arr + 3));


    vector<int>v = {4, 3, 1, 2};
    cout << endl << "for vector:" << endl;
    sort(v.begin(), v.end());
    do {
        for (int i = 0; i < 4; ++i) cout << v[i] << ' '; cout << endl;
    }while(next_permutation(v.begin(), v.end()));


}
