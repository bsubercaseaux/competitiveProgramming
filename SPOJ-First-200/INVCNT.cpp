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

void convert(vi &a, int n){
	vi b(n); rep(i,n)b[i]=a[i];
	sort(b.begin(), b.end());
	rep(i, n) a[i] = lower_bound(b.begin(),b.end(), a[i])- b.begin() + 1;  
}

intt sum(int bit[], int id){
	intt ans =0;
	while(id > 0){
		ans += bit[id];
		id -= id&(-id);
	}
	return ans;
}

void update(int bit[], int n, int id, int val){
	while(id <= n){
		bit[id]+=val;
		id += id&(-id);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin>>t;
	while(t-->0){
		int n; cin >> n;
		vi a(n); rep(i,n) cin >> a[i];
		convert(a, n);
		int bit[n+1]; rep(i,n+1) bit[i] =0;
		intt ans = 0;
		invrep(i,n){
			ans += sum(bit, a[i]-1);
			update(bit, n, a[i], 1);
		}	
		cout << ans << endl;
	}
	return 0;
}