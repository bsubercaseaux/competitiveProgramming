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

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int N, A; cin >>N >> A;
	vi v(N); rep(i,N) cin >> v[i];
	int ans = -1; int ca = 0; map<int,int> M;
	vi avai(1e6+1, 1); avai[A] = 0;
	rep(i, N){
		if(v[i] == A) ca++;
		else {
			if(M[v[i]] < ca){
				avai[v[i]] = 0;
			} else {
				M[v[i]]+=1;
			}
		}
	}

	repx(i,1, 1e6+1){
		if(avai[i] and M.count(i) and M[i] >= ca){
			cout << i << endl; return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}