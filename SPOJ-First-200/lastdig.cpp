#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
	int t ; cin >> t;
	while(t-->0){
		int a, b; cin >> a >> b; if(b == 0) {cout << 1 << endl; continue;}
		int ans = a%10;
		for (int i = 0; i < (b-1)%4; ++i) {
			ans=  (ans*(a%10))%10;
		}
		cout << ans << endl;
	}
}
