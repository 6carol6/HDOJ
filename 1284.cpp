#include <iostream>
#include <memory.h>
using namespace std;
const int MAXN = 32770;
int weight[3] = {1,2,3};
int dp[MAXN];
long long ans[MAXN];
int nValue;

int max(int a, int b){
	return a>b?a:b;
}

CompletePack(int c, int w){
	for(int i = c; i <= nValue; i++){
		dp[i] = max(dp[i-c]+w, dp[i]);
		if(dp[i] == dp[i-c]+w){
			ans[i] += ans[i-c];
		}
		
	}
}

int main(){
	while(cin >> nValue){
		memset(dp, 0, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		ans[0] = 1;
		for(int i = 0; i < 3; i++){
			CompletePack(weight[i], weight[i]);
		}
		cout << ans[nValue] <<endl;
	}
	return 0;
}