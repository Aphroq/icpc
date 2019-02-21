#include<bits/stdc++.h>
using namespace std;
char a[1005],b[1005];
int dp[1005][1005],mark[1005][1005];


int main()
{
    while(~scanf("%s%s",a+1,b+1))
    {
        int i,j;
        memset(dp,0,sizeof(dp));
        int lena= strlen(a+1) ,lenb=strlen(b+1);
        for(i=1 ;i<=lena ;i++)
        {
            for(j=1 ;j<=lenb; j++)
            {
                if(a[i]==b[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else 
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

            }
        }
        cout<<dp[lena][lenb]<<endl;
    }

}