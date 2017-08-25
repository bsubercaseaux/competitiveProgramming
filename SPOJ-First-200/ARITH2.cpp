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

intt operate(intt ans, char op, intt num){
  if(op == '+') ans += num;
  if(op == '-') ans -= num;
  if(op == '*') ans *= num;
  if(op == '/') ans /= num;
  if(op == 'a') ans = num;
  return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

  int T; cin >> T;
  rep(t, T){
    intt ans = 0LL;

    bool loop = true;
    intt num = 0; char op = 'a';
    int cnt = 0;
    while(loop){
      if(cnt & 1) cin >> op;
      else cin >> num;
      if(op == '=') loop = false;
      if((cnt & 1) ==  0) ans = operate(ans, op, num);
      cnt++;
    }

    cout << ans << endl;
  }

	return 0;
}
