#include<bits/stdc++.h>
#define intt long long int
#define rep(i,n) for(int i = 0; i < (int )n; ++i)

using namespace std;

void coutv(vector<intt> V){
  cout << V[0];
  rep(i,V.size()-1) cout << " " << V[i+1];
  cout << endl;
}

bool eval(vector<intt> perm, vector<intt> V, intt K){
  intt s = 0;
  rep(i,perm.size()) s += perm[i]*V[i];
  return (s <= K);
}

bool nextperm(vector<intt> &perm){
  for(int i = 9; i >= 0; --i)
    for(int j = i - 1; j >= 0; --j){
      if(perm[j] < perm[i]){
        swap(perm[i],perm[j]);
        return true;
      }
    }
  return false;
}

int main(){
  vector<intt> V(10); rep(i,10) cin >> V[i];
  intt K; cin >> K;
  vector<intt> perm {0,1,2,3,4,5,6,7,8,9};
  while(true){
    if(eval(perm,V,K)) {coutv(perm); break;}
    if(!nextperm(perm)) {cout << "-1" << endl; break;}
  }



return 0;}
