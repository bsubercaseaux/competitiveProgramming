#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
#define endl '\n'
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

int DP[6101][6101];
const int E = -1;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t; while(t-->0){
		string s; cin >> s;
		invrep(i, s.size())
			repx(j, i+1, s.size()+1){
				if(s[i] == s[j-1])
					DP[i][j] = DP[i+1][j-1];
				else DP[i][j] = 1 + min(DP[i+1][j], DP[i][j-1]);
			}

		cout << DP[0][s.size()] << endl;
	}

	return 0;
}