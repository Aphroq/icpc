/*
    title: 给一个数字串(不超过80位),可以在数字之间添加逗号，分成几个数，
        要求最后形成一个严格递增的序列，且要求最后一个数尽可能的小，
        如果有多个满足要求，则使第一个数尽可能大，如果还有多个，则使第二个最大，
        如此类推。求最后的序列。

    
    solution: 好dp+思维。
            第一次从前往后dp,dp[i]表示包括第i位往前，满足题目要求能得到的最小长度。
            这样就可以求出，最后一个最小的满足的数了。

            求出最后一个最小的数后，从后往前dp,dp[i]表示从第i位开始往后，
            在满足题目要求的情况下，能得到的最大长度。这样就可以求出，按顺序依次最大的了。

            PS：多个变量一次不能确定的情况下，先确定一个，然后再确定另外一个。

    date : 2019.2.21
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
 
#define Maxn 90
char sa[Maxn];
int dp[Maxn];
 
bool isgreater(int i,int j,int m,int n) //判断从i~j的串是否大于从m~n的串
{
    while(sa[i]=='0'&&i<=j) //去掉前导0
        i++;
    while(sa[m]=='0'&&m<=n)//去掉前导0
        m++;
    if(i>j) //前者为0
        return false;
    if(m>n) //后者为0
        return true;
    int a=j-i+1,b=n-m+1; //长度，也就是位数
    if(a>b)
        return true;
    else if(a<b)
        return false;
    else
    {
        for(int k=i,p=m;k<=j;k++,p++) //位数相同，逐位比较
        {
            if(sa[k]>sa[p])
                return true;
            else if(sa[k]<sa[p])
                return false;
        }
    }
    return false; //等于的情况
}
int main()
{
    while(scanf("%s",sa+1)!=EOF)
    {
        int n=strlen(sa+1);
        if(n==1&&sa[1]=='0')
            break;
        dp[1]=1;//dp[i]表示从第i位往前共长度最小为dp[i]组成一个数字时的情况,
        for(int i=2;i<=n;i++)
        {
            dp[i]=i;
            for(int j=i-1;j>=1;j--)
            {
                if(isgreater(j+1,i,j-dp[j]+1,j))
                {
                    dp[i]=i-j; //求出满足题意的最小长度
                    break;
                }
            }
        }
 
        //然后从后往前，dp[i]表示在满足第一个条件的情况下，从i开始的最大长度
        int tt=n-dp[n]+1;
        dp[tt]=dp[n];
        for(int i=tt-1;i>=1;i--)
        {
            if(sa[i]=='0')
            {
                dp[i]=dp[i+1]+1;
                continue;
            }
            for(int j=tt;j>i;j--) //求出长度最大的
            {
                if(isgreater(j,j+dp[j]-1,i,j-1))
                {
                    dp[i]=j-i;
                    break;
                }
            }
 
        }
        for(int i=1;i<=dp[1];i++) //输出
            putchar(sa[i]);
        int pp=dp[1]+1;
        while(pp<=n)
        {
            putchar(',');
            for(int i=pp;i<pp+dp[pp];i++)
                printf("%c",sa[i]);
            pp=pp+dp[pp];
        }
        putchar('\n');
 
 
    }
   return 0;
}
 
