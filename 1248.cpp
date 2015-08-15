//HDOJ-1248 CompletePack

#include <iostream>
#include <memory.h>
using namespace std;

const int MAXN = 10001;
int dp[MAXN];
int value[3] = {150, 200, 350};
int nValue;

int max(int a, int b){
	return a>b?a:b;
}

void CompletePack(int cost, int weight){
	for(int i = cost; i <= nValue; i++){
		dp[i] = max(dp[i], dp[i-cost]+weight);
	}
}

void work(){
	int N;
	cin >> N;
	nValue = N;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < 3; i++){
		CompletePack(value[i], value[i]);
	}
	cout << nValue - dp[nValue] << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}