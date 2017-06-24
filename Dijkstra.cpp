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
const int inf = 1e9;

void dijkstra(vvii &g, vi &d, int start){
	priority_queue<ii, vii, greater<ii>> q;
	q.push({0, start});
		d[start] = 0;
		while (not q.empty()) {
				int priority = q.top().first, u = q.top().second;
				q.pop();
				for (ii p : g[u]) {
						int v = p.first, w = p.second;
						if (d[u] + w < d[v]) {
								d[v] = d[u] + w;
								q.push({d[v], v});
						}
				}
		}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		unordered_map<string,int> M;
		int n; cin >> n; 
		vvii g(n); 
		
		rep(i, n){
			g[i].clear();
			string name; cin >> name;
			M[name] = i;
			int p; cin >> p;
			rep(j, p){
				int id, cost; cin >> id >> cost;
				--id;
				g[i].pb({id, cost});
			}
		}
		int r; cin >> r;
		vi d(n); 
		rep(i, r){
				rep(k,n) d[k] = inf;
				string s1, s2; cin >> s1 >> s2;
				dijkstra(g, d, M[s1]);
				cout << d[M[s2]] << endl;
		}
		
	}
	return 0;
}