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
	ios::sync_with_stdio(0);  cin.tie(0);
  int N; cin >> N; int cnt = 0;
  while(N != 1 and N!=4){
    int d = 0;
    while(N){
      d += (N%10)*(N%10);
      N/=10;
    }
    N = d;
    ++cnt;
  }
  cout << (N == 1 ? cnt : -1) << endl;
	return 0;
}
