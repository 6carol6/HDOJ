#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

const int MAXN = 10001;
double dp[MAXN], weight[MAXN];
int value[MAXN];
int nValue;

double min(double a, double b){
	return a<b?a:b;
}

void ZeroOnePack(int cost, double weight){
	for(int i = nValue; i >= cost; i--){
		dp[i] = min(dp[i], dp[i-cost]*weight);
	}
}

int main(){
	int n, m;
	cin >> n >> m;
	double ans = 0;
	while(n!=0 || m!=0){
		nValue = n;
		for(int i = 0; i < m; i++){
			cin >> value[i] >> weight[i];
			weight[i] = 1-weight[i];
		}
		for(int i = 0; i <= nValue; i++){
			dp[i] = 1;
		}
		for(int i = 0; i < m; i++){
			ZeroOnePack(value[i], weight[i]);
		}
		ans = (1- dp[nValue])*100.0;
		printf("%.1f%%\n", ans);
		cin >> n >> m;
	}
	return 0;
}