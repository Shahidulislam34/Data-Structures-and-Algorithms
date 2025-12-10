#include<bits/stdc++.h>
using namespace std;

///computational geometry----
double eps = 1e-10;
double pi = acos(-1.0);
int sgn(double dif) {//check difference is zero, negative, or positive
    if (fabsl(dif) <= eps) return 0;
    else if (dif > 0) return 1;
    else return -1;
}
struct point {
    double x, y;
    void read() { cin >> x >> y; }
    point(double xx = 0, double yy = 0) { this->x = xx, this->y = yy; }
    point operator + (point b) { return point(x + b.x, y + b.y); }
    point operator - (point b) { return point(x - b.x, y - b.y); }
    point operator * (double b) { return point(1.0 * x * b, 1.0 * y * b); }
    point operator / (double b) { return point(1.0 * x / b, 1.0 * y / b); }
    bool operator == (point b) { return x == b.x && y == b.y; }
    bool operator < (point b) { return x == b.x ? (y < b.y) : (x < b.x); }
    double len() { return sqrtl(x * x + y * y); }
    double norm() { return x * x + y * y; }
};
point rot(point a, double thi) { return {a.x * cos(thi) - a.y * sin(thi), a.x * sin(thi) + a.y * cos(thi)}; }
double clamp(double a, double l, double r) { return max(l, min(a, r)); }
double dot(point a, point b) { return a.x * b.x + a.y * b.y; }
double angle(point a, point b) { return acos(clamp(dot(a, b) / (a.len() * b.len()), -1.0, 1.0)); }
double cross(point a, point b) { return a.x * b.y - b.x * a.y; }
double orient(point a, point b, point c) { return sgn(cross(b - a, c - a)); }
double area(point a, point b, point c) { return fabsl(cross(b - a, c - a)); }
tuple<double, double, double> line(point a, point b) { return {a.y - b.y, b.x - a.x, cross(a, b)}; }
double rad_to_deg(double thi) { return (thi * 180) / pi; }
double deg_to_rad(double thi) { return (thi * pi) / 180; }
double proj(point a, point b) { return dot(a, b) / a.len(); } //projection of b on vector a
point line_intersec_point(double a1, double b1, double c1, double a2, double b2, double c2) {
    return {(b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1),
    (c1 * a2 - c2 * a1) / (a1 * b2 - a2 * b1)};
}
bool on_segment(point p, point a, point b) {
    if (fabsl(cross(b - a, p - a)) > eps) return false;
    if (proj(b - a, p - a) < 0) return false;
    else if (proj(b - a, p - a) > (b - a).len()) return false;
    else return true;
}
bool on_ray(point p, point a, point b) {
    if (orient(a, b, p) != 0) return false;
    else if (sgn(proj(b - a, p - a)) == -1) return false;
    else return true;
}
bool seg_inter(point a, point b, point p, point q) {
    if (orient(a, b, p) != orient(a, b, q) && orient(p, q, a) != orient(p, q, b)) return true;
    if (orient(a, b, p) == 0 && on_segment(a, b, p)) return true;
    else if (orient(a, b, q) == 0 && on_segment(a, b, q)) return true;
    else if (orient(p, q, a) == 0 && on_segment(p, q, a)) return true;
    else if (orient(p, q, b) == 0 && on_segment(p, q, b)) return true;
    else return false;
}
double point_to_line_dis(point p, point q, point r) {
    auto [a, b, c] = line(q, r);
    return fabs((a * p.x + b * p.y + c) / sqrtl(a * a + b * b));
}
double point_to_ray_dis(point p, point s, point d) {
    if (proj(d - s, p - s) < 0) return (p - s).len();
    else return point_to_line_dis(p, s, d);
}
double point_to_seg_dis(point p, point q, point r) {
    if (proj(r - q, p - q) < 0) return (p - q).len();
    else if (proj(q - r, p - r) < 0) return (p - r).len();
    else return point_to_line_dis(p, q, r);
}
double seg_to_seg_dis(point a, point b, point p, point q) {
    if (seg_inter(a, b, p, q)) return 0;
    else return min({point_to_seg_dis(a, p, q), point_to_seg_dis(b, p, q),
                    point_to_seg_dis(p, a, b), point_to_seg_dis(q, a, b)});
}
///computational geometry----

int32_t main() {
    point a(3, 0), b(3, 3);
    point c = a + b;
    cout << c.x << ' ' << c.y << endl;
    cout << (b - a).norm() << endl;
    cout << (b - a).len() << endl;
    cout << (180 * angle(a, b)) / acos(-1.0) << endl;

    if (a < b) cout << "YES" << endl;
    else cout << "NO" << endl;
}
