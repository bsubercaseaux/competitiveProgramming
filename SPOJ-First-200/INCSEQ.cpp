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

const int mod = 5000000;

void convert(vi &a, int n){
	vi b(n); rep(i,n)b[i]=a[i];
	sort(b.begin(), b.end());
	rep(i, n) a[i] = lower_bound(b.begin(),b.end(), a[i])- b.begin() + 1;  
}

int sum(vi &bit, int id){
	int ans = 0;
	while(id > 0){
		ans = (ans%mod +bit[id]%mod)%mod;
		id -= id&(-id);
	}
	return ans;

}

void update(vi &bit, int id, int val){
	while(id < bit.size()){
		bit[id] = (bit[id]%mod + val%mod)%mod;
		id += id & (-id);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, k; cin >> n >> k;
	vector<int> v(n); rep(i,n) cin >> v[i];
	convert(v, n);
	vvi bits(k+1, vi(10002, 0));
	int s[n+1][k+1]; rep(i, n+1) rep(j, k+1) s[i][j]=0;

	s[0][1] = 1;
	rep(i, n) {
		s[i][0] = 1;
		s[i][1] = i+1;
		
	}
	update(bits[0], v[0], 1);
	update(bits[1], v[0], 1);
	repx(i, 1, n){

		update(bits[0], v[i], 1);
		update(bits[1], v[i], 1);

		repx(j,2,k+1){
			s[i][j] = s[i-1][j]%mod;
			//cout << "n : " << i << " k : " << j << endl;
			//cout << "hay " << s[i-1][j] << " incseqs que terminan en el anterior" << endl;
			int finish_here = sum(bits[j-1], v[i]-1);
			//cout << " y " << finish_here << " que terminan aqui " << endl;
			update(bits[j], v[i], finish_here);
			s[i][j] = (s[i][j]%mod + finish_here%mod)%mod;
		}
	}



	cout << s[n-1][k] << endl;
	return 0;
}