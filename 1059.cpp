#include <iostream>
using namespace std;

int nValue, N = 6;
int n[6];
int dp[120001];

int max(int a, int b){
	return a>b?a:b;
}

void CompletePack(int C, int W){
	for(int i = C; i <= nValue; i++){
		dp[i] = max(dp[i], dp[i-C]+W);
	}
}

void ZeroOnePack(int C, int W){
	for(int i = nValue; i >= C; i--){
		dp[i] = max(dp[i], dp[i-C]+W);
	}
}

void MultiplePack(int C, int W, int M){
	if(C*M >= nValue){
		CompletePack(C, W);
		return;
	}
	int k = 1;
	while(k < M){
		ZeroOnePack(k*C, k*W);
		M -= k;
		k *= 2;
	}
	ZeroOnePack(M*C, M*W);
}

int main(){
	int total, cnt = 0;
	while(1){
		total = 0;
		for(int i = 0; i < N; i++){
			cin >> n[i];
			total += (i+1)*n[i];
		}
		if(total == 0) break;
		cout << "Collection #" << ++cnt << ":" << endl;
		if(total%2){
			cout << "Can't be divided." << endl << endl;
			continue;
		}
		nValue = total/2;
		for(int i = 0; i <=nValue; i++){
			dp[i] = 0;
		}
		for(int i = 0; i < N; i++){
			MultiplePack(i+1, i+1, n[i]);
		}
		if(dp[nValue] == nValue){
			cout << "Can be divided." << endl;
		}else{
			cout << "Can't be divided." << endl;
		}
		cout << endl;
	}
	return 0;
}