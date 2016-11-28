#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(int)n; ++i)
using namespace std;

int main(){
   vector<int> V{1,10,100,1000,10000};
  while(true){
    int n;  if(!(cin >> n)) break;
    int m; cin >> m;
    int ans = 0;
    rep(i,m){
        int B; cin >> B; int sum = 0;
        int d; cin >> d; rep(j,n-1) {int a; cin >> a; sum+=a;} int win = ( d + sum <= B ? d: 0 );
        int p = 0;
        rep(k,5) if(V[k] + sum <= B) p = max(p,V[k] - win);
        ans += p;
    } cout << ans  << endl;
  }
  return 0;
}
