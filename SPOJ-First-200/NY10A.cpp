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

int countOc(string a, string b){
  int ans = 0;
  rep(i, b.size() - a.size() + 1){
    bool m = true;
    rep(j, a.size()) if(a[j] != b[i+j]) m =  false;
    if(m) ans++;
  }
  return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  rep(t,T){
    int N; cin >> N;
    string s; cin >> s;
    vi occ(8, 0);
    string s3[8] = {"TTT", "TTH", "THT", "THH", "HTT", "HTH", "HHT", "HHH"};
    rep(i, 8)
      occ[i] += countOc(s3[i], s);
    cout << N << " ";
    rep(i, 7) cout << occ[i] << " "; cout << occ[7] << endl;
  }

	return 0;
}
