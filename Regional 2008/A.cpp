#include<bits/stdc++.h>
#define rep(i,n) for(int i =0 ; i < (int) n; ++i)
using namespace std;

int row_solve(vector<int> &V){
    vector<int> S(V.size());
    S[0] = V[0];
    S[1] = max(V[0],V[1]);
    for(int i = 2; i < V.size(); ++i){
        S[i] = max(S[i-1],S[i-2]+ V[i]);
    }
    return S[V.size()-1];
}


int solve(vector<vector<int>> &MAT){
    vector<int> sols(MAT.size());
    rep(i,MAT.size()) sols[i] = row_solve(MAT[i]);
    return row_solve(sols);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(true){
        int N,M; cin >> N >> M; if(N == 0 and M == 0) break;
        vector<vector<int>> MAT(N,vector<int>(M));
        rep(i,N) rep(j,M) cin >> MAT[i][j];
        cout << solve(MAT) << endl;
    }

return 0;}
