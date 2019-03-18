#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n,m,a,b,c;
    cin>>n>>m;
    for( int i=1 ;i<=m ;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        tu[a-1][b-1] = tu[b-1][a-1] = min( c, tu[a-1][b-1]);
    }

    for(int i=0 ;i < three[n]   ;i++)
    {
        bool flag = 1;
        for( int j= 0 ; j<n ;j++   )
        {
            if(digit[i][j]==0) flag=0; //

            if(dp[i][j]!=INF)
                for(int k=0 ; k<n ;k++)
                {
                    if(tu[j][k]&& digit[i][k]!=2)
                    {
                        dp[j+three[k]][k] = min(dp[i][j]+tu[j][j] , dp[j+three[k]][k] );
                    }
                }
        }
        if(flag)
            for(int j=0 ;j<n ;j++)
                ans = min( ans ,dp[i][j]);
    }


}