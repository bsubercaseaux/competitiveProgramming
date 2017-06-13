#include<bits/stdc++.h>
using namespace std;
 
int inv(int A){
    int ans = 0;
    while(!(A%10)) A/= 10;
    while(A){
        ans *= 10;
        ans += A%10;
        A /= 10;
    }
    return ans;
}
 
int main(){
    int T; cin >> T;
    while(T-->0){
        int A,B; cin >> A >> B;
        cout << inv(inv(A)+ inv(B)) << '\n';
    }
 
 
return 0;}