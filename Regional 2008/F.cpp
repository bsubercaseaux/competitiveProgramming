#include<bits/stdc++.h>
#define rep(i,n) for(int i =0 ; i < (int) n; ++i)
#define inf 1000000000
#define par pair<int,int>
using namespace std;




void dijkstra(int start, vector<vector<int>> &mat, vector<int> &dist){
    priority_queue<par, vector<par>, greater<par>> q;
    q.push({0, start});
    dist[start] = 0;
    while (not q.empty()) {
        int priority = q.top().first, u = q.top().second;
        q.pop();
        if (priority != dist[u])
            continue;
        rep(i,mat.size()) {
            if(mat[u][i] != inf){
            int v = i, w = mat[u][i];
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }

}
}

void coutv(vector<int> &v){
    cout << v[0]; rep(i,v.size()-1) cout << " " << v[i+1]; cout << endl;
    return;
}

void coutm(vector<vector<int>> &mat){
    rep(i,mat.size()) coutv(mat[i]);

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(true){
        int N, M; cin >> N >> M; if(N == 0 and M == 0) break;
        int S,D; cin >> S >> D;
        vector<vector<int>> MAT(N,vector<int>(N,inf));
        vector<vector<int>> USA(N,vector<int>(N,inf));
        rep(i,M) {
            int u,v,p; cin >> u >> v >> p; MAT[u][v] = p;
        }
        vector<int> d1(N,inf), d2(N,inf), d3(N,inf);

        //coutm(MAT);
        rep(i,N) rep(j,N) USA[i][j] = MAT[j][i];
        //coutm(USA);
        dijkstra(S,MAT,d1);
        //coutv(d1);

        dijkstra(D,USA,d2);
        //coutv(d2);

        rep(i,N) rep(j,N) {
                if(d1[i] + MAT[i][j] +  d2[j] == d1[D]) MAT[i][j] = inf;
        }
        coutm(MAT);
        dijkstra(S,MAT,d3);
        if(d3[D] < inf) cout << d3[D] << endl;
        else{ cout <<  -1 << endl;}
    }
return 0;}
