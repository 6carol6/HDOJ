#include <iostream>
#include <cstdio>
using namespace std;
int count;
void work(int n){
    count = 0;
    int judge = 0;
    int before, now = 0;
    for(int i = 0; i < n; i++){
        before = now;
        //cin >> now;
        scanf("%d", &now);
        if(now-before > 3){
            count = 0;
            for(int j = i+1; j < n; j++){
                cin >> now;
            }
            return;
        }
        else if(now == before && now != 1){
            count = 0; 
            for(int j = i+1; j < n; j++){
                cin >> now;
            }
            return;
        }
        if(before * now == 2) count++;
        //if(before == 2 && now == 1) count++;
    }
    if(now == 0) count++;
    else
        count = count*2+2;

}
int main(){
    int T;
    //cin >> T;
    scanf("%d\n", &T);
    for(int i = 1; i <= T; i++){
        int n;
        //cin >> n;
        scanf("%d\n", &n);
        work(n);
        cout << "Case #" << i << ": " << count << endl;
    }
    return 0;
}