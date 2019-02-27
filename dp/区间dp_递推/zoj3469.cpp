
/*
    title: 
            一个逗比送外卖，一群顾客逗比因为等的时间增长而不满值也增强，
            求不满值的最小值

    
    solution: 
            dp[i][j][k]表示i~j区间内外卖送完后的最小不满值，k=0表示停在i点，k=1表示停在j点
            然后得到四个状态转移

            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(a[i+1].x-a[i].x)*(tem+a[i].v));
            dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(a[j].x-a[i].x)*(tem+a[i].v));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(a[j].x-a[i].x)*(tem+a[j].v));
            dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(a[j].x-a[j-1].x)*(tem+a[j].v));


    date : 2019.2.27
*/





#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int s[1005];
int path[205][205][2],dp[1005][1005][2],t[205],di[205],sum[1005];
struct num
{
    int x,v;
}a[1005];
int cmp( num a, num b  )
{
    return a.x<b.x;
}
int main()
{
    int N ,n, X ,x,v, V ,i,j,k;
    while(cin>>n>>V>>X){
    
    for(i=1 ;i<=n ;i++)
        cin>>a[i].x>>a[i].v;
    
    a[++n].x = X;
    a[n].v = 0;
    sort(a+1,a+n+1,cmp);
    
    //cout<<"11\n";
    int pos;
    for(i=1 ;i<=n ;i++)
    {
        if(a[i].x == X)
        {    pos = i ;
            break;
        }
    } 

    for(i=1 ; i<=n ;i++)
        sum[i]  = sum[i-1] + a[i].v;
    
    for(i=1 ;i<=n ;i++)
    for(j=1 ;j<=n ;j++)
        dp[i][j][0] = dp[i][j][1] = INF ; //根据dp的定义,
    // cout<<"22\n";
     //cout<<"pos: "<<pos<<endl;
    dp[pos][pos][0] = dp[pos][pos][1] = 0 ;

    for(i=pos ; i>=1 ;i--)
    {
        // cout<<"i: "<<i<<endl;
        for(j=pos ; j<=n ;j++)
        {
           // cout<<"j: "<<j<<endl;
            if(i==j ) continue;
            int cost = sum[i-1]+sum[n]-sum[j];
            dp[i][j][0] = min( dp[i][j][0] , dp[i+1][j][0] + (cost+a[i].v)*(a[i+1].x-a[i].x));
            dp[i][j][0] = min( dp[i][j][0] , dp[i+1][j][1] + (cost+a[i].v)*( a[j].x-a[i].x) );                       
            dp[i][j][1] = min( dp[i][j][1] , dp[i][j-1][0] + (cost+a[j].v)*( a[j].x-a[i].x ) );              
            dp[i][j][1] = min( dp[i][j][1] , dp[i][j-1][1] + (cost+a[j].v)*( a[j].x-a[j-1].x));     
        }
    }    
    printf("%d\n",min(dp[1][n][0],dp[1][n][1])*V);
    }
}