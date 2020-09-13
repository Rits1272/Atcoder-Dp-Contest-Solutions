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

void dfs(int node, vector<int> adj[], int dp[], bool vis[]){
	vis[node] = true;
	for(int i=0; i<(int)adj[node].size(); i++){
		if(!vis[adj[node][i]])
			dfs(adj[node][i], adj, dp, vis);
		dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
	}
}

int getLongestPath(vector<int> adj[], int n){
	int dp[n+1];
	memset(dp, 0, sizeof(dp));

	bool vis[n+1];
	memset(vis, false, sizeof(vis));

	for(int i=1; i<=n; i++){
		if(!vis[i])
			dfs(i, adj, dp, vis);
	}

	int ans = 0;

	for(int i=1; i<=n; i++)
		ans = max(ans, dp[i]);

	return ans;
}

int main(){
	ios::sync_with_stdio(0); 
    cin.tie(0); 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int n, m;
	cin >> n >> m;
	vector<int> adj[n+1];
	for(int i=0; i<m; i++){
		int x, y; cin >> x >> y;
		adj[x].pb(y); 
	}
	int ans = getLongestPath(adj, n);
	cout << ans << "\n";
	return 0;
}