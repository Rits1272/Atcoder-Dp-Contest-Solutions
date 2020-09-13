#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define MAX 1e9
#define MIN -1e9
#define MOD 1000000007
#define println(x) cout << "[" << #x << ":" << x << "]\n"; 
#define print(x) cout << "[" << #x << ":" << x << "] "; 

int main(){
	ios::sync_with_stdio(0); 
    cin.tie(0); 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	vector<string> board(n);
	for(int i=0; i<n; i++){
		cin >> board[i];
	}

	vector<vector<int>> dp(n, vector<int>(m));
	dp[0][0] = 1;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if((i == 0 && j == 0) || board[i][j] == '#')
				continue;
			if(i == 0){
				// We are in first row
				dp[i][j] = dp[i][j-1];
			}

			else if(j == 0){
				// We are in the first column
				dp[i][j] = dp[i-1][j];
			}

			else
				dp[i][j] = dp[i-1][j]%MOD + dp[i][j-1]%MOD;
		}
	}
	dp[n-1][m-1] %= MOD;
	cout << dp[n-1][m-1] << "\n";
	return 0;
}