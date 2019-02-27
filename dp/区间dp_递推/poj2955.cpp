/*
    title: 
            求最长非连续对称子序列 区间dp

    
    solution: 
            dp[i][j]表示 i~j中的 最长值 它是符合最优子结构的
            
            然后开小区间查找

    date : 2019.2.27
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

char s[202];
int dp[200][200];
int main()
{
    int i,j,k,m,n,len;
    while( (cin>>s+1) && s[1]!='e' ){

    memset(dp,0,sizeof(dp));
    int n = strlen(s+1);
    //cout<<"len: "<<n<<endl;
    for(len=1 ;len< n ; len++)
    {
        for(i=1; i<=n-len ; i++)
        {
            int j = i+len;
            
            
            //dp[i][j] = max(dp[i][j],dp[i][j-1]+dp[i+1][j]);
            // 这个转移方程是错的 , 因为非连续 ,那么子状态就不只是i~j-1 和i+1~j ;
            for(k=i ;k<=j ;k++)
            {
                dp[i][j] = max(dp[i][j],dp[i][k]+dp[k+1][j]);
            }
            

            if( (s[i]=='('&&s[j]==')') ||(s[i]=='['&&s[j]==']'))
                dp[i][j] = max( dp[i][j],dp[i+1][j-1]+2);
        }
    }
    cout<<dp[1][n]<<endl;
    }
}








