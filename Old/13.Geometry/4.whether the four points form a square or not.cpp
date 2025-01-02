#include<iostream>
#include<vector>
using namespace std;
struct point{
    int x,y;
};

int dis_square(point p, point q){
    return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
}

int main() {
    struct point a, b, c, d;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;
    cin >> d.x >> d.y;

    int ab= dis_square(a, b);
    int ac= dis_square(a, c);
    int ad= dis_square(a, d);

    if(ab==ac && ad==2*ab && dis_square(b, d)==2*dis_square(a, d))
        cout << "Fomr a square" << endl;
    else if(ad==ac && ab==2*ad && dis_square(a, b)==2*dis_square(d, b))
        cout << "Form a square" << endl;
    else if(ab==ad && ac==2*ad && dis_square(a, c)==2*dis_square(a, d))
        cout << "Form a square" << endl;
    else
        cout << "Don't form a square" << endl;

    return 0;

}
