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
  while(1){
    int A,D; cin >> A >> D; if(A == 0 && D == 0) break;
    vi va(A); rep(i, A) cin >> va[i];
    vi vd(D); rep(i, D) cin >> vd[i];
    sort(va.begin(), va.end());
    sort(vd.begin(), vd.end());

    cout << (va[0] < vd[1]  ? "Y" : "N") << endl;

  }
	return 0;
}
