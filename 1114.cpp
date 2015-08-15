//HDOJ-1114 CompletePack
#include <iostream>
using namespace std;

const int MAXN = 501;
int dp[10001];
int weight[MAXN], value[MAXN];
int nWeight;

int min(int a, int b){
	return a<b?a:b;
}

void CompletePack(int c, int w){
	for(int i = c; i <= nWeight; i++){
		dp[i] = min(dp[i], dp[i-c]+w);
	}
}

void work(){
	int E, F, N;
	cin >> E >> F >> N;
	for(int i = 0; i < N; i++){
		cin >>  value[i] >> weight[i];
	}
	nWeight = F-E;
	dp[0] = 0;
	for(int i = 1; i <= nWeight; i++){
		dp[i] = 9999999;
	}

	for(int i = 0; i < N; i++){
		CompletePack(weight[i], value[i]);
	}
	if(dp[nWeight] == 9999999){
		cout << "This is impossible." << endl;
	}else{
		cout << "The minimum amount of money in the piggy-bank is " << dp[nWeight] <<"."<<endl;
	}
}

int main(){
	int T;
	cin >> T;
	while(T--) work();
	return 0;
}