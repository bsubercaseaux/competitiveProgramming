#include<bits/stdc++.h>
#define intt long long int
#define repx(i,x,n) for(int i= x; i < ((int)n); ++i)
#define invrep(i,n) for(int i = n; i >= 0; --i)
#define rep(i,n) repx(i,0,n)
#define first x
#define second y

using namespace std;
map<string,int> M;
vector<char> chars(25);
typedef unsigned long long uintt;
uintt mod[] = {(int)1e9+7, (int)1e9+9};
//largo máximo que puede tener un string
int maxstrlen = 1e6;

class RH {
	static vector<uintt> x[2];
	vector<uintt> h[2];
	string str;
	int n;

	//private: usar el método público para obtener el hash
	uintt hash(int a, int start, int len) {
		uintt ans = 0, end = start + len;
		//descomentar si se consideran substrings cíclicos
		//if (end > n) {end -= n; ans = h[a][0]*x[a][n-start] %mod[a];}
		ans += h[a][start] - h[a][end]*x[a][len] %mod[a] + mod[a];
		return ans %mod[a];
	}

public: RH() {}
	//str: string del cual se producen substrings a hashear
	RH(const string &str) { // complejidad: O(n)
		this->str = str;
		n = str.size();
		if (x[0].empty()) rep(a, 2) {
			x[a].assign(maxstrlen+1, 1);
			rep(i, maxstrlen) x[a][i+1] = x[a][i]*127 %mod[a];
		}
		rep(a, 2) {
			h[a].assign(n+1, 0);
			invrep(i, n) h[a][i] = (h[a][i+1]*127 + str[i]) %mod[a];
		}
	}

	//obtiene el hash de un substring que comienza en el índice “start”
	//y tiene largo “len”.
	uintt hash(int start, int len) { // complejidad: O(1)
		return hash(0, start, len) << 32 | hash(1, start, len);
	}

	//si se usan, insertar aquí los métodos opcionales 1 o 2.
};
//esta línea es importante para que el código compile
vector<uintt> RH::x[2];

string toStr(vector<string> &V){
  string ans = "";
  vector<int> diffs(V.size() -1);
  rep(i,diffs.size()){
    diffs[i] = M[V[i+1]] - M[V[i]]  + ( M[V[i+1]] > M[V[i]] ? 0 :12);
  }
  rep(i,diffs.size()){
    ans += chars[diffs[i] + 11];
  }
	return ans;
}

bool isIn(string a, string b){
  bool ans =false;
  RH ra(a);
  RH rb(b);
  rep(i,a.size() - b.size() + 1)
    if(ra.hash(i,b.size()) == rb.hash(0,b.size())) ans =true;
  return ans;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  rep(i,25){
    chars[i]= 'a' + i;
  }
  M["C"] = 1;
  M["B#"] = 1;
  M["C#"] = 2;
  M["Db"] = 2;
  M["D"] = 3;
  M["Eb"] = 4;
  M["D#"] = 4;
  M["E"] = 5;
  M["Fb"] = 5;
  M["F"] = 6;
  M["E#"] = 6;
  M["F#"] = 7;
  M["Gb"] = 7;
  M["G"] = 8;
  M["G#"] = 9;
  M["Ab"] = 9;
  M["A"] = 10;
  M["A#"] = 11;
  M["Bb"] = 11;
  M["B"] = 12;
  M["Cb"] = 12;
  while(true){
    int N,M; cin >> N >> M; if(N == 0 and M == 0) break;
    vector<string> A(N) , B(M);
    rep(i,N) cin >> A[i];
    rep(i,M) cin >> B[i];
    string AA = toStr(A),  BB = toStr(B);
    cout << (isIn(AA,BB) ? "S" : "N") << endl;
  }


  return 0;
}
