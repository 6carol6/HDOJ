#include <iostream>
#include <math.h>
#define eps 1e-8
#define fabs(x) ((x)>0?(x):-(x))
#define zero(x) (fabs(x) < eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
#define MAXN 1000
#define offset 10000
#define sqr(x) ((x)*(x))
using namespace std;

const double pi = acos(-1.0);

struct Point{
    double x;
    double y;
};

struct Line{
    Point a;
    Point b;
};

double xmult(Point &p1, Point &p2, Point &p0){
    return (p1.x-p0.x)*(p2.y-p0.y) - (p2.x-p0.x)*(p1.y-p0.y);
}

int dots_inline(Point &p1, Point &p2, Point &p3){
    return zero(xmult(p1, p2, p3));
}

int same_side(Point &p1, Point &p2, Line &l){
    return xmult(l.a, p1, l.b)*xmult(l.a, p2, l.b) > eps;
}

int dot_online_in(Point &p, Line &l){
    return zero(xmult(p, l.a, l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}

int intersect_in(Line &u, Line &v){
    if(!dots_inline(u.a, u.b, v.a) || !dots_inline(u.a, u.b, v.b)){
        return !same_side(u.a, u.b, v) && !same_side(v.a, v.b, u);
    }
    return dot_online_in(u.a, v) || dot_online_in(u.b, v) || dot_online_in(v.a, u) || dot_online_in(v.b, u);
}

int N;
Line lines[101];

int main(){
    cin >> N;
    while(N != 0){
        int count = 0;
        for(int i = 0; i < N; i++){
            cin >> lines[i].a.x >> lines[i].a.y;
            cin >> lines[i].b.x >> lines[i].b.y;
        }
        for(int i = 0; i < N-1; i++){
            for(int j = i+1; j < N; j++){
                if(intersect_in(lines[i], lines[j])) count++;
            }
        }
        cout << count << endl;
        cin >> N;
    }
    return 0;
}