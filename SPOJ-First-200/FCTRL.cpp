#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i  <  n; ++ i)
#define intt long long int
 
using namespace std;
 
intt leading(intt n){
  if( n < 5) return 0;
  intt k = 5; intt ans = 0;
  while(k <= n){
    ans += n/k;
    k*=5;
  }
  return ans;
}
 
int main(){
  int T; cin >> T;
  rep(t,T){
    intt n; cin >>  n;
    cout << leading(n) << endl;
  }
return 0;}