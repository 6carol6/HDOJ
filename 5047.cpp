#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory.h>
//#include <time.h>
using namespace std;

long long n, n0, g;
int i, l;
long long a[50], b[50];
void work()
{
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    
    scanf("%I64d", &n);
    l = 1;
    n0 = n;
    while (n != 0)
    {
        a[l] = n % 10;       
        n = n / 10;
        l++;    
    }
    
    g = 0;
    for (i=1; i<=l*2+1; i++)
    {
        g = g + a[i]*n0*8;
        b[i] = g % 10;
        g = g / 10;
    } 

    g = 0;
    for (i=1; i<=l+1; i++)
    {
        g = g + a[i]*7;
        a[i] = g % 10;
        g = g / 10;
    } 

    i = 1;
    while (b[i] == 9) 
    {
        b[i] = 0; i++;
    }
    b[i]++;

    g = 0;
    for (i=1; i<=l*2+1; i++)
    {
        g = b[i]-a[i]-g;
        if (g>=0) {b[i] = g;g = 0;}  
        else {b[i]= g+10;g = 1;}
    } 

    g = l*2+1;
    while (b[g] == 0) g--;
    for (i=g; i>=1; i--) printf("%I64d", b[i]);
    printf("\n");
    
}

int main()
{
// //     freopen("in.txt","r",stdin);
// freopen("out.txt","w",stdout);
//clock_t start,finish;
    //start=clock();

    long t,j;
    scanf("%ld", &t);
    for (j=1; j<=t; j++) 
    { 
        printf("Case #%ld: ", j);
        work();
    } 
  
  //      freopen("CON","w",stdout);
  //  finish=clock();
  //  printf("%lf ms\n",1000*(double)(finish-start)/CLOCKS_PER_SEC);

}