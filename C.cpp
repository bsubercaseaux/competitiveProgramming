#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
#define endl '\n'
#define pb push_back
#define coutv(v)  cout << "#v : "; rep(i, v.size())  cout << v[i] << " "; cout << endl;
#define coutvar(n) // cout << #n << " : " << n << endl;

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
	vi a(n); rep(i,n) cin >> a[i];
	vvi g(n, vector<int>()); rep(i, n-1) {
		int u, v; cin >> u >> v; --u;--v;
		g[u].pb(v); g[v].pb(u);
	}
	int ans = -2*1e9; int snode = -1;
	rep(i,n) ans= max(ans, a[i]);
	int m2 = 0, m1 = 0; rep(i,n){
		if(a[i]==ans) m2++;
		if(a[i]==(ans-1)) m1++;
	} int mx=ans;
	ans=mx+2;
	coutvar(mx);
	rep(i,n) {
	
		if(a[i]==mx)m2--;
		if(a[i]==mx-1)m1--;
		for(int neigh:g[i]){
			if(a[neigh]== mx) m2--, m1++;
			if(a[neigh]== mx-1)m1--;
		}


		if(m2==0){
			ans = min(ans, mx+1);
			if(m1==0) ans = min(ans, mx);
		}

		if(a[i]==mx)m2++;
		if(a[i]==(mx-1))m1++;
		for(int neigh:g[i]){
			if(a[neigh]==mx) m2++, m1--;
			if(a[neigh]==mx-1)m1++;
		}

	}
	cout << ans << endl; 

	return 0;
}