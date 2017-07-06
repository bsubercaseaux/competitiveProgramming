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

intt min_cost(vector<intt> &p, intt k){
	intt ans = 0;
	vector<intt> cp(p.size());
	rep(i, p.size()) cp[i] = p[i] + (i+1)*k;
	sort(cp.begin(), cp.end());
	rep(i, k) ans += cp[i];
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, s; cin >> n >> s;
	vector<intt> p(n+1); rep(i,n) cin >> p[i]; p[n] = 1e9;
	int lo = 1; int hi = n+1;
	while(lo < hi){
		int m = (lo + hi)/2;
		if(min_cost(p, m) > s){
			hi = m;
		}else{
			lo = m+1;
		}
	}
	cout << lo-1 << " " << min_cost(p, lo-1) << endl;
	return 0;
}