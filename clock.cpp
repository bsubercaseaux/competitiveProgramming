#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define invrep(i, n) for(int i = n-1; i >= 0; --i)
#define endl '\n'
#define pb push_back
#define coutv(v)  cout << "v : "; rep(i, v.size())  cout << v[i] << " "; cout << endl;
#define coutvar(n) cout << "n : " << n << endl;

using namespace std;
typedef long long intt;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vector<int>> vvi;
typedef vector<vector<ii>> vvii;

struct number
{
	vector<string> segments;
};

struct vertical
{
	string points;
};

struct cloc
{
	number n1, n2, n3, n4;
	vertical two_points;
	vector<vector<char>> mat;
};



cloc* get_clock(){
	cloc* c = new cloc;
	number* n1 = new number;
	number* n2 = new number;
	number* n3 = new number;
	number* n4 = new number;
	c->n1 = *n1;
	c->n2 = *n2;
	c->n3 = *n3;
	c->n4 = *n4;
	rep(i,7){
		c->n1.segments.pb("");
		c->n2.segments.pb("");
		c->n3.segments.pb("");
		c->n4.segments.pb("");
	}
	rep(i,7){ 
		c->mat.pb(vector<char>(21));
		c->mat.pb(vector<char>(21));
		c->mat.pb(vector<char>(21));
		c->mat.pb(vector<char>(21));
	}
	rep(i,7) rep(j,21) cin >> c->mat[i][j];
	c->two_points.points = c->mat[2][10] + c->mat[4][10];
	c->n1.segments[0] = c->mat[0][1] + c->mat[0][2]; 
	c->n1.segments[1] = c->mat[1][3] + c->mat[2][3]; 
	c->n1.segments[2] = c->mat[4][3] + c->mat[5][3]; 
	c->n1.segments[3] = c->mat[6][1] + c->mat[6][2]; 
	c->n1.segments[4] = c->mat[4][0] + c->mat[5][0]; 
	c->n1.segments[5] = c->mat[1][0] + c->mat[2][0];
	c->n1.segments[6] = c->mat[3][1] + c->mat[3][2];
	c->n2.segments[0] = c->mat[0][6] + c->mat[0][7]; 
	c->n2.segments[1] = c->mat[1][8] + c->mat[2][8]; 
	c->n2.segments[2] = c->mat[4][8] + c->mat[5][8]; 
	c->n2.segments[3] = c->mat[6][6] + c->mat[6][7]; 
	c->n2.segments[4] = c->mat[5][5] + c->mat[6][5]; 
	c->n2.segments[5] = c->mat[1][5] + c->mat[2][5];
	c->n2.segments[6] = c->mat[3][6] + c->mat[3][7];
	c->n3.segments[0] = c->mat[0][13] + c->mat[0][14]; 
	c->n3.segments[1] = c->mat[1][15] + c->mat[2][15]; 
	c->n3.segments[2] = c->mat[4][15] + c->mat[5][15]; 
	c->n3.segments[3] = c->mat[6][13] + c->mat[6][14]; 
	c->n3.segments[4] = c->mat[5][12] + c->mat[6][12]; 
	c->n3.segments[5] = c->mat[1][12] + c->mat[2][12];
	c->n3.segments[6] = c->mat[3][13] + c->mat[3][14];
	c->n4.segments[0] = c->mat[0][18] + c->mat[0][19]; 
	c->n4.segments[1] = c->mat[1][20] + c->mat[2][20]; 
	c->n4.segments[2] = c->mat[4][20] + c->mat[5][20]; 
	c->n4.segments[3] = c->mat[6][18] + c->mat[6][19]; 
	c->n4.segments[4] = c->mat[5][17] + c->mat[6][17]; 
	c->n4.segments[5] = c->mat[1][17] + c->mat[2][17];
	c->n4.segments[6] = c->mat[3][18] + c->mat[3][19];
	return c;
}

void print_clock(cloc* c){
	rep(i,7) {rep(j,21) cout<<c->mat[i][j]; cout << endl;}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;	
	vector<cloc*> clocks(n);
	rep(i,n) clocks[i] = get_clock();
	print_clock(clocks[0]);
	return 0;
}