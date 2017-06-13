#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
#define endl '\n'
#define pb push_back
#define coutv(v)  cout << "v : "; rep(i, v.size())  cout << v[i] << " "; cout << endl;
#define coutvar(n) cout << "n : " << n << endl;

using namespace std;
typedef long long intt;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ii>> vvii;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;
	while(t-->0){
		int E, F; cin >> E >> F;
		int weight = F - E;
		int n; cin >> n; vi p(n), w(n);
		rep(i,n) cin >> p[i] >> w[i];
		int maxS = 10005;
		int dp[maxS]; rep(i, maxS) dp[i] = 1e9;
		dp[0]= 0;
		repx(i, 1, maxS){
			rep(j, n)
				if(i- w[j] >= 0)
					dp[i] = min(dp[i], dp[i - w[j]] + p[j]);
		}
		if(dp[weight] < 1e8)
			cout << "The minimum amount of money in the piggy-bank is " << dp[weight] << "." << endl;
		else
			cout << "This is impossible." << endl;
	}

	return 0;
}