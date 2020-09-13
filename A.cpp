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
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];
	int dp[n+1] = {0};
	dp[0] = 0;
	dp[1] = abs(a[1] - a[0]);
	for(int i=2; i<n; i++){
		dp[i] = min((dp[i-1] + abs(a[i]-a[i-1])), (dp[i-2] + abs(a[i] - a[i-2])));
	}
	cout << dp[n-1] << "\n";
	return 0;
}