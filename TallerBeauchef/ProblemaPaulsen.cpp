#include<bits/stdc++.h>
using namespace std;
typedef long long intt;
int x1,x2,y1,y2,xn,yn;

int cross(intt a, intt b, intt c, intt d){
  return (a*d > b*c) - (a*d < b*c);
}

void solve(int x, int y){
  if(cross(x,y,xn,yn) == 0) cout << "C\n";
  else if (cross(x,y,xn,yn)> 0) cout << "I\n";
  else cout << "D\n";
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> x1 >> y1 >> x2 >> y2; xn = x1 - x2; yn = y1 - y2;
  int Q; cin >> Q; int x,y;
  for (size_t i = 0; i < Q; i++) {
     cin >> x >> y;
     solve(x,y);
  }
return 0;}
