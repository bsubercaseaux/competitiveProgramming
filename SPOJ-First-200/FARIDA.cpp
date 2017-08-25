#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
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

  int T; cin >> T;
  intt f[10005];
  rep(t, T){
    int n; cin >> n;
    if(n == 0) {cout << "Case " << t+1 << ": " << 0 << endl; continue;}
    vector<intt> m(n); rep(i, n) cin >> m[i];
    rep(i, n) f[i] = 0LL;

    rep(i, n){
      if(i-2 >= 0) f[i] = max(f[i-2] + m[i], f[i-1]);
      else if(i-1 >= 0) f[i] = max(f[i-1], m[i]);
      else f[i] = m[i];
    }

    cout << "Case " << t+1 << ": " << f[n-1] << endl;

  }

	return 0;
}
