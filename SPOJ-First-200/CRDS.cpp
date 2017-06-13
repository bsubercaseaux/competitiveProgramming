#include<iostream>
#define M
#define intt long long int
using namespace std;
 
 
int main()
{
intt A[1000007];
A[0] = 0;
A[1] = 2;
for(intt i = 2;i < 1000007; i++)
{A[i] = (A[i-1]%1000007 +((3*i)%1000007)  -1)%1000007 ;}
intt N; cin >> N;
for(intt j = 0; j < N; j++)
{ intt a; cin >> a; cout << (A[a]%1000007) << endl;}
 
return 0;}