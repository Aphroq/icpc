/*
    title:  原点N ,目标点K , 3种操作: x+1 ,x-1 ,x*2 ;
            求最少操作次数 

    solution: 
            从K倒回来 dfs(N,K)

            K为偶数:  dfs(N,k/2)+1 
                    再考虑 N与 K/2的位置 , 直接k/2快 还是到了N的左边 在走回N
            K为奇数: min(dfs(N,k-1),dfs(N,k+1)) +1 ;

            特判N==0 ,对于N出发来说 , 它只能走N+1 
                    
                    或者说会造成无限递归 :
                    dfs(0,4)--> dfs(0 , 2)-->dfs( 0 ,1)

                    --> min( dfs(0,2) , dfs(0,1) )+1

                    dfs(0,2)无限递归

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
int cnt =0 , K ,N , ans;
char s[100][100];
int book[100];

int dfs( int x , int k )
{
    if(k<=x) return x-k;

    if(k%2==0)
    {
        if(k/2>x) 
            return dfs( x, k/2)+1;
        else if(k/2==x)
            return 1;
        else
            return  min ( dfs(x,k/2)+1 , k-x );
    } 
    else
        return ( min( dfs(x,k+1) ,dfs(x,k-1) ) +1 );
    
}

int main()
{
    while(cin>>N>>K){
        int flag=0;
        //if(N==0) flag=1;
        ans = 9999999;
      
        cout<<dfs(N+flag , K )+flag<<endl;
    }
}