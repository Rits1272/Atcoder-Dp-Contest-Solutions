#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define MAX 1e18
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
	int n, W; 
	scanf("%d%d", &n, &W);
	vector<int> w(n), v(n);
	for(int i=0; i<n; i++)
		scanf("%d%d", &w[i], &v[i]);
	int total_sum = 0;
	for(auto x: v)
		total_sum += x;
	vector<ll> dp(total_sum+1, MAX);
	dp[0] = 0;
	for(int i=0; i<n; i++){
		for(int j=total_sum-v[i]; j>=0; j--){
			dp[j+v[i]] = min(dp[j+v[i]], dp[j] + w[i]);
		}
	}

	ll ans = MIN;
	for(int i=0; i<=total_sum; i++){
		if(dp[i] <= W){
			ans = max(ans, (ll)i);
		}
	}

	printf("%lld\n", ans);
	return 0;
}