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
	int n; cin >> n;
	double p[n];
	for(int i=1; i<=n; i++)
		cin >> p[i];
	double hprob[n+1][n+1];
	memset(hprob, 0, sizeof hprob);
	hprob[0][0] = 1;

	for(int i=1; i<=n; i++){
		hprob[0][i] = (1 - p[i]) * hprob[0][i-1];
		for(int j=1; j<=i; j++)
			hprob[j][i] = p[i] * hprob[j-1][i-1] + (1 - p[i]) * hprob[j][i-1];
	}

	// for(int i=0; i<=n; i++){
	// 	for(int j=0; j<=n; j++)
	// 		cout << hprob[i][j] << " ";
	// 	cout << endl;
	// }

	double ans = 0;
	for(int i=n/2+1; i<=n; i++)
		ans += (double)hprob[i][n];
	cout << fixed << setprecision(10) << ans << "\n";
	return 0;
}