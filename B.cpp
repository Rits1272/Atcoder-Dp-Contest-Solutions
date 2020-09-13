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
	int n, k; cin >> n >> k;
	int h[n];
	for(int i=0; i<n; i++)
		cin >> h[i];
	int dp[n];
	for(int i=0; i<n; i++)
		dp[i] = MAX;
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	for(int i=2; i<n; i++){
		for(int j=1; j<=k; j++){
			if(i-j >= 0)
				dp[i] = min(abs(h[i] - h[i-j]) + dp[i-j], dp[i]);
		}
	}
	cout << dp[n-1] << "\n";
	return 0;
}