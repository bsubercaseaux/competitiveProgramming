#include<bits/stdc++.h>
using namespace std;
typedef long long intt;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;
	while(t--){
		intt n ; cin >> n;
		cout << n*(n+2)*(2*n+1)/8 << endl;
	}

	return 0;
}