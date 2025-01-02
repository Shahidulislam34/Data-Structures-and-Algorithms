#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long double x1, y1, x2, y2, d;
    cin>> x1 >>y1 >> x2 >> y2;
    d=sqrtl((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    cout<<d<<endl;

    return 0;
}
