#include<bits/stdc++.h>
#define rep(i,n) for(int i =0 ; i < (int) n; ++i)
using namespace std;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(true){
        int N,M; cin >> N >> M; if(N == 0 and M == 0) break;
        vector<int> att(N), deff(M);
        rep(i,N) cin >> att[i]; rep(i,M) cin >> deff[i];
        sort(att.begin(),att.end()); sort(deff.begin(),deff.end());
        if(att[0] < deff[0]) { cout << "Y" << endl;}
        else if(att[0] == deff[0] and att[0] < deff[1]) cout << "Y" << endl;
        else if(att[0] < deff[1]) cout << "Y" << endl;
        else cout << "N" << endl;
          }

return 0;}
