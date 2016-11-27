#include<bits/stdc++.h>
#define repx(i,x,n) for(int i = x; i < (int)n; ++i)
#define rep(i,n) repx(i,0,n)
using namespace std;
typedef long long intt;

vector<intt> deg(1e5+5,0);


struct node {
    intt valueMax,valueMin; int idmax, idmin;
    node() {valueMax = INT_MIN; valueMin = INT_MAX; idmax = idmin = -1;}
    node(int x,int i) {valueMax = valueMin = x; idmax= idmin = i;}
    node(const node &a,
          const node &b) {
        if(a.valueMax > b.valueMax) {valueMax = a.valueMax; idmax = a.idmax;}
        else { valueMax = b.valueMax; idmax = b.idmax;}
        if(a.valueMin < b.valueMin) { valueMin = a.valueMin; idmin = a.idmin;}
        else { valueMin = b.valueMin; idmin = b.idmin;}
    }
};

template<class node> class ST {
    vector<node> t;
    int n;


public:
    ST(vector<node> &arr) {
        n = arr.size();
        t.resize(n*2);
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n-1; i > 0; --i)
            t[i] = node(t[i<<1], t[i<<1|1]);
    }


    // 0-indexed
    void set_point(int p, const node &value) {
        for (t[p += n] = value; p > 1; p >>= 1)
            t[p>>1] = node(t[p], t[p^1]);
    }

	void bajar_grado(int id){
		node lessdeg = query(id,id+1);
		lessdeg.valueMax--; lessdeg.valueMin--;
		this->set_point(id,lessdeg);
	}

    // inclusive exclusive, 0-indexed
    node query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l&1) ansl = node(ansl, t[l++]);
            if (r&1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
    
    void eliminar(int id){
		this->set_point(id,node());
	}
};

bool fails(intt x, int A, int B, int S){
	
	if(abs(x)  > 1e6) return false;
	if(x < A){
		 return true;
	}
	if((S - x - 1) < B){
		 return true;
	} 
	return false;
}

void solve(vector<vector<int> > &g, int A,int B){
    bool changes = true; int S = g.size();
    rep(i,S) deg[i] = g[i].size();
    vector<node> nodes(S); rep(i,S) nodes[i] = node(deg[i],i);
    ST<node> st(nodes);
    int n = S; 
    while(changes and S){
        changes = false;
        node a = st.query(0,n);
        vector<int> c({a.idmax,a.idmin});
    
        if(a.idmax == -1) break;
        rep(k,2){
			deg[c[k]]= st.query(c[k],c[k]+1).valueMax;
			
			if(fails(deg[c[k]],A,B,S)){
				st.eliminar(c[k]); S--;
				for(int v : g[c[k]] ) st.bajar_grado(v);

				changes = true;
			}
		}
    }
    cout << S << '\n';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

    int N,M,A,B; cin >> N >> M >> A >> B;
    vector<vector<int> > g(N,vector<int>());
    rep(i,M){
        int u,v; cin >> u >> v; --u; --v;
        g[u].push_back(v); g[v].push_back(u);
    }
    solve(g,A,B);

return 0;}
