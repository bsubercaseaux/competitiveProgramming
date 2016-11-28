#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(int)n; ++i)
using namespace std;

int main(){
  while(true){
    int n;  if(!(cin >> n)) break;
    int ans = 0;
    rep(i,5) {
      int b; cin >> b; ans += (n == b ? 1:0 );
    }
    cout << ans << endl;
  }

  return 0;
}
