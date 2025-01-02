#include<iostream>
using namespace std;

struct point{
    int x, y;
};

int orientation(point a, point b, point c){
    int ls= (c.x - a.x) * (a.y - b.y) - (c.y - a.y) * (a.x - b.x);
    if(ls==0)return 0;
    return ls>0?1:2;
}

int main(){
    struct point a, b, c, d;
    cin >> a.x >> a.y >> b.x >> b.y;
    cin >> c.x >> c.y >> d.x >> d.y;

    int l1= orientation(a, b, c);
    int r1= orientation(a, b, d);
    int l2= orientation(c, d, a);
    int r2= orientation(c, d, b);
    if(l1!=r1 && l2!=r2)
        cout << "Intersect two lines" << endl;
    else
        cout << "Don't intersect two lines" << endl;

    return 0;
}
