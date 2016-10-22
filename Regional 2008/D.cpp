#include<bits/stdc++.h>
#define rep(i,n) for(int i =0 ; i < (int) n; ++i)
using namespace std;

void solve(vector<bool>&points,int S, int N){
    for(int i = N; i >= 3; --i){

        if(S%i == 0){
        int siz = S/i;
        for(int j = 0; j < siz; ++j){
            bool works = true;
            rep(k,i){
                if(!points[(j+k*siz)%S]) works = false;

            }

            if(works) {cout << N -i << endl; return;}
        }

    }
    }
    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(true){
       int N; cin >> N; if(N == 0)  break;
       vector<int> C(N); int S = 0; rep(i,N){
            cin >> C[i]; S += C[i];
        }
       vector<bool> points(S,false);
       points[0] =true;
        int last = 0;
       rep(i,N) {
        last += C[i];
        points[last%S] = true;
       }
       solve(points,S,N);
    }

return 0;}
