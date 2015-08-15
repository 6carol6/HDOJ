//HDOJ-4508 CompletePack

#include <iostream>
#include <memory.h>
using namespace std;

const int MAXN = 101;

int dp[100001];
int value[MAXN], weight[MAXN];
int nValue;

int max(int a, int b){
	return a>b?a:b;
}

void CompletePack(int c, int w){
	for(int i = c; i <= nValue; i++){
		dp[i] = max(dp[i], dp[i-c]+w);
	}
}

int main(){
	int n;
	while(cin >> n){
		int m;
		for(int i = 0; i < n; i++){
			cin >> weight[i] >> value[i];
		}
		cin >> m;
		nValue = m;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++){
			CompletePack(value[i], weight[i]);
		}
		cout << dp[nValue] << endl;
	}
	return 0;
}