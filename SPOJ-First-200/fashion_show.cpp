#include<bits/stdc++.h>

using namespace std;


int main(){
	
	int t; cin >> t;
	while(t-->0){
		int n; cin >> n; vector<int> M(n),W(n);
		for (int i = 0; i < n; ++i) {
			cin >> M[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> W[i];
		} sort(M.begin(),M.end()); sort(W.begin(), W.end());
		int answer = 0; for (int i = 0; i < n; ++i) {
			answer+= M[i]*W[i];
		} cout << answer << '\n';
	} return 0;
}