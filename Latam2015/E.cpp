#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(int)n; ++i)
#define repx(i,x,n) for(int i = x; i <(int)n; ++i)
#define inf 1000000000
using namespace std;

int M[10005][205][2];

struct cc{
    int costo = 0;
    int dsp = 0, ppp = 0;
};

void dfs_getter(vector<vector<int>> &G,int u, vector<int> &S, vector<int> &T, vector<bool> &marked, cc &comp){
    marked[u] = true;
    bool dsp = (u < S.size());
    comp.dsp += dsp; comp.ppp += (1-dsp);
    comp.costo += (dsp ? S[u] : T[u - S.size()]);
    for(int v : G[u]) if(not marked[v]) dfs_getter(G,v,S,T,marked, comp);
}

void get_components(vector<vector<int>> &G, vector<int> &S, vector<int> &T, vector<cc> &CC){
    vector<bool> marked(G.size(),false);
    rep(i,G.size()) if(not marked[i]){
        cc last;
        CC.push_back(last);
        dfs_getter(G,i,S,T,marked,CC.back());
    }
}

int dp(vector<cc> &CC, int B,int id, int dir){
    if(B < 0) return -inf;
    if(id == CC.size()) return 0;
    if(M[B][id][dir] != -1) return M[B][id][dir];
    return M[B][id][dir] = max((dir ? CC[id].dsp : CC[id].ppp) + dp(CC,B-CC[id].costo,id+1,dir),
                               (dir ? CC[id].ppp : CC[id].dsp) + dp(CC,B,id+1,dir));
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(true){
        rep(i,10005) rep(j,205) rep(k,2) M[i][j][k] = -1;
        int D,P,R,B; if(!(cin >> D)) break; cin >> P >> R >> B;
        vector<int> S(D),T(P); rep(i,D) cin >> S[i]; rep(i,P) cin >> T[i];
        vector<vector<int>> G(D+P,vector<int>());
        rep(i,R){
            int x,y; cin >> x >> y; --y; --x;
            G[x].push_back(y + D);
            G[y+D].push_back(x);
        }
        vector<cc> CC; get_components(G,S,T,CC);
        cout << dp(CC,B,0,0) << " " << dp(CC,B,0,1) << endl;
    }
return 0;}
