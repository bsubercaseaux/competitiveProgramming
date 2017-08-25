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

bool p(int maxx, vi &v, int boxes){

  for(int people : v) {
    int bp = (people + maxx - 1) / maxx;
    boxes -= bp;
    if(boxes < 0) return false;
  }

  return true;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

  while(true){
    int n,b; cin >> n >> b; if(n == -1 and b == -1) break;

    vi v(n); rep(i, n) cin >> v[i];

    int l = 1, r = 5000000;
    while(l != r){
      int m = (l + r) >> 1;
      if(p(m, v, b)) {
        r = m;
      } else {
        l = m + 1;
      }
    }

    cout << l << endl;
  }

	return 0;
}
