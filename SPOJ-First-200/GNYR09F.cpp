#include<iostream>
 
using namespace std;
 
const int T = 100000;
const int EMPTY = -2;
 
int MEMO[1000][1000];
 
long long int F(int n, int k, int fib[T]);
long long int Fu(int n, int k, int fib[T]);
 
long long int F(int n, int k, int fib[T])
{
    if(n == 0 or n < k) return 0;
    if(k == 0) return fib[n+2];
    if(MEMO[n][k] != EMPTY)
    {
        return MEMO[n][k];
    }
    return  MEMO[n][k] = F(n-1,k,fib) + F(n-2,k,fib) + Fu(n-1,k-1,fib);
}
 
long long int Fu(int n, int k,int fib[T])
{
    if(n == 0 or n < k)return 0;
    if(k == 0) return fib[n];
    return F(n-2,k,fib) + Fu(n-1,k-1,fib);
}
 
int main()
 
{
    for(int i = 0; i < 1000; i++)
    {
        for(int j = 0; j < 1000; j++)
        {
            MEMO[i][j] = EMPTY;
        }
    }
    int fib[T];
    fib[0] = 0;
    fib[1] = 1;
    for(int k = 2; k < T; k++)
    {
        fib[k] = fib[k-1] + fib[k-2];
    }
    int T; cin >> T;
 
    while( T --> 0)
    {
        int a, b, c; cin >> a >> b >> c;
        cout << a << " " << F(b,c,fib) << endl;
    }
    return 0;
}
 