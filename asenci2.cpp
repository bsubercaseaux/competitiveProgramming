#include <iostream>
#include <vector>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define point pair<int,int>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid){
    point robot, princess;
    rep(i,n) rep(j,n) if(grid[i][j] == 'm') {robot.first = i; robot.second = j;} else if (grid[i][j] == 'p') {princess.first= i; princess.second =j;}
    int dx = robot.second - princess.second;
    int dy = robot.first - princess.first;
    rep(i,max(dx,-1*dx)) cout << ((dx > 0) ? "LEFT" : "RIGHT") << endl;
    rep(i,max(dy,-1*dy)) cout << ( (dy > 0 )? "UP" : "DOWN") << endl;
}
int main(void) {

    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
