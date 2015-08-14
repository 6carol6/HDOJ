#include <iostream>
#include <memory.h>
using namespace std;
const int MAXN = 1001;
int cost[MAXN];
int dp[MAXN];
int nValue;

int max(int a, int b){
	return a>b?a:b;
}

void OneZeroPack(int cost, int weight){
	for(int i = nValue; i >= cost; i--){
		dp[i] = max(dp[i], dp[i-cost]+weight);
	}
}

int main(){
	int n, m;
	cin >> n;
	while(n != 0){
		for(int i = 0; i < n; i++){
			cin >> cost[i];
			if(cost[i] > cost[0]){
				int tmp = cost[i];
				cost[i] = cost[0];
				cost[0] = tmp;
			}
		}
		cin >> m;
		if(m < 5){
			cout << m << endl;
			cin >> n;
			continue;
		}
		memset(dp, 0, sizeof(dp));
		nValue = m-5;
		for(int i = 1; i < n; i++)
			OneZeroPack(cost[i], cost[i]);
		cout << m - dp[nValue] - cost[0] << endl;
		cin >> n;
	}
	return 0;
}