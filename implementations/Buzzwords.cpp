#include<bits/stdc++.h>
#define intt long long int
using namespace std;


const intt X = 33; //127 para alfabetos gigantes
const int N = 1001; //largo máximo del string
vector<intt> x(N + 1, 1);
void precalculo_rh() {
    for (int i = 1; i <= N; ++i)
        x[i] = x[i - 1]*X;
}
int charn(int c) {
    return c - 'a' + 1; //o lo que sea, depende de alfabeto (bug +1 arreglado)
}

//hashs da el hash de un substring dados los hash de los sufijos
intt hashs(vector<intt>& h, int n, int start, int len) {

    if (start + len == n) //hash de un sufijo
        return h[start];

    return h[start] - h[start + len]*x[len]; //hash de un substring normal
}

int main() {
    precalculo_rh();
    while(1){

        string str;
        getline(cin,str);
        if(str == "0") break;
        string rstr = "";
        for(int  i = 0; i < (int)str.size(); ++i){
            if(str[i] != ' ')
                rstr += str[i];
        }

        int n = rstr.size();
        vector<intt> h(n);
        h[n - 1] = charn(rstr[n - 1]);
        for (int i = n - 2; i >= 0; --i)
            h[i] = h[i + 1]*X + charn(rstr[i]);
        vector<map<intt,int> > V(n);
        for(int i = 1; i <= n; ++i){
            map<intt,int> M;
            for(int j = 0; j < n; ++j)
                if(i + j <= n){
                    intt H = hashs(h,n,j,i);
                    if(!M.count(H))
                    M[H] = 1;
                    else{
                        M[H] += 1;
                    }
                }
            V[i-1] = M;
            }
        for(int i = 0; i < n; ++i){
            map<intt,int> M = V[i];
            int maxFrec = -1;
            for(map<intt,int>::iterator it = M.begin(); it != M.end(); ++it){
                maxFrec = max(maxFrec,it -> second);
            }
            cout << maxFrec << endl;
            if(maxFrec == 1)
                break;
        }
    }
    return 0;
}
