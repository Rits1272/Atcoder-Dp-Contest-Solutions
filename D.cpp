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
	int n, W; cin >> n >> W;
	ll dp[W+1] = {0};

	for(int i=0; i<n; i++){
		int w, v; cin >> w >> v;
		// print(w) println(v)
		for(int j= W-w; j>=0; j--){
			// print(j) print(j+w) print(dp[j+w])
			dp[j+w] = max(dp[j+w], dp[j]+v);
			// println(dp[j+w])
		}
	}

	ll ans = 0;
	for(int i=0; i<=W; i++)
		ans = max(ans, (ll)dp[i]);
	cout << ans << "\n";
	return 0;
}