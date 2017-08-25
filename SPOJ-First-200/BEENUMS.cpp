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
  set<int> S;
  int b = 1;
  int c = 6;
  while(b <= (int)2*1e9){
    S.insert(b);
    b += c;
    c += 6;
  }
  while(1){
    int n; cin >> n; if(n == -1) break;
    cout << (S.count(n) ? "Y\n" : "N\n");
  }
	return 0;
}
