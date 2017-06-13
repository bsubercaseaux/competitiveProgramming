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

bool pal(string s){
		rep(i,s.size()/2){
			if(s[i]!= s[s.size() - 1 - i]) return false;
		}
	return true;
}

string inv(string s){
	string ans = "";
	invrep(i, s.size()) ans+=s[i];
	return ans;
}

string suc(string s){
	if(s[s.size()-1] != '9'){
		string ans =""; rep(i,s.size()-1) ans+=s[i]; ans+= (s[s.size()-1] + 1); return ans;
	} 
	int ln = s.size()-1;
	while(s[ln] =='9') ln--;
	if(ln == -1){ string ans = "1"; rep(i,s.size()) ans += '0'; return ans;}
	else{
		string ans ="";
		rep(i, ln) ans +=s[i];
		ans += (s[ln] + 1);
		while(ans.size() < s.size()) ans+= '0';
		return ans;

	}
}

string f(string s){
	string ans = "";
	if(!(s.size()%2)){
		if(pal(s)){
			rep(i, s.size()/2){
				ans+= s[i];
			}
			ans = suc(ans);
			if(ans.size() == s.size()/2)
				ans += inv(ans);
			else{
				int anss= ans.size();
				rep(i,anss-1){
					ans+= ans[anss-2-i];
				}
			}
			return ans;
		} else {
			string half = "", shalf ="";
			rep(i, s.size()/2) {half+=s[i];shalf+=s[s.size()/2+i];}
			string ans = "";
			if(inv(half) > shalf){
				 ans = half;
			} else {
				 ans = suc(half);
			}
			
			string in = inv(ans);
			ans += in;
			return ans;	
		}
	} else{
		if(pal(s)){
			rep(i, s.size()/2+1){
				ans+= s[i];
			}
			ans = suc(ans);
			string cpy = ans;
			if(ans.size()>s.size()/2+1){
				ans = "";
				rep(i,cpy.size()-1) ans+=cpy[i];
			}
			string in = inv(cpy);
			int anss= cpy.size();
			repx(i,1, anss){
				ans += in[i];
			}
			return ans;
		} else{
			string half = "", shalf ="";
			rep(i, s.size()/2) {half+=s[i];shalf+=s[s.size()/2+1+i];}
			if(inv(half) > shalf){
				ans = half;
				string in = inv(ans);
				ans += s[s.size()/2] + in;

			} else {
				ans = suc(half+s[s.size()/2]);
				string in = inv(ans);
				int anss= ans.size();
				repx(i,1, anss){
					ans += in[i];
				}
			}
			return ans;
		}
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin>> t; while(t-->0){
		string s; cin >> s;
		
		cout << f(s) << endl;
	}
	return 0;
}
