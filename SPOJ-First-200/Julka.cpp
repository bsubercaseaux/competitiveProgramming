#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define endl '\n'
using namespace std;

vector<int> minnus(vector<int>&a, vector<int>&b){
	assert(a.size() >= b.size());
	vector<int> ans(a.size(), 0);
	vector<int> b2(a.size(), 0);
	
	rep(i, b.size()) b2[i+a.size()-b.size()] =b[i];
	int carry = 0;
	for (int i = a.size()-1; i >= 0; --i) {
		//cout << "a[i] "<< a[i] << " b[i] " << b2	[i] << endl;
		int diff = (10 + a[i] - b2[i] - carry)%10;
		//cout << "diff = " << diff << endl;

		if(b2[i]+ carry > a[i]) carry = 1;
		else{ carry = 0;}
		ans[i] = diff;
		
	}

	return ans;
}


vector<int> division_by_two(vector<int>& number){
	vector<int> answer;
	int carry = 0;
	for (int i = 0; i < number.size(); ++i) {
		if((number[i]+carry)%2 == 0){
			answer.push_back((number[i]+carry)/2);
			carry = 0;
		} else{
			answer.push_back((number[i]+carry)/2);
			carry =10;
		}
	}
	return answer;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	while(1){
		std::vector<int> vn,vk;
		string s1,s2; if(!(cin >> s1 >> s2)) break;
		rep(i, s1.size()) vn.push_back(s1[i] - '0');
		rep(i, s2.size()) vk.push_back(s2[i] - '0');

		std::vector<int> v =  minnus(vn, vk);
		
		std::vector<int> result = division_by_two(v);
		bool nz = false;
		

		v = minnus(vn , result);
		
		for (int i = 0; i < v.size(); ++i) {
			if(!nz and v[i] != 0) nz =true;
			if(nz) cout << v[i];
		}cout << endl;

		nz = false;
		for (int i = 0; i < result.size(); ++i) {
			if(!nz and result[i] != 0) nz =true;
			if(nz) cout << result[i];
		}cout << endl;
	}
	return 0;
}
