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
  while(t--){
    intt a, b, c;
    cin >> a >> b >> c;
    intt n = 2*(c/(a+b)) + (c%(a+b) ? 1 : 0);
    cout << n << endl;
    intt step = (b - a) / (n-5);
    intt in = a - 2*step;
    rep(i, n-1){
      cout << in + i*step<< " ";
    } cout << in + (n-1)*step << endl;
  }
	return 0;
}
