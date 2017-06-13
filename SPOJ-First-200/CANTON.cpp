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



void solve(int n){
	int num = 0, den = 0; int cnt = 1;
	int id = 0;bool right = false;
	while(id < n){
		for (int i = 0; i < cnt; ++i) {
			id++; num = (right ? i+1 : cnt -i);
			if(id == n) break;	
		} cnt++; right^=1;
	} id = 0; cnt = 1; right = true;
	while(id < n){
		for (int i = 0; i < cnt; ++i) {
			id++; den = (right ? i+1 : cnt -i);
			if(id==n) break;
		} cnt ++; right^=1;
	}
	cout << "TERM " <<  n <<" IS " << num << "/" << den << endl;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t-->0){
		int n; cin >> n;
		solve(n);
	}

	return 0;
}