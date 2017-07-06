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
	int n, m, k; cin >> n >> m >> k; --m;
	vi v(n); rep(i,n) cin >> v[i];
	repx(i,1,n){
		if(m+i < n and v[m+i] != 0 and v[m+i]<= k){
			cout << 10*i << endl;
			return 0;
		}
		if(m-i >= 0 and v[m-i] != 0 and v[m-i]<= k){
			cout << 10*i << endl;
			return 0;
		}
	}
	return 0;
}