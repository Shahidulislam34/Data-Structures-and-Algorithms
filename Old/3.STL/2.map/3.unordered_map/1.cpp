#include<bits/stdc++.h>
using namespace std;


int main()
{
    unordered_map<int,int>umap;
    umap[1]=4;
    umap[5]=6;
    umap[3]=10;
    umap[20]=20;

    for(auto x:umap)cout<<x.first<<' '<<x.second<<endl;


    return 0;
}
