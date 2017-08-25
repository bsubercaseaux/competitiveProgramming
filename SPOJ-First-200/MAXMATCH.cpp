#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;

typedef long long ll;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define maxD (1<<18)

const double PI = 3.14159265358979323846264338;

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
	string s;  cin >> s;
   // int n; cin >> n;
    vector<int> A(maxD,0), B(maxD,0),C(maxD,0),AA(maxD,0),BB(maxD,0),CC(maxD,0),D(maxD,0),E(maxD,0),F(maxD,0);

	int fa = -1, fb = -1, fc = -1, id  = 1;
	while(id <= s.size() and s[id-1] != 'a') id++; int ida = id; id = 1;
	while(id <= s.size() and s[id-1] != 'b') id++; int idb = id; id = 1;
	while(id <= s.size() and s[id-1] != 'c') id++; int idc = id;
	int la = 0,lb = 0,lc = 0;
	rep(i,(int)s.size()) {
		if(s[i] == 'a') la = i;
		if(s[i] == 'b') lb = i;
		if(s[i] == 'c') lc = i;
	}

    rep(i,(int)s.size()) A[i] = (s[i] == 'a');
	rep(i,(int)s.size()) B[i] = (s[i] == 'b');
	rep(i,(int)s.size()) C[i] = (s[i] == 'c');

	rep(i,la+1) AA[i] = A[la -i];
	rep(i,lb+1) BB[i] = B[lb -i];
	rep(i,lc+1) CC[i] = C[lc -i];
	MulPol(A,AA,D);
	MulPol(B,BB,E);
	MulPol(C,CC,F);
    vector<int> fA,fB,fC;
	for(int i =ida-1; i < 2*la+1 - (ida-1); ++i) fA.push_back(D[i]);
	for(int i = idb-1; i < 2*lb+1 - (idb-1); ++i) fB.push_back(E[i]);
	for(int i = idc - 1;i < 2*lc+1 - (idc-1); ++i) fC.push_back(F[i]);

	fA.resize(maxD,0); fB.resize(maxD,0); fC.resize(maxD,0);

	vector<int> FinalP(max(la,max(lc,lb)),0);
	rep(i,(int)FinalP.size()){
		if(la-ida+1+i >= 0)FinalP[i] += fA[la-ida+1+i];
		if(lb-idb+1+i >= 0)FinalP[i] += fB[lb-idb+1+i];
		if(lc-idc+1+i >= 0)FinalP[i] += fC[lc-idc+1+i];
	}
	int maxx = -1;
	for(int i = 1; i < FinalP.size();++i)
		if(FinalP[i] > maxx) maxx = FinalP[i];
	cout << maxx << endl;
	vector<int> idd;
	for(int i = 1; i < FinalP.size(); ++i)
		if(FinalP[i] == maxx) idd.push_back(i);
	cout << idd[0];
	rep(i,(int)idd.size()-1) cout << " " << idd[i+1];
	cout << endl;
    return 0;
}
