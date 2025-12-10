#include<bits/stdc++.h>
#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin >> n;
    const int m = n;
    map<array<int, 3>, int>mp;
    mp[{1,2,3}] = 12;
    map<int, vector<int>>mp2;
    mp2[10].push_back(20);

    map<int, int>mp3[100];
    mp3[0][20] = 100;

    map<int, set<int>>ms;
    ms[10].insert(20);

}
