#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define endl '\n'
#define mod 1000000007
#define coutv(v)  //cout << #v << " : "; rep(i, v.size())  cout << v[i] << " "; cout << endl;
#define coutvar(n) //cout << #n << " : " << n << endl;
using namespace std;
typedef pair<int,int> pii;

void dfs(vector<vector<pii>> &g, vector<int>&p, int node, int parent){
	p[node] = parent;
	rep(i, g[node].size()){
		if(g[node][i].first != p[node]){
			dfs(g, p, g[node][i].first, node);
		}
	}
}


pair<long long, long long> f(vector<vector<pii>> &g, vector<int>&p, int node){
	if(g[node].size() == 0 or g[node].size() == 1 and g[node][0].first == p[node]) return {0LL, 1LL};

	long long ans = 0LL; long long sP = 0LL, sG = 0LL;
	
	
	vector<long long> G(g[node].size(),0LL), H(g[node].size(),0LL);
	rep(i, g[node].size()){
		if(g[node][i].first != p[node]){
			pair<long, long> par = f(g, p, g[node][i].first);
			G[i] = (par.second%mod * g[node][i].second)%mod;
			H[i] = par.first%mod;
		}
	}

	rep(i, g[node].size()){
		if(g[node][i].first != p[node]){
			sP= (sP%mod + H[i]%mod)%mod;
			sG= (sG%mod + G[i]%mod)%mod;
		}
	} ans = (ans%mod + (sP%mod + sG%mod)%mod)%mod;
	
	long long add = 0LL;
	vector<long long> S(g[node].size(), 0LL);
	
	for (int i = g[node].size()-2; i >= 0; --i) {
			S[i] = (S[i+1]%mod +G[i+1]%mod)%mod;
	} 
	
	rep(i, g[node].size()){
		if(g[node][i].first != p[node])
			add  = (add%mod + (G[i]%mod * S[i]%mod)%mod)%mod;
	}
	ans = (ans%mod + add%mod)%mod;
	return {ans, sG+1};
}
	




int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<vector<pii>> g(n, vector<pii>());
	rep(i, n-1){
		int a,b,w; cin >> a >> b >> w; --a; --b;
		g[a].push_back({b, w});
		g[b].push_back({a,w});
	}

	vector<int> p(n);
	dfs(g, p, 0, 0);
	
	
	pair<long long, long long> ans = f(g,p,0);
	cout << ans.first << endl;
	return 0;
}

