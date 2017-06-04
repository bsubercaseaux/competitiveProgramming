#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef complex<double> cd;
typedef vector<cd> vcd;
#define maxD (1<<19) // potencia de 2 !!
const double PI = 2*acos(0);
cd W[maxD][2], a[maxD],aa[maxD],b[maxD],bb[maxD],cc[maxD], c[maxD];
void fft(cd *v, cd *a, int step, int size, int dir) {
	if (size == 1) a[0] = v[0];
	else{
	 size /=2;
	 fft(v, a, step*2, size, dir);
	 fft(v + step, a + size, step*2, size, dir);
	 rep(i,size) {
	 cd even = a[i]; cd odd = a[i + size];
	 a[i] = even + W[i*step][dir] * odd;
	 a[i + size] = even + W[i*step + maxD / 2][dir] * odd;
	 }
	 }
}
void MulPol(vector<int> &A, vector<int> &B, vector<int> &C){
 rep(i,maxD) {
 double ang = 2*PI*i / maxD;
a[i] = cd(A[i],0); b[i] = cd(B[i],0);
W[i][0] = cd(cos(ang), sin(ang));
W[i][1] = cd(W[i][0].real(), -W[i][0].imag());
}
fft(a,aa,1,maxD,0); fft(b,bb,1,maxD,0);
rep(i,maxD) cc[i] = aa[i] * bb[i];
fft(cc, c, 1, maxD, 1);
rep(i,maxD) c[i] /= maxD;
rep(i,maxD) C[i] = (int)round(c[i].real());
}
int main() {
 string s; // cin >> s;
int n; cin >> n;
vector<int> A(maxD,0), B(maxD,0),C(maxD);
rep(i,n+1) cin >> A[i];
rep(i,n+1) cin >> B[i];
MulPol(A,B,C);
 rep(i,2*n+1) cout << C[i] << " ";
return 0;
}
