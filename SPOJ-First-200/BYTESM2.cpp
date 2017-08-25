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
typedef vector<vector<int> > vvi;
typedef vector<vector<ii> > vvii;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

  int T; cin >> T;
  int A[105][105];
  int DP[105][105];

  rep(t,T){
    int r,c; cin >> r >> c;
    rep(i, r) rep(j, c) DP[i][j] = 0;


    rep(i, r) rep(j, c) cin >> A[i][j];
    rep(j, c) DP[0][j] = A[0][j];


    repx(i,  1, r)
      rep(j, c){
        DP[i][j] = max(DP[i][j], DP[i-1][j]);
        if(j-1 >= 0) DP[i][j] = max(DP[i][j], DP[i-1][j-1]);
        if(j+1 < c) DP[i][j] =  max(DP[i][j], DP[i-1][j+1]);
        DP[i][j] += A[i][j];
      }

    int ans = -1;
    rep(j, c) ans = max(ans, DP[r-1][j]);
    cout << ans << endl;

  }

	return 0;
}
