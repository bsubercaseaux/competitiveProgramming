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

void dfs(vvi& g, vi &vis, int node){
	vis[node] = 1;
	for(int vec : g[node])
		if(!vis[vec]) dfs(g, vis, vec);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m; cin >> n >> m;
	if(m != n -1) {cout << "NO"<< endl; return 0;}
	vvi g(n);
	rep(i, m){
		int u,v; cin >> u >> v; --u; --v;
		g[u].pb(v); g[v].pb(u);
	}
	vi vis(n, 0);
	dfs(g, vis, 0);
	rep(i, n) if(!vis[i]) {cout << "NO\n" << endl; return 0;}
	cout << "YES" <<endl;
	return 0;
}