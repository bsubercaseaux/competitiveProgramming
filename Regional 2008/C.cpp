#include<bits/stdc++.h>
#define rep(i,n) for(int i =0 ; i < (int) n; ++i)
using namespace std;

void solve(vector<int> &C, vector<int> &P){
    vector<int> F(C.size(),-1);
    rep(i,C.size()){
        if(((i + P[i]) >= F.size()) or F[i + P[i]] != -1){
            cout << -1 << endl; return;
        } else{
            F[i + P[i]] = C[i];
        }
    }
    cout << F[0]; rep(i,F.size() - 1) cout << " " << F[i+1];
    cout << endl;

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(true){
       int N; cin >> N; if(N == 0)  break;
       vector<int> C(N),P(N); rep(i,N) cin >> C[i] >> P[i];
       solve(C,P);
    }

return 0;}
