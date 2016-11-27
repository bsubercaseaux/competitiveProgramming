#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
using namespace std;

vector<bool> vis, rec;

bool cycleFrom(int i, vector<vector<int>> &g){
	if(!vis[i]){
		vis[i] = true; rec[i] = true;
		for(int u : g[i]) if(!vis[u] and cycleFrom(u,g)) return true; 
		else if(rec[u]) return true;
	} rec[i] = false; return false;
}

bool hasCycle(vector<vector<int>> &g){
	vis.assign(g.size(),false);
	rec.assign(g.size(),false);
	rep(i,g.size()) if(cycleFrom(i,g)) return true;
	return false;
}

int main(){
	int n; cin >> n;
	map<string,int> M;
	vector<pair<string,string>> edges;
	int t = 0;
	rep(i,n){
		string n1,sg,n2;
		cin >> n1 >> sg >> n2;
		if(sg == ">") swap(n1,n2);
		edges.push_back({n1,n2});
		if(!M.count(n1)) M[n1] = t++;
		if(!M.count(n2)) M[n2] = t++;
	} int v = M.size();
	vector<vector<int>> g(v);
	for(pair<string,string> edge : edges){
		g[M[edge.first]].push_back(M[edge.second]);
	}
	cout << (hasCycle(g) ? "impossible" : "possible") << endl;



return 0;}







