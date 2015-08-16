#include <iostream>
#include <memory.h>
using namespace std;
const int MAXN = 101;
int dp[MAXN], a[MAXN], value[MAXN], weight[MAXN];
int nValue;

int max(int a, int b){
	return a>b?a:b;
}

void OneZeroPack(int c, int w){
	for(int i = nValue; i >= c; i--){
		dp[i] = max(dp[i], dp[i-c]+w);
	}
}

void CompletePack(int c, int w){
	for(int i = c; i <= nValue; i++){
		dp[i] = max(dp[i], dp[i-c]+w);
	}
}

void MultiplePack(int c, int w, int m){
	if(c*m >= nValue){
		CompletePack(c, w);
		return;
	}
	int k = 1;
	while(k <= m){
		OneZeroPack(c*k, w*k);
		m -= k;
		k <<= 1;
	}
	OneZeroPack(c*m, w*m);
}

void work(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> value[i] >> weight[i] >> a[i];
	}
	nValue = n;
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < m; i++){
		MultiplePack(value[i], weight[i], a[i]);
	}
	
	cout << dp[nValue] << endl;
}

int main(){
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}