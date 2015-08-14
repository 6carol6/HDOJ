#include <iostream>
#include <memory.h>
using namespace std;

const int MAXN = 101;

float dp[10010];
int value[MAXN];
float weight[MAXN];
int nValue, ans;

float max(float a, float b){
	return a>b?a:b;
}

void ZeroOnePack(int cost, float weight){
	for(int i = nValue; i >= cost; i--){
		dp[i] = max(dp[i], dp[i-cost]*weight);
	}
}

void work(){
	int N; float P;
	cin >> P >> N;
	nValue = 0, ans = 0;
	for(int i = 0; i < N; i++){
		cin >> value[i] >> weight[i];
		weight[i] = 1-weight[i];
		nValue += value[i];
	}
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 0; i < N; i++){
		ZeroOnePack(value[i], weight[i]);
	}
	for(int i = nValue; i >= 0; i--){
		if(dp[i] >= 1-P){
			if(ans < i) ans = i;
		}
	}
	cout << ans << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}