#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
using namespace std;
 
int main(){
	while(true){
			int n; cin >> n; if(n == -1) break;
			vector<int> V(n); rep(i,n) cin >> V[i];
			int mean = 0; rep(i,n) mean += V[i];
			if(mean % n != 0) {
				cout << "-1\n"; continue;
			} mean /= n;
			int ans = 0;
			rep(i,n) if(V[i] < mean) ans += (mean -V[i]);
			cout << ans << '\n';
	}
return 0;}