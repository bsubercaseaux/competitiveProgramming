#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(int)n; ++i)
#define repx(i,x,n) for(int i = x; i <(int)n; ++i)
#define graph vector<vector<int>>
using namespace std;

class Hopcroft {
    graph g;
    vector<int> U, dist;
    int inf = 1e9;

    bool bfs(){
        queue<int> q;
        for(int  u : U) if(match[u] == nil){
            dist[u] = 0;
            q.push(u);
        }else dist[u] = inf;
        dist[nil] = inf;
        while(not q.empty()){
            int u  = q.front(); q.pop();
            if( u != nil) for(int v: g[u]) if (dist[match[v]] == inf){
                dist[match[v]] = dist[u] + 1;
                q.push(match[v]);
            }
        }
        return (dist[nil] != inf);
    }

    bool dfs(int u){
        if (u != nil){
            for(int v: g[u]) if (dist[match[v]] == dist[u]+1 and dfs(match[v])){
                match[v] = u;
                match[u] = v;
                return true;
            }
            dist[u] = inf;
            return false;
        }
        return true;
    }
public:
    vector<int> match;
    int nil, isSemiPerfect,matchSize = 0;
    Hopcroft(graph& gg,vector <int>& UU ){
        g = gg; U = UU; nil = g.size();
        match.assign(g.size() + 1,nil);
        dist.assign(g.size() + 1,inf);
        while(bfs()) for(int u : U) if(match[u] == nil and dfs(u))
            ++matchSize;
        isSemiPerfect = (matchSize == U.size());
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int n; if(!(cin >> n)) break; int q; cin >> q;
        bool Cero = true; vector<vector<bool>> contains(n, vector<bool>(n+1,false));
        rep(i,n) {
            int b; cin >> b; if(b == n) Cero = false; rep(j,b)  { int gen; cin >> gen; contains[i][gen] = true;}
        } rep(i,q){
            int b; cin >> b; if(b == 0) {cout << (Cero ? "Y" : "N") << endl; } else{
                graph g(n+b,vector<int>());
                vector<int> son(b); rep(j,b) cin >> son[j];
                rep(k,b) rep(l,n) {
                   if(contains[l][son[k]]){
                    g[k].push_back(l+b);

                   }
                } vector<int> Son(b); rep(r,b) Son[r] = r;
                Hopcroft HK(g,Son);
                cout << (HK.isSemiPerfect ? "Y" : "N") << endl;
            }
        }
    }
return 0;}
