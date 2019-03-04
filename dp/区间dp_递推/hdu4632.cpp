#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
const int mod = 10007;
char s[1005];
int path[205][205][2];
long long dp[1005][1005];
int t[205],di[205],sum[1005];

int main(){
    int casee=0,t;
    cin>>t;
    while(t--)
    {
        scanf("%s",s+1);
        int i,j,k,len;
        int n = strlen(s+1);
        for(i=1 ;i<=n; i++)
            dp[i][i] = 1;   // 不止单字符是回文的 , XX 也是 , 少了它不能递推所有
        for( i=1 ;i<=n ;i++)
        {
            if(i!=n)
            if(s[i]==s[i+1])
                dp[i][i+1] = 3 ; 
            else    
                dp[i][i+1] = 2 ; // 若XY ,看成X 和 Y ,两个回文串
        }
        for(len = 2 ; len<n ;len++)  // 因为基础里有两个长度的了
        {
            for(i=1;i<=n-len ;i++)
            {
                int j  = i+len ;
                if(s[i] == s[j])
                    dp[i][j] = (dp[i+1][j]+dp[i][j-1]+1) %mod ; //   
                // 为什么这里不用算容斥 
                // 因为当s[i]==s[j]时,dp[i+1][j-1]要作为回文子序列存在,是解的一部分


                else dp[i][j] = (dp[i+1][j]+ dp[i][j-1] - dp[i+1][j-1] + mod)%mod;
                //
                
            }
        }
        printf("Case %d: %d\n",++casee,dp[1][n]%mod);


    }






}