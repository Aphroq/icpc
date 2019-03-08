/*
    title:  求n的倍数x , x只由0,1组成 
    solution: 
            dfs  
            注意Long long int ,  c<=19

    date : 2019.3.6
*/



#include<iostream>
#include<cmath>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<list>
#include<queue>
#include<ctime>
#include<bitset>
#define eps 1e-6
#define INF 0x3f3f3f3f
#define PI acos(-1.0)
#define ll __int64
#define LL long long
#define lson l,m,(rt<<1)
#define rson m+1,r,(rt<<1)|1
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
int cnt =0 , K ,N ;
long long int ans;
char s[100][100];
int book[100];
int flag=0;

void dfs( int n , long long int x , int c)
{
    
    if(flag) return ;
    if(x%n==0) { ans = x ;flag=1; return ;}
    if(c==19) return ;
    //printf("x: %lld  x<<1: %lld\n",x,x<<1);
   
    dfs( n , x*10 , c+1 ) ; 
    
    //printf("x: %lld  x<<1|1: %lld\n",x,x<<1|1);
    dfs( n , x*10+1 , c+1) ;

}
int main()
{
    int n;
    while(cin>>n && n){
    flag =0 ;
    dfs(n , 1 , 1);
    cout<<ans<<endl;
    }
    return 0;

}