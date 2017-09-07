#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
#define pb push_back
#define coutv(v)  cout << #v << ": "; rep(i, v.size())  cout << v[i] << " "; cout << endl;
#define coutvar(n) cout << #n << ": " << n << endl;

using namespace std;
typedef long long intt;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ii>> vvii;

void mul(intt a[2][2], intt b[2][2], intt c[2][2], intt mod){
    intt d[2][2] = {{0LL,0LL},{0LL,0LL}};
    rep(i, 2)
      rep(j, 2){
        rep(k, 2) d[i][j] = (d[i][j]%mod + (a[i][k]%mod * b[k][j]%mod)%mod)%mod;
      }
    rep(i, 2) rep(j, 2) c[i][j] = d[i][j];
}

intt power(intt F[2][2], intt pw, intt mod){
    intt M[2][2] = {{1LL,2LL}, {1LL,0LL}};
    if(pw == 1){
      return (F[0][0]%mod + F[0][1]%mod)%mod;
    }
    power(F, pw>>1, mod);
    mul(F, F, F, mod);
    if(pw%2) mul(F, M, F, mod);
    return (F[0][0]%mod + F[0][1]%mod)%mod;
}

intt ntherm(intt pw, intt mod) {
  intt F[2][2] = {{1LL,2LL}, {1LL,0LL}};
  return power(F, pw-3, mod);
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
  intt N, M; cin >> N >> M;
  switch (N) {
    case 0: {
      cout << 0 << endl;
      break;
    }

    case 1: {
      cout << 0 << endl;
      break;
    }

    case 2: {
      cout << 1 <<  endl;
      break;
    }

    case 3: {
      cout << 1 <<  endl;
      break;
    }

    default:
      cout << ntherm(N, M) << endl;
  }


	return 0;
}
