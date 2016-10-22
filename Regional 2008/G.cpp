#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (int)n; ++i)
#define repx(i,x,n) for(int i = x; i< (int)n; ++i)
#define inf 1000000000
using namespace std;

void solve(int k, string A, string B){
  int n = A.size(), m = B.size();
  vector<vector<int>> LCS(n+1, vector<int> (m+1,0)), CL(n+1,vector<int> (m+1,0));
  repx(i,1,n+1) repx(j,1,m+1) {
    LCS[i][j] = max(LCS[i][j], max(LCS[i][j-1],LCS[i-1][j]));
    if(A[i-1] == B[j-1]) CL[i][j] = CL[i-1][j-1] + 1;
    else CL[i][j] = 0;
    if(CL[i][j] >= k) repx(z,k,CL[i][j]+1) LCS[i][j] = max( max(LCS[i][j-1],LCS[i-1][j]),max(LCS[i][j],LCS[i-z][j-z] + z));
  }
  cout << LCS[n][m] << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  while(true){
    int k; string A,B; cin >> k;if(k == 0) break; cin >> A >> B;
    solve(k,A,B);
  }
return 0;}
