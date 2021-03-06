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

map<int,intt> M;

intt f(int n){
	if(n == 0)return 0LL;
	if(M.count(n)) return M[n];
	return M[n] = max((intt)n, f(n/2) + f(n/3) + f(n/4));
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(1){
		int n; if(!(cin >>n)) break;
		cout << f(n) << endl;
	}
	return 0;
}