#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
using namespace std;

void printarr(vector<auto> vec){
	for(auto el : vec)
		cout << el << " ";
	cout << endl;
}

bool valide(vector<int> partial, vector<int> rat){
	int klo = 1, khi = 1000000000;
	rep(i, partial.size()){
		int lo = ceil(partial[i]/(1.1 * rat[i]));
		int hi = floor(partial[i]/(0.9*rat[i]));
		// cout << "lo and hi" << endl;
		//cout << lo << " " << hi << endl;
		klo = max(klo, lo);
		khi = min(khi, hi);
		//cout << "left " << klo << " high " << khi << endl;
		if(klo > khi) return false;
	}
	return true;
}

int main(){
	
	int T; cin >> T; int cn = 1;
	while(T-->0){
		int n, p; cin >> n >> p;
		vector<int> rat(n); rep(i,n) cin >> rat[i];
		vector< vector<int> > mat(n, vector<int>(p, 0));
		rep(i,n) rep(j,p) cin >> mat[i][j];
		rep(i,n) sort(mat[i].begin(), mat[i].end());
		vector<int> ptrs(n, 0);
		int ans = 0;
		int row = 0;
		while(ptrs[0] < p){
			vector<int> partial_list;
			row = 0;
			while(row < n){
				//cout << "row " << row << " ptr =  " << ptrs[row] << endl;
				partial_list.push_back(mat[row][ptrs[row]]);
				//printarr(partial_list);
				if(!valide(partial_list, rat)) {

					//cout << "invalid list" << endl;
					partial_list.pop_back();
					ptrs[row]++; 
					if(ptrs[row] >= p) {
						if(row == 0) break;
					//	cout << "im done with this row" << row << endl;
						ptrs[row] = 0;
						row--;
						partial_list.pop_back();
					}
				} else {
					//cout << "valid list" << endl;
					
					ptrs[row]++;	
					row++;
				}
			} 
			if(partial_list.size() == n)
				ans++;
			else{
				rep(i,n-1) ptrs[i+1] = 0;
			}
		}
		cout << "Case #" << cn++ << ": " << ans << '\n';
	}

	return 0;
}