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

  int f[105][505];

  while(1){
    int b, n; cin >> b >> n;
    if(b == 0 and n == 0) break;

    vi v(n), c(n); rep(i, n) cin >> c[i] >> v[i];
    rep(i, 105) rep(j, 505) f[i][j] = 0;

    rep(p, b+1) f[0][p] = ( c[0] > p ? 0 : v[0]);

    repx(i, 1, n)
      rep(p, b+1)
          if(c[i] > p) f[i][p] = f[i-1][p];
          else f[i][p] = max(f[i-1][p], f[i-1][p - c[i]] + v[i]);

    // f[i][p] = f[i-1][p], f[i-1][p - c[i]] + v[i]

    rep(p, b+1) if(f[n-1][p] == f[n-1][b])  {cout << p  << " " << f[n-1][p] << endl; break;}
  }

	return 0;
}
