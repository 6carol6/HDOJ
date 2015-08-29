//HDOJ-1176 SimpleDP
#include <stdio.h>
#include <memory.h>
#include <algorithm>
const int MAXN = 100001;
int dp[MAXN][13];

int max(int a, int b){
	return a>b?a:b;
}

int max(int a, int b, int c){
	return max(a,max(b,c));
}
/*
int cmp(const void *p,const void *q){
	return *(int*)p - *(int*)q;
}
*/
int main(){
	int n;
	scanf("%d", &n);
	while(n){
		memset(dp, 0, sizeof(dp));
		int max_t = 0;
		for(int i = 0; i < n; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			dp[b][a+1] += 1;
			if(max_t < b) max_t = b;
		}
		
		for(int i = max_t-1; i >= 0; i--){
			for(int j = 1; j <= 11; j++){
				dp[i][j] += max(dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]);
			}
		}
		printf("%d\n", dp[0][6]);
		scanf("%d", &n);
	}
	return 0;
}
