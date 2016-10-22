#include<bits/stdc++.h>
#define rep(i,n) for(int i =0 ; i < (int) n; ++i)
using namespace std;

struct fecha{
    int D,M,Y,C;
};

bool esBisiesto(int a){
    if(a%400 == 0) return true;
    if(a%100 == 0) return false;
    return (!(a%4));
}

bool sonCons(fecha A, fecha B){
    if(B.Y == A.Y + 1){
        return (B.M == 1 and B.D == 1 and A.M == 12 and A.D == 31);
    }
    if(B.Y == A.Y){
        //mismo mes
        if(B.M == A.M) {
            return B.D == A.D + 1;
        }
        if(B.M == A.M + 1){
            if(A.M == 1) return (B.D == 1 and A.D == 31);
                if(A.M == 2) return (B.D == 1 and A.D == ( esBisiesto(A.Y) ? 29 : 28));
                if(A.M == 3)  return (B.D == 1 and A.D == 31);
                if(A.M == 4)  return (B.D == 1 and A.D == 30);
                if(A.M == 5)  return (B.D == 1 and A.D == 31);
                if(A.M == 6) return (B.D == 1 and A.D == 30);
                if(A.M == 7) return (B.D == 1 and A.D == 31);
                if(A.M == 8) return (B.D == 1 and A.D == 31);
                if(A.M == 9) return (B.D == 1 and A.D == 30);
                if(A.M == 10) return (B.D == 1 and A.D == 31);
                if(A.M == 11) return (B.D == 1 and A.D == 30);
        }
    }

    return false;
}

void solve(vector<fecha> &F){
    int sum  = 0;
    int num = 0;
    rep(i,F.size()-1) if(sonCons(F[i],F[i+1])){
        num++; sum += F[i+1].C - F[i].C;
    }
    cout << num << " " << sum << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        int N; cin >> N; if(!N) break;
        vector<fecha> F(N);
        rep(i,N) {
            cin >> F[i].D >> F[i].M >> F[i].Y >> F[i].C;
        }
        solve(F);
    }

return 0;}
