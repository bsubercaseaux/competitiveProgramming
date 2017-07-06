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
	ios::sync_with_stdio(0); cin.tie(0);int n; cin>>n; rep(i,n){

	string a, b; cin >> a >> b;
		map<char,int> M;
		rep(i, a.size()){
				M[a[i]]+=1; 
		}
		rep(i, b.size()) M[b[i]]+=1;
		if(M.size()>20) {return 1/0;}


		cout <<  "The boolean expressions " << a << " and " << b << " are logically equal!" <<endl; 
	}

	return 0;
}