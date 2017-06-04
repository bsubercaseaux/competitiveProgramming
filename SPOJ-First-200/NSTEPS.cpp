#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y; cin >> x >> y;
		if(x == y or y + 2 == x){
			cout << ( x%2 ? x+y-1: x+y ) <<'\n';
		} else {
			cout <<  "No Number\n";
		}
	}
	return 0;
}