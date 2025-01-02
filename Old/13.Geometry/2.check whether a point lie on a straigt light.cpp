#include<iostream>
using namespace std;

int main(){
    long double x1,y1,x2,y2,x,y;
    cin>>x1>>y1>>x2>>y2;
    cin>>x>>y;
    ///first create the straight line then check
    if((y-y1)*(x1-x2)==(x-x1)*(y1-y2))cout<<"Yes stay on the line"<<endl;
    else cout<<"don't stay on the line"<<endl;
    return 0;
}
