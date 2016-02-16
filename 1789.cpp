/*
 * HDOJ-1789
 * 贪心
 * 按照分数从大到小排序，同分的按ddl从小到大排序。
 * 然后一个一个看能不能放进去，放不进去就加上罚分。
*/
#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

struct HmWk{
    int ddl;
    int score;
}homework[1000];

int N;
bool used[1000000];

void input(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> homework[i].ddl;
    }
    for(int i = 0; i < N; i++){
        cin >> homework[i].score;
    }
    memset(used, 0, sizeof(used));
}

bool cmp(HmWk a, HmWk b){
    if(a.score == b.score){
        return a.ddl < b.ddl;
    }
    return a.score > b.score;
}

void work(){
    int ans = 0;
    input();
    sort(homework, homework+N, cmp);
    for(int i = 0; i < N; i++){
        //cout << homework[i].score<<endl;
        int j;
        for(j = homework[i].ddl; j > 0; j--){
            if(!used[j]){
                used[j] = true; break;
            }
        }
        if(j == 0) ans += homework[i].score;
    }
    cout << ans << endl;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        work();
    }
    return 0;
}