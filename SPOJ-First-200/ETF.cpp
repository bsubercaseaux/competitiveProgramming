#include<bits/stdc++.h>
#define intt long long int
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n;++i)
#define x first
#define y second
#define ii pair<intt,intt>
 
using namespace std;
const int N = 1e6+1;
int criba[N];
 
int pw(int base, int exp){
	if(exp == 0) return 1;
	if(exp == 1) return base;
	int aux = pw(base,exp/2);
	return aux*aux*pw(base,exp%2);
}
 
int eulerT(int n){
	if(n==1) return 1;
	if(criba[n] == n) return n-1;
	int fd = 0; int c = n; while(criba[n] == criba[c]) {c/= criba[c]; fd++;}
	int k = pw(criba[n],fd-1);
	return (criba[n] - 1)*k*eulerT(n/(k*criba[n]));
}
 
int main(){
		rep(i,N) criba[i] = i;
		for(int i = 2; i*i <= N; ++i) if(criba[i] == i)
			for(int j = i*2; j < N; j+= i) criba[j] = i;
		int T; cin >> T; rep(t,T){
			int n; cin >> n; cout << eulerT(n) << endl;
		}
return 0;}
 