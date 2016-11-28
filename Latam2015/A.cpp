#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i <(int)n; ++i)
#define repx(i,x,n) for(int i = x; i <(int)n; ++i)
using namespace std;

string hard_complete(string n, int id, vector<vector<int>> &D){
    if(id >= n.size()) return n;
    string ans ="";
    rep(i,id)ans += n[i];
    int R= n.size() - ans.size();
    rep(z,R){
        for(int k = 9; k>= 0; --k){
            if(D[k][id-1+z] < 2){
                ans += (k + '0');
                n[id+z] = (k + '0');
                D[n[0]-'0'][0] = 1;
                repx(i,1,n.size()) rep(l,10) {D[l][i] = D[l][i-1]; D[n[i]-'0'][i] = D[n[i]- '0'][i-1] + 1;}
                break;
            }
        }
    }

return ans;}

string complete_greedy(string n, int id, vector<vector<int>> &D ){
    bool change = false;
    string ans = "";
    for(int pr = n[id]- '0' - 1; pr >= 0; --pr){
        if(D[pr][id] < 2){
            // hacer cambio en D
            n[id] = pr + '0';
            rep(l,10) D[l][0] = 0; D[n[0]-'0'][0] = 1;
            repx(i,1,n.size()) rep(l,10) {D[l][i] = D[l][i-1]; D[n[i]-'0'][i] = D[n[i]- '0'][i-1] + 1;}
            ans = hard_complete(n,id +1, D);
            change = true;
            break;
        }
    }
    if(!change){
        ans = complete_greedy(n,id-1,D);
    }
    return ans;
}

int main(){
    while(true){
        string n; if(!(cin >> n)) break;
        vector<vector<int>> D(10,vector<int>(n.size(),0));
        D[n[0]-'0'][0] = 1;
        repx(i,1,n.size()) rep(l,10) {D[l][i] = D[l][i-1]; D[n[i]-'0'][i] = D[n[i]- '0'][i-1] + 1;}
        int fails = 0;
        rep(i,n.size()) rep(j,10) if(D[j][i] > 2){
            string ans = complete_greedy(n,i,D); fails = 1;
            if(ans[0] != '0') cout << ans[0]; repx(k,1,ans.size()) cout << ans[k]; cout << endl;
        } if(! fails) cout << n << endl;
    }
    return 0;
}
