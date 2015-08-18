//HDOJ-4540 SimpleDP
#include <iostream>
using namespace std;

const int MAXN=21, MAXM=11;
int dp[MAXN][MAXM];
int a[MAXN][MAXM];

int min(int a, int b){
	return a<b?a:b;
}
int abs(int a){
	if(a<0)return -a;
	return a;
}

int main(){
	int N, K;
	while(cin >> N >> K){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < K; j++){
				cin >> a[i][j];
			}
		}
		for(int i = 0; i < K; i++){
			dp[0][i] = 0;
		}
		for(int i = 1; i < N; i++){
			for(int j = 0; j < K; j++){
				dp[i][j] = dp[i-1][0]+abs(a[i][j]-a[i-1][0]);
				for(int k = 1; k < K; k++){
					dp[i][j] = min(dp[i][j], dp[i-1][k]+abs(a[i][j]-a[i-1][k]));
				}
			}
		}
		int ans = dp[N-1][0];
		for(int i = 1; i < K; i++) ans = min(ans, dp[N-1][i]);
		cout << ans << endl;
	}
	return 0;
}