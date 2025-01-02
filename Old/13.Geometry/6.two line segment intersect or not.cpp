#include<iostream>
using namespace std;
#define int long long

struct point{
    int x, y;
};

bool onsegment(point a, point b, point c){
    if((c.x>=min(a.x, b.x) && c.x<=max(a.x, b.x)) && (c.y >= min(a.y, b.y) && c.y <=max(a.y, b.y)))
        return true;
    else
        return false;
}

int cross(point a, point b, point c){
    int val=(a.x * b.y + b.x * c.y + c.x * a.y) - (a.y * b.x + b.y * c.x + c.y * a.x);
    if(val>0)return 1;
    else if(val==0 && onsegment(a, b, c)==true)return 2;
    else if(val==0 && onsegment(a, b, c)==false)return 0;
    else return -1;
}

int32_t main(){
    point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;
    int abc=cross(a, b, c);
    int abd=cross(a, b, d);
    int cda=cross(c, d, a);
    int cdb=cross(c, d, b);

    if(abc==2 || abd==2 || cda==2 || cdb==2)cout << "YES" << endl;///on segment
    else if(abc!=abd && cda!=cdb)cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

