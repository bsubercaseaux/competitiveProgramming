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

void divide(intt m, intt n){
	string ans = "0.";
	map<int,int> M;
	intt r = 10*m;
	intt period = 0;
	cout << ans << endl;
	while(r != 0){
		//cout << r << endl;
		if(M.count(r)){
			period = ans.size()-2;
			break;
		}
		ans.pb('0'+r/n);
		M[r]+=1;
		r %= n;
		r *= 10;
	}

	cout << m << "/" << n << " largo periodo =" << period << endl;
}

intt pw(intt base, intt exp){
	if(exp == 0) return 1LL;
	if(exp == 1) return base;
	intt v = pw(base, exp/2);
	return v*v*pw(base, exp%2);
}

int main(){
	//ios::sync_with_stdio(0); cin.tie(0);
	int a1 = 1, b1 = 7;
	rep(i,5){
		a1  = 7LL*a1+1;
		b1 *=7LL;
	}
	intt a = a1, b = b1;
	cout << a << " " << b << endl;
	divide(a,b);

	return 0;
}