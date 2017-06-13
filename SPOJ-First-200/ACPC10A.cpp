#include<bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c;
	while(1){
		cin >> a >> b>>c; if(a ==0 and b==0 and c==0) break;
		if(c-b == b-a){
			cout <<"AP " << c + (b-a)<<"\n";
		} else {
			cout << "GP " << c*(b/a) <<'\n';
		}
	}

	return 0;
}