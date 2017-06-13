#include<bits/stdc++.h>

using namespace std;

struct bt {
	char val;
	bt *left;
	bt *right;

} ;

bool in(char c, string s){
	for(char d  : s){
		if(d == c) return true;
	}
	return false;
}


bt *generate_tree(string expression, int i, int j, vector<int> precedence){
	if(i >= j) return nullptr;

	int mx = -1; int mxid = i;
	bt* ans = new bt;
	for(int l = i; l < j; ++l){
		if(precedence[l] > mx){
			mx = precedence[l]; mxid = l;
		}
	}
	ans->val = expression[mxid];
	ans->left = generate_tree(expression, i, mxid, precedence);
	ans->right = generate_tree(expression, mxid+1, j, precedence);

	return ans;
}

string rpn(bt* btree) {
	if(btree->left == nullptr and btree->right == nullptr){
		string ans = ""; ans += btree->val; return ans;
	} return rpn(btree->left) + rpn(btree->right) + btree->val;
}

bool normal_char(char c){
	string prec = "()^+-*/";
	return (!in(c, prec));
}

int main(){
	
	int t; cin >> t;
	while(t-->0){
		string ar_exp; cin >> ar_exp;

		vector<string> precedences;
		precedences.push_back("*/");
		precedences.push_back("+-");

		vector<int> ar_pre(ar_exp.size());
		int prec_counter = 1;
		for (int i = 0; i < ar_exp.size(); ++i){
			if(normal_char(ar_exp[i])){
				ar_pre[i] = 0;
			}
		}

		vector<int> par_degree(ar_exp.size(), 0);
		int cnt = 0; int mxcnt = -1;
		for (int i = 0; i < ar_exp.size(); ++i) {
			if(ar_exp[i] == '(') ++cnt;
			else if(ar_exp[i] == ')') --cnt;
			else{ par_degree[i] = cnt;}
			if(cnt > mxcnt) mxcnt = cnt;
		}

		for(int j = mxcnt; j >= 0; --j){
			for (int i = ar_exp.size(); i >=  0; --i) {
				if(par_degree[i] == j){
					if(ar_exp[i] == '^')
						ar_pre[i] = prec_counter++;
				}
			}

			for (string precedence : precedences) {
				for (int i = 0; i < ar_exp.size(); ++i) {
					if(par_degree[i] == j){
						if(in(ar_exp[i], precedence)){
							ar_pre[i] = prec_counter++;
						}
					}
				}
			}
			
		}

		string unpar_exp = "";
		vector<int> unpar_pre;
		for (int i = 0; i < ar_exp.size(); ++i) {
			if(ar_exp[i] != '(' and ar_exp[i] != ')'){
				unpar_exp+= ar_exp[i];
				unpar_pre.push_back(ar_pre[i]);
			}
		}
		//output;
		
		bt *ans = generate_tree(unpar_exp, 0, unpar_exp.size(), unpar_pre);
		
		cout << rpn(ans) << '\n';
	}



}