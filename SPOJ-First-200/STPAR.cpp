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
	while(1){
		int n; cin >> n; if(!n) break;
		queue<int> s; stack<int>p; rep(i,n) {int k; cin >> k; s.push(k);}
		vi final; int cnt = 1;
		while(final.size() != n){
			int a = s.front();
			if(a == cnt) {final.pb(a); s.pop(); cnt++;}
			else {
				if(!p.empty() and p.top() == cnt){
					p.pop(); final.pb(cnt); ++cnt;
				} else {
					p.push(a); s.pop();
				}
			}
			if(s.empty()) while(!p.empty()){final.pb(p.top()); p.pop();}
		} bool no = false;
		repx(i,1,n) if(final[i] < final[i-1]) {
			cout << "no"<< endl; no = true; break;
		}
		if(!no) cout <<"yes"<< endl;

	}

	return 0;
}