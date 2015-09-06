//HDOJ-1284 CompletePack
#include <iostream>
#include <memory.h>
using namespace std;
const int MAXN = 32770;
long long ans[MAXN];
int nValue;

void CompletePack(int c, int w){
    for(int i = c; i <= nValue; i++){
        ans[i] += ans[i-c];
    }
}

int main(){
    while(cin >> nValue){
        memset(ans, 0, sizeof(ans));
        ans[0] = 1;
        for(int i = 1; i <= 3; i++){
            CompletePack(i, i);
        }
        cout << ans[nValue] <<endl;
    }
    return 0;
}
