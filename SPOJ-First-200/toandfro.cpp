#include<bits/stdc++.h>

using namespace std;


int main(){
	
	while(1){
		int n; cin >> n; if(!n) break;

		string s; cin >> s;
		string ans ="";
		int rws = s.size()/n + (s.size()%n != 0);
		char mat[rws][n];
		int pnt = 0;bool der = true;
		for (int i = 0; i < rws; ++i) {
			for (int j = 0; j < n; ++j) {
				int ji = (der ? j : n-j-1);
				mat[i][ji] = s[pnt++];
			} der^=1;
		}
		for (int j = 0; j < n; ++j) {
			for (int i = 0; i < rws; ++i) {
				ans+= mat[i][j];
			}
		}
		
		cout << ans <<'\n';
	}


	return 0;
}