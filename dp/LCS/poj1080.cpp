/*
    title: 给定两个字符串(ATCG)用-补齐，
          不同的字符对（--无定义）会有不同权值，
          要求权值和最大
 
    solution: LCS , dp[i][j] ( 保证i与j是对齐的*)
            
            通过转移方程
            dp[i][j]= max {
                dp[i-1][j-1]+ 匹配[key][key] 
                

                dp[i-1][j] + 匹配[key]['-'];
                
                不想让i和j匹配,但又要保持1-i ,1-j 是对齐的
                所以用 dp[i-1][j] ( 这个值已经在前面求出, 即1~i-1有'-',来保证对齐) 
                那么,剩下的i , 与'-'配对


                dp[i][j-1] + 匹配['-'][key]

                同上
            }
            
    
    date : 2019.2.21
*/



#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int mx[5][5]={{5,-1,-2,-1,-3},
        {-1,5,-3,-2,-4},
        {-2,-3,5,-2,-2},
        {-1,-2,-2,5,-1},
        {-3,-4,-2,-1,0},
        };
map<char,int>mp;
char a[105],b[105];
int dp[105][105];
int main()
{
    mp['A']=0 , mp['C']=1 , mp['G']=2 ,mp['T']=3 ,mp['-']=4;
    int m,n,i,j,t,k;
    cin>>t;
    for(k=1;k<=t;k++){
    memset(dp,0,sizeof(dp));
    cin>>n;
    scanf("%s",a+1);
    cin>>m;
    scanf("%s",b+1);
    //printf("a: %s\nb: %s\n",a+1,b+1);
    for(i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+mx[mp[a[i]]][mp['-']];
    }
    for(j=1;j<=m;j++){
        dp[0][j]=dp[0][j-1]+mx[mp['-']][mp[b[j]]];
    }


    for(i=1 ;i<=n;i++)
        for(j=1 ;j<=m; j++)
        {
            dp[i][j] = dp[i-1][j-1] + mx[mp[a[i]]][mp[b[j]]];
            dp[i][j] = max( dp[i][j], dp[i][j-1]+mx[ mp['-'] ][ mp[b[j]] ] );
            dp[i][j] = max(dp[i][j],dp[i-1][j]+mx[mp[a[i]]][mp['-']]);

        }
    cout<<dp[n][m]<<endl;
    }
}
