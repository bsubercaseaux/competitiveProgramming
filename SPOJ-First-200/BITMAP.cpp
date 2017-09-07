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
  int t; cin >> t;
  ii vdirectores[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
  int inf = 1e9;
  while(t--){
    int n, m; cin >> n >> m;
    int mat[n][m]; int ans[n][m];
    rep(i, n) {string s; cin >> s; rep(j, m) mat[i][j] =  s[j] - '0';}
    queue<ii> q;
    rep(i, n)
      rep(j, m){
        if(mat[i][j]) {
          ans[i][j] = 0; q.push({i, j});
        }
        else {
          ans[i][j] = inf;
        }
      }
    while(!q.empty()){
      ii par = q.front(); q.pop();
      for(ii vd : vdirectores){
        int x = par.first + vd.first, y = par.second + vd.second;
        if(x < 0 || x >= n || y < 0 || y >= m) continue;
        if(ans[x][y] == inf){
          ans[x][y] = ans[par.first][par.second] + 1;
          q.push({x, y});
        }
      }
    }
    rep(i, n) {
      rep(j, m) cout << ans[i][j] << (j == m-1 ? "": " ");
      cout << endl;
    }
  }
	return 0;
}
