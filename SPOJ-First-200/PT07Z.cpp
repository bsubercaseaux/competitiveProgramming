#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
#define endl '\n'
#define pb push_back
#define coutv(v)  cout << #v << ": "; rep(i, v.size())  cout << v[i] << " "; cout << endl;
#define coutvar(n) cout << #n << ": " << n << endl;

using namespace std;
typedef long long intt;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ii>> vvii;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	vvi g(n);
	rep(i, n-1){
			int u,v; cin >> u >> v; --u; --v;
			g[u].pb(v); g[v].pb(u);
	}
	const int inf = 1e9;
	vi d(n, inf);
	d[0] = 0;
	queue<int> q;
	q.push(0);
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int v: g[u]){
			if(d[v] == inf) {
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}

	int longest = -1;
	int md = -1;
	repx(i, 1, n) if(d[i] > md) { md = d[i]; longest = i;}
	q = queue<int>();
	rep(i, n) d[i] = inf;
	d[longest] = 0;
	q.push(longest);
	while(not q.empty()){
		int u = q.front();
		q.pop();
		for(int v: g[u]){
			if(d[v] == inf){
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
	int ans = -1;
	rep(i,n) ans = max(ans, d[i]);
	cout << ans << endl;

	return 0;
}	