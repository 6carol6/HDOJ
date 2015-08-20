#include <iostream>
#include <memory.h>
using namespace std;

const int MAXN = 51;
int value[MAXN], num[MAXN];
int dp[250001];
int nValue;

int max(int a, int b){
	return a>b?a:b;
}

void ZeroOnePack(int v, int w){
	for(int i = nValue; i >= v; i--){
		dp[i] = max(dp[i], dp[i-v]+w);
	}
}

void CompletePack(int v, int w){
	for(int i = v; i <= nValue; i++){
		dp[i] = max(dp[i], dp[i-v]+w);
	}
}

void MultiplePack(int v, int w, int m){
	if(v*m >= nValue){
		CompletePack(v, w);
		return;
	}
	int k = 1;
	while(k < m){
		ZeroOnePack(k*v, k*w);
		m -= k;
		k <<= 1;
	}
	ZeroOnePack(m*v, m*w);
}

int main(){
	int N;
	cin >> N;
	while(N > 0){
		nValue = 0;
		for(int i = 0; i < N; i++){
			cin >> value[i] >> num[i];
			nValue += value[i]*num[i];
		}
		int t = nValue;
		nValue /= 2;
		memset(dp, 0 ,sizeof(dp));
		for(int i = 0; i < N; i++){
			MultiplePack(value[i], value[i], num[i]);
		}
		while(dp[nValue] != nValue) nValue--;
		cout << t-nValue << " " << nValue << endl;
		cin >> N;
	}
	return 0;
}