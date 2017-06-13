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
	int t; cin>> t;
	while(t-->0){
		int p,s; cin >> p;
		bool escala = true;
		rep(i,4) {
			cin >> s; if(s != p+1) escala=false;
			p = s;
		}
		cout << (escala?"Y":"N")<< endl;
	}
	return 0;
}