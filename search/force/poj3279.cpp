/*
    title:  给定一个矩阵，要么黑要么白，
            求出按照规则将其翻转为全白最小翻转次数的方案，
            如有多种最小方案则输出字典序最小的方案

    solution: 
            枚举第一行 , 递推下面 , 最后判断末行 


    date : 2019.3.9
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
int m,n;
int s[30][30] , c[30][30] ,b[30][30];
int xx[5]={0,0,0,-1} ,yy[5]={1,-1,0,0};
int getcolor( int x , int y)   // 若操作偶数次 , 则没改变
{
    int res= s[x][y];
    for(int i=0 ;i<4; i++)
    {
        int fx = x+xx[i] , fy=y+yy[i];
        if(fx<1||fy<1||fx>m||fy>n)
            continue;
        res+=b[fx][fy];
    }
    return res%2 ;
}

int solve()
{
    int sum=0;
    int i,j;
    for(i=2 ;i<=m ; i++)
    {
        for(j=1 ;j<=n ;j++)
        {
            if( getcolor(i-1 , j)) b[i][j]=1;
        }
    }

    for(i=1 ;i<=n ;i++)
        if(getcolor(m,i)) return INF;  //1表示黑色
    
    for(i=1 ;i<=m ; i++)
        for(j=1 ;j<=n ;j++)
            sum+=b[i][j];
    return sum;
}

int main()
{
    int i,j;
    cin>>m>>n;
    for(i=1 ;i<=m ;i++)
    for(j=1 ;j<=n ;j++)
        cin>>s[i][j];
    int ans = INF ;
    for(i=0 ;i< 1<<n ; i++)
    {
        memset(b,0,sizeof(b));
        for(int j=1 ;j<=n ;j++)
            b[1][j]  = i>>(n-j) & 1;

        int t= solve();
        if(t<ans)
        {
            ans = t;
            memcpy(c,b,sizeof(b));
        }
    }
    if(ans==INF) printf("IMPOSSIBLE\n");
    else 
    {
        for(int i=1 ;i<=m ;i++)
        {
            for(j=1 ;j<=n ;j++)
                printf("%d ",c[i][j]);
            printf("\n");
        }
    }


}