#include <iostream>
#include <memory.h>
using namespace std;
const int MAXN = 1001;
int dp[MAXN],value[MAXN],weight[MAXN];
int nValue;

int max(int a, int b){
	return a>b?a:b;
}

void ZeroOnePack(int cost, int weight){
	for(int i = nValue; i >= cost; i--){
		dp[i] = max(dp[i], dp[i-cost]+weight);
	}
}

void work(){
	int N, V;
	cin >> N >> V;
	nValue = V;
	for(int i = 0; i < N; i++){
		cin >> weight[i];
	}
	for(int i = 0; i < N; i++){
		cin >> value[i];
	}
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < N; i++){
		ZeroOnePack(value[i], weight[i]);
	}
	cout << dp[nValue] << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--){
		work();
	}
	return 0;
}