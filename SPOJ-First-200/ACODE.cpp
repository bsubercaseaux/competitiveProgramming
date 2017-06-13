#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define endl '\n'
using namespace std;


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(1){
		string s; cin >> s; if(s == "0") break;
		long long int dp[5005]; rep(i, 5005) dp[i] = 0LL;
		dp[0] = 1;
		repx(i, 1, s.size()){
			if(s[i]=='0'){
				dp[i] = (i-1 ? dp[i-2]: 1LL);
			} else if(s[i-1] == '0' or s[i-1]>'2' or (s[i-1]=='2' and s[i]>'6')) {
				dp[i] = dp[i-1];
			}
			else {
				dp[i] = dp[i-1] + (i-1 ? dp[i-2] : 1LL);
			}
		}
		cout << dp[s.size() - 1] << endl;
	}
	return 0;
}