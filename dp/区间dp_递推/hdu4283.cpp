/*
    title: 
            一个队列，每个人有一个愤怒值D，如果他是第K个上场，不开心指数就为(K-1)*D。
            但是边上有一个小黑屋（其实就是个堆栈），可以一定程度上调整上场程序
    
    solution: 
            dp[i][j]表示从第i个人到第j个人这段区间的最小花费

            这里注意下


    date : 2019.2.27
*/




#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int s[1005];
int path[205][205][2],dp[1005][1005],t[205],di[205],sum[1005];

int main()
{
    int t,i,j,k,m,n,cas=0,len;
    cin>>t;
    while(t--)
    {
        
        cin>>n;
        for(i=1 ;i<=n ;i++)
            cin>>s[i];
        for(i=1 ;i<=n ;i++)
            sum[i] = sum[i-1] + s[i];
        
        memset(dp,0,sizeof(dp));
        for(i=1 ;i<=n ;i++)
            for(j=i+1 ;j<=n ;j++){
                dp[i][j] = INF ;
        }
        /* 为什么越界的(dp[big][small]) 是赋0
            当len==1时,会出现这种情况 , 这样能保证只添加自己的愤怒值

        */
        for(len=1 ;len<n ;len++)
        {
            for(i=1 ; i<=n-len ; i++)
            {
                int j=i+len;
                for(k=i;k<=j ;k++)
                dp[i][j] = min(dp[i][j], dp[i+1][k]+dp[k+1][j]+ s[i]*(k-i) + (k-i+1)*(sum[j]-sum[k]) ) ;
                
            }

        }
        printf("Case #%d: %d\n",++cas,dp[1][n]);


    }


}