#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
#define endl '\n'
#define pb push_back
#define coutv(v) // cout << "v : "; rep(i, v.size())  cout << v[i] << " "; cout << endl;
#define coutvar(n) cout << #n << ": " << n << endl;

using namespace std;
typedef long long intt;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ii>> vvii;

struct bt
{
	char val;
	bt* left;
	bt* right;
	
};

bt* generate_tree(string& line, int i, int j, vector<int>& precedence){
	if(i>=j) return nullptr;
	bt* ans = new bt;
	int mx = -1; int mxid = i;
	repx(k,i,j) if(precedence[k]>mx){
		mx=precedence[k]; mxid=k;
	}
	ans->val = line[mxid];
	ans->left = generate_tree(line, i, mxid, precedence) ;
	ans->right = generate_tree(line, mxid+1, j, precedence) ; 


	return ans;
}

bool eval_tree(bt* tree){
	if(tree->val == 'V') return true;
	if(tree->val == 'F') return false;
	if(tree->val == '+') return (eval_tree(tree->left) or eval_tree(tree->right));
	if(tree->val == '*') return (eval_tree(tree->left) and eval_tree(tree->right)); 
	if(tree->val == '#') return not eval_tree(tree->left);
	return true;
}



int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int nmbr = 1;
	while(1){
		string dumb; if(!getline(cin, dumb)) break;
		string line_dumb =""; for(char c : dumb) if(c!=' ') line_dumb+=c;
		string line = "";
		vector<int> ps(line_dumb.size(),0);
		ps[0]= (line_dumb[0]=='('?1:0);
		repx(i,1,line_dumb.size()) { if(line_dumb[i] == '(') ps[i]=ps[i-1]+1; else if(line_dumb[i] == ')') ps[i] = ps[i-1] -1;}
		rep(i, line_dumb.size()-1){
			line+=line_dumb[i];
			if(((line_dumb[i] >= 'A' and line_dumb[i] <= 'Z') or line_dumb[i]==')') and line_dumb[i+1] != '+' and line_dumb[i+1]!='#' and line_dumb[i+1] != ')'){
				line+='*';
			}
		}line+= line_dumb[line_dumb.size()-1]; 
		coutvar(line);
		vector<int> precedence(line.size(), 0);
		string prec_order = "#+";

		vector<int> par_degree(line.size(), 0);
		int cnt = 0; int mxcnt = -1;
		rep(i, line.size()) {
			if(line[i] == '(') ++cnt;
			else if(line[i] == ')') --cnt;
			else{ par_degree[i] = cnt;}
			if(cnt > mxcnt) mxcnt = cnt;
		}

		coutv(par_degree); coutvar(mxcnt);
		int prec_counter = 1;
		invrep(i, mxcnt+1){
			for(char c : prec_order){
				rep(j, line.size()){
					if(par_degree[j] == i){
						if(line[j] == c){
							precedence[j] = prec_counter++;
						}
					}
				}
			}
		}
		coutv(precedence);

		string unpar_line = "";
		vector<int> unpar_prec;
		rep(i, line.size()){
			if(line[i] != '(' and line[i] != ')'){
				unpar_line+=line[i];
				unpar_prec.pb(precedence[i]);
			}
		}

		bt* ans_tree = generate_tree(unpar_line, 0, unpar_line.size(), unpar_prec);
		cout << ans_tree->val << endl;
		//cout << "Expression " << nmbr++ << ": " << (eval_tree(ans_tree) ? "V" : "F") << endl;


	}

	return 0;
}
