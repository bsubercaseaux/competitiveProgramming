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
	int cn =1;
	while(1){
		string s; cin >> s;
		int ans = 0;
		if(s[0] == '-')break;
		vi p(s.size());
		p[0] = (s[0] == '{' ? 1: -1);
		if(p[0]==-1) p[0]=1, ans++;
		repx(i,1,s.size()) { 
			p[i] = p[i-1] + (s[i] == '{' ? 1: -1);
			if(p[i] == -1) p[i] =1, ans++;
		}
		cout << cn++ << ". " << ans + p[s.size()-1]/2 << endl;

	}

	return 0;
}