#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (int)n; ++i)
using namespace std;
 
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    vector<int> P;
    for(int i = 2; i < 100000; ++i){
        bool pr = true;
        for(int j = 2; j*j <= i; ++j){
            if(i%j == 0){
                pr = false;
                break;
            }
        } if(pr)
        P.push_back(i);
    }
 
    while(T-->0){
        int a,b; cin >> a >> b;
        for(int i = max(2,a); i <= b; ++i){
            bool p = true;
            rep(j,P.size()){
                if(P[j] >=i) break;
                if(!(i%P[j])) {
                    p =false; break;
                }
            }
            if(p) cout << i << '\n';
        }
        cout << '\n';
    }
 
 
return 0;}