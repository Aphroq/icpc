/*
    title:  放棋子, '#'可以放 , '.'不能放
            棋子不能在同行或同列 , 总共有K个 
            求摆放方法
 

    solution: 
            深搜 , 注意考虑不放的情况 
    
    date : 2019.3.5
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
int cnt =0 , K ,D;
char s[100][100];
int book[100];
void dfs( int d , int k)
{
     
    if( k==0 )
    {
        cnt++ ; return ;
    } 
    
    if( d >=D ) return ;//注意出口的顺序 
                        //因为 d,k也许是同时变化的 , 虽然当变化之后的k刚好满足答案, 
                        //变化后的d不满足答案 , 但这是合理的

    int i;
    for(i=0 ;i<D ;i++)
    {
        if(s[d][i]=='#')
        {   if(!book[i])
            {
                book[i] = 1 ;
                dfs(d+1 , k-1 );
                book[i]  = 0;
                // dfs(d+1 , k );
                //为什么不在这里dfs: '不选这个' 呢?
                //其实,当for循环时,表示i选,且i之前的都不选
            }
        }
    }
    dfs(d+1 , k );  //都不选
    
}
int main()
{
    int i ,j , n;
    while(~scanf("%d%d",&n,&K)&&(n+K!=-2))
    {
        memset(book , 0 , sizeof(book));
        cnt = 0 ; D = n;
        for(i=0 ;i<n ;i++)
        for(j=0 ;j<n ;j++)
            cin>>s[i][j];
        
        dfs(0,K);
        cout<<cnt<<endl;

    } 
    return 0;
}