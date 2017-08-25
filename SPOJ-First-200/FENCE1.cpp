#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
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

const double PI = acos(-1.0);

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  cout << fixed;
  cout << setprecision(2);
  while(1){
    double l; cin >> l;
    // perimeter = l --> pi*r = l --> r = l/pi --> area = pi/2 *r*r = l*l/2*pi
    if(l < 0.5) break;
    cout << l*l/(2.0*PI) << endl;
  }

	return 0;
}
