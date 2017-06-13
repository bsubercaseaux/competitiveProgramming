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
	intt a[10000];
	a[1] =3;
	repx(i,2,10000) a[i]=a[i-1]+i+1;
	int t; cin >> t; while(t-->0){
		int n; cin >> n;
		int lo=1;
		int hi=10000;
		bool found = false;
		while(lo < hi){
			int m=(lo+hi)/2;
			if(a[m] == n){
				cout << m << endl;
				found=true;
				break;
			}
			if(a[m]>n){
				hi=m;
			} else {
				lo=m+1;
			}

		}
		if(!found)cout << "No solution" << endl;
	}
	return 0;
}