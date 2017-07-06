#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int T; cin >> T;
	vector<bool> P(N,false);
	while(T--)
	{
		int N; cin >> N;
		rep(i, N) P[i] = false;
		string ans = "0.";
		int r = 10;
		while(r != 0)
		{
			if(P[r]) break;
			ans.push_back('0'+r/N);
			P[r] = true;
			r %= N;
			r *= 10;
		}

		cout << ans << '\n';
	}

	return 0;
}