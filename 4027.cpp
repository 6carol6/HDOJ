#include <stdio.h>
#include <math.h>
using namespace std;

typedef long long ll;

const int MAXN = 100010;

struct Node{
    int l, r, tag;
    ll sum;
}t[MAXN<<2];
ll a[MAXN];

int n;

void up(int rt){
    t[rt].sum = t[rt<<1].sum + t[rt<<1|1].sum;
    t[rt].tag = t[rt<<1].tag && t[rt<<1|1].tag;
}

void create(int rt, int l, int r){
    t[rt].l = l;
    t[rt].r = r;
    t[rt].sum = 0;
    t[rt].tag = 0;
    if(l == r){
        t[rt].sum = a[l];
        return;
    }
    int mid = (l+r)>>1;
    create(rt<<1, l, mid);
    create(rt<<1|1, mid+1, r);
    up(rt);
}

void update(int rt, int l, int r){
    if(t[rt].tag) return;
    if(t[rt].l >= l && t[rt].r <= r){
        if(t[rt].l == t[rt].r){
            t[rt].sum = (ll)floor(sqrt(t[rt].sum));
            if(t[rt].sum < 2) t[rt].tag = 1;
            return;
        }
    }
    //if(t[rt].l == t[rt].r) return;
    int mid = (t[rt].l+t[rt].r) >> 1;
    if(l <= mid) update(rt<<1, l, r);
    if(mid < r) update(rt<<1|1, l, r);
    up(rt);
}

ll query(int rt, int l, int r){
    if(t[rt].l >= l && t[rt].r <= r){
        return t[rt].sum;
    }
    
    int mid = (t[rt].l+t[rt].r)>>1;
    ll le = 0, re = 0;
    if(l<= mid) le = query(rt<<1, l, r);
    if(mid < r) re = query(rt<<1|1, l, r);
    return le+re;
}

void work(){
    for(int i = 1; i <= n; i++){
        //cin >> a[i];
        scanf("%lld",&a[i]);
    }
    create(1, 1, n);
    int m;
    //cin >> m;
    scanf("%d",&m);
    for(int i = 0; i < m; i++){
        int T,x,y;
        scanf("%d%d%d", &T, &x, &y);
        if(x>y){
            int tmp = x;
            x = y;
            y = tmp;
        }
        //cin >> T >> x >> y;
        if(T){
            printf("%lld\n", query(1, x, y));
            //cout << query(1, x, y) << endl;
        }else{
            update(1, x, y);
        }
    }
}

int main(){
    int idx = 1;
    while(scanf("%d",&n) != EOF){
        printf("Case #%d:\n", idx++);
        //cout << "Case #"<<idx++<<":"<<endl;
        work();
        printf("\n");
    }
    return 0;
}