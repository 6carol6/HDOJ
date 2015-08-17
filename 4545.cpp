#include <iostream>
#include <string.h>
using namespace std;

const int MAXN=1001;

bool g[30][30];
bool dp[MAXN][MAXN];

void work(){
	memset(g, 0, sizeof(g));
	memset(dp, 0, sizeof(dp));
	string str1, str2;
	int m;
	cin >> str1 >> str2 >> m;
	while(m--){
		string a, b;
		cin >> a >> b;
		g[a[0]-'a'][b[0]-'a'] = true;
	}
	for(int i = 0; i <= str2.length(); i++){
		dp[0][i] = true;
	}
	for(int i = 1; i <= str1.length(); i++){
		for(int j = 1; j <= str2.length(); j++){
			if(dp[i][j-1]) dp[i][j] = true;
			else if(str1[i-1]==str2[j-1]&&dp[i-1][j-1])
				dp[i][j] = true;
			else if(g[str2[j-1]-'a'][str1[i-1]-'a']&&dp[i-1][j-1])
				dp[i][j] = true;
		}
	}
	if(dp[str1.length()][str2.length()]) cout << "happy" << endl;
	else cout << "unhappy" << endl;
}

int main(){
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cout << "Case #" << i << ": ";
		work();
	}
	return 0;
}