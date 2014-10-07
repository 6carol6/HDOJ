#include <stdio.h>
  
int main(){
    int n,m;
    while(scanf("%d %d\n", &n, &m) != EOF){
        printf("%d\n", n+m);
    }
    return 0;
}