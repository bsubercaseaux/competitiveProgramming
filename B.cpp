#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
#define endl '\n'
#define pb push_back
#define coutv(v)  cout << "v : "; rep(i, v.size())  cout << v[i] << " "; cout << endl;
#define coutvar(n) cout << "n : " << n << endl;

using namespace std;
typedef long long intt;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ii>> vvii;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, k; cin >> n >> m >> k;
	map<int,int> h; rep(i,m) {int hi; cin>>hi; --hi; h[hi]+=1; }
	int bone = 0;
	if(h.count(0)){
		cout << 1 << endl; return 0;
	}
	rep(i,k){
		int a,b; cin >> a >> b; a--; b--;
		
		if(bone == a){
			if(h.count(b)){
				bone = b; break;
			}
			bone = b;
			
		}
		else if(bone == b){
			if(h.count(a)){
				bone = a; break;
			}
			bone = a;
		}


	}

	cout << bone+1 << endl;
	return 0;
}