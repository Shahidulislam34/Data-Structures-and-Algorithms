#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

struct point{
    int x, y;
}arr[200005];
point o;

int orientation(point o, point a, point b){
    return (o.x*a.y + a.x*b.y + b.x*o.y) - (o.y*a.x + a.y*b.x + b.y*o.x);
}
int distance(point a, point b){
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

bool comparision(point &a, point &b){
    int ok=orientation(o, a, b);
    if(ok>0)return true;
    else if(ok<0)return false;
    else if(ok==0 && distance(o, a)<=distance(o, b))return true;
    else return false;
}

int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; ++i){
        cin >> arr[i].x >> arr[i].y;
    }
    int ymin=arr[1].y, ind=1;
    for(int i=1; i<=n; ++i){
        if(ymin>arr[i].y){
            ind=i;
            ymin=arr[i].y;
        }
        else if(ymin==arr[i].y && arr[ind].x>arr[i].x){
            ind=i;
        }
    }
    swap(arr[ind], arr[1]);
    o=arr[1];
    sort(&arr[1], &arr[n+1], comparision);
//    for(int i=1; i<=n; ++i)cout << arr[i].x << arr[i].y << endl;
    point f, s;
    f=arr[2];
    s=arr[1];

    stack<point>st;
    st.push(arr[1]);
    st.push(arr[2]);
    for(int i=3; i<=n; ++i){
        int ok=orientation(s, f, arr[i]);
        if(ok>=0){
            s=f;
            f=arr[i];
            st.push(arr[i]);
        }
        else{
            while(orientation(s, f, arr[i])<0){
                f=s;
                st.pop();
                st.pop();
                s=st.top();
                st.push(f);
            }
            st.push(arr[i]);
        }
    }
    while(!st.empty()){
        cout << st.top().x << ' ' << st.top().y << endl;
        st.pop();
    }
    cout << endl;
}
