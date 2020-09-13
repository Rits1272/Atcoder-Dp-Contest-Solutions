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

const int mx = 3001;
int lookup[mx][mx];

string LCS(string a, string b, int m, int n){
	if(m == 0 || n == 0)
		return string("");
	if(a[m-1] == b[n-1])
		return LCS(a, b, m-1, n-1) + a[m-1];
	if(lookup[m-1][n] > lookup[m][n-1])
		return LCS(a, b, m-1, n);
	else
		return LCS(a, b, m, n-1);
}

void LCSLength(string a, string b, int m, int n){
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(a[i-1] == b[j-1])
				lookup[i][j] = lookup[i-1][j-1] + 1;
			else
				lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
 		}
	}
}

int main(){
	ios::sync_with_stdio(0); 
    cin.tie(0); 
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	string s, t; cin >> s >> t;
	LCSLength(s, t, s.size(), t.size());
	string ans = LCS(s, t, s.size(), t.size());
	cout << ans << "\n";
	return 0;
}