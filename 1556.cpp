#include <iostream>
#include <memory.h>
using namespace std;

const int MAX=100021;

struct Node{
    int add, sum, l, r;
}t[MAX*3];

int n;

void up(int rt){
    t[rt].sum = t[rt<<1].sum+t[rt<<1|1].sum;
}

void create(int rt, int l, int r){
    t[rt].l = l;
    t[rt].r = r;
    t[rt].add = 0;
    if(t[rt].l == t[rt].r){
        t[rt].sum = 0;
        return;
    }
    int mid = (l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    up(rt);
}

void down(int rt){
    int m = t[rt].r-t[rt].l+1;
    if(t[rt].add){
        t[rt<<1].add+=t[rt].add;
        t[rt<<1|1].add+=t[rt].add;
        t[rt<<1].sum += (m-(m>>1))*t[rt].add;
        t[rt<<1|1].sum += (m>>1)*t[rt].add;
        t[rt].add = 0;
    }
}

void update(int rt, int l, int r){
    if(l<=t[rt].l && t[rt].r<=r){
        t[rt].sum += t[rt].r-t[rt].l+1;
        t[rt].add++;
        return;
    }
    down(rt);
    int mid = (t[rt].l+t[rt].r) >> 1;
    if(l <= mid) update(rt<<1,l,r);
    if(mid < r) update(rt<<1|1,l,r);
    up(rt);
}

int query(int rt, int l, int r){
    if(l <= t[rt].l && t[rt].r <= r) return t[rt].sum;
    down(rt);
    int mid = (t[rt].l+t[rt].r)>>1;
    int le = 0, re = 0;
    if(l <= mid) le = query(rt<<1, l, r);
    if(mid < r) re = query(rt<<1|1, l, r);
    return le+re;
}

void work(){
    int l, r;
    memset(t, 0, sizeof(t));
    create(1,1,n);
    for(int i = 0; i < n; i++){
        cin >> l >> r;
        update(1,l, r);
    }
    for(int i = 1; i < n; i++){
        cout << query(1, i, i) << " ";
    }
    cout << query(1,n,n)<< endl;
}

int main(){
    cin >> n;
    while(n){
        work();
        cin >> n;
    }
}