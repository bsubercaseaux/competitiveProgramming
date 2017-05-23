#include<bits/stdc++.h>
#define repx(i,x,n) for(int i= x;i <(int)n; ++i)
using namespace std;

int initial(vector<vector<int> > &PS, int a, int b, int c, int d){
	int res = PS[c][d];
	
	if(a > 0) res -= PS[a-1][d];
	if(b > 0) res -= PS[c][b-1];
	if(a > 0 and b > 0) res+= PS[a-1][b-1];
	
	return (res>1);
}



int main(){

	int t; cin >> t; int cn = 1;
	while(t-->0){
		int r,c; cin >> r >>c;
		
		vector<vector<char>> M(r,vector<char>(c));
		vector<pair<int,int>> original_letters;
		repx(i,0,r)
			repx(j,0,c){
				cin >> M[i][j];
				if(M[i][j] != '?'){
					original_letters.push_back(make_pair(i,j));
				}
			}
		
		vector<vector<int>> PS(r, vector<int>(c, 0));
		
		
		
		// for each letter find the maximal K-expansion and fill it.
		for(pair<int,int> letter : original_letters){
			int i = letter.first;
			int j = letter.second;
			int cj = j, clj = j;
			int ci = i, cli = i;

			repx(i,0,r)
			repx(j, 0, c){
				PS[i][j] = (M[i][j] != '?');
				if (i) PS[i][j] += PS[i-1][j];
				if(j) PS[i][j] +=  PS[i][j-1];
				if(i and j) PS[i][j] -= PS[i-1][j-1];
							
			}


			//cout <<"voy a pintar con la letra " << M[i][j] << endl; 

			while(cj < c-1 and not initial(PS, i,j,i,cj+1)) ++cj;
			while(clj > 0 and not initial(PS, i, clj-1, i, cj)) --clj;
			while(cli > 0 and not initial(PS, cli-1, clj, i, cj)) --cli;
			while(ci < r-1 and not initial(PS, cli,  clj, ci+1, cj)) ++ci;
			
			//cout <<"entre " << cli <<" , " << clj << " y " << ci << " , " << cj << endl;
			repx(l, cli, ci + 1)
				repx(m, clj, cj + 1)
					M[l][m] =  M[i][j];

			
		}

		// answer print
		cout << "Case #" << cn++ <<":\n";
		repx(i, 0, r){
			repx(j, 0, c){
				cout << M[i][j];
			} cout <<'\n';
		}


	}
	return 0;

}
