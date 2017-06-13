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

void convert(vi &a, int n){
	vi b(n); rep(i,n)b[i]=a[i];
	sort(b.begin(), b.end());
	rep(i, n) a[i] = lower_bound(b.begin(),b.end(), a[i])- b.begin() + 1;  
}

int sum(vi& bit, int id){
	int ans = 0;
	while(id > 0){
		ans += bit[id];
		id -= id & (-id); 
	} return ans;
}

void up(vi &bit, int id, int val){
	while(id < bit.size()){
		bit[id] += val;
		id += id&(-id);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n; vector<int> v(n); rep(i,n) cin >> v[i];
	vi bit(n+1, 0);
	rep(i,n) up(bit, i+1, v[i]);
	rep(i,n) cout << sum(bit, i+1) << endl;
	return 0;
}