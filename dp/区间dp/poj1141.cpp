
/*
    title: 
            给一个由[,],{,}组成的字符串序列，求增加最少的字符，
           使该序列能够匹配，并输出最后的方案。

    
    solution: 
            区间dp.dp[i][j]表示从i~j 所需的最少的字符使之能匹配，
            转移的话要么是头尾匹配直接加中间，要么分成两段。

            不过要输出到达路径，所以在用一个path[i][j]表示到达该路径时的选择，
            -1表示头尾，其他表示中间分开的位置。

    date : 2019.2.22
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
using namespace std;
const int INF = 1e8;
char s[105];
int path[105][105],dp[105][105];
void out_( int l , int r)
{
    if(l>r)
        return ;
    if(l==r)
    {
        if(s[l]=='('||s[l]==')')
            printf("()");
        else 
            printf("[]");
        return ;
    }

    if(path[l][r]==-1)
    {
        putchar(s[l]);
        out_(l+1,r-1);
        putchar(s[r]);
    }
    else 
    {
        out_(l,path[l][r]);
        out_(path[l][r]+1,r);

    }

}

int main()
{
    while(gets(s+1))
    {
        memset(dp,0,sizeof(dp));
        //printf("test\n");
        int i,j,k,h;
        int lens = strlen(s+1);

        for(i=1 ;i<=lens ;i++)      //最小区间不能忽略,是转移的基础;
            dp[i][i] =1;            //根据dp[i][j]的定义, i-j的区间,保证是匹配的,dp[i][j]就是此时的长度
                                    //一个字符时当然是1 : 再复制一个
        for(k=1 ;k<lens ;k++)
        {
            
            for(i=1 ; i<=lens-k ;i++ )
            {
                int j = i+k ;
                dp[i][j]=INF;   // 赋初值,因为要求最小,所以给MAX
                
                if((s[i]=='['&&s[j]==']')||(s[i]=='('&&s[j]==')')   )
                    if(dp[i][j]>dp[i+1][j-1])
                       dp[i][j] = dp[i+1][j-1] ,
                       path[i][j] = -1;
                    
                for(h=i ; h<j ;  h++)
                {
                    if(dp[i][j] > dp[i][h]+dp[h+1][j])
                        path[i][j] = h,
                        dp[i][j] = dp[i][h]+dp[h+1][j];

                }
            }
        }    
        out_(1,lens);
        printf("\n");
    }



}
