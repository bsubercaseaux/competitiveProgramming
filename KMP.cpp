#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
#define endl '\n'
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


void fill_lps(string pat, vi &lps){
	lps[0] = 0; int i = 1; int len = 0;
	while(i < pat.size()){
		if(pat[i] == pat[len]){
			len++; lps[i] = len; ++i;
		} else {
			if(len != 0){
				len = lps[len-1];
			} else {
				lps[i] = 0;
				++i;
			}
		}		
	}
}

void KMP(string pat, string text){
	int i = 0; int j = 0;
	vi lps(pat.size()); fill_lps(pat, lps);
	while(i < text.size()){
		if(pat[j] == text[i]) ++i, ++j;
		if(j == pat.size()) {
			cout << "pat found : " << i - j << endl;
			j = lps[j-1]; 
		} else if(i < text.size() and pat[j] != text[i]){
			if(j > 0) j =lps[j-1];
			else i++;
		}
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	string a;
	string b;
	cin >> a >> b;
	KMP(a, b);
	return 0;
}	