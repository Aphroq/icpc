/*
    title: 有两个数组，求两个数组的最长公共子序列长度。
           两个数组中数都在1~n*n范围内，且数组内没有任意两个数相同。
    
    input: 多组数据; ( n , p ,q ); 接p+1个数,q+1个数, p,q< n*n ; 
    output: 如题

    solution: 常见的LCS时间复杂度为o(n*n)肯定行不通，
            考虑题目的特殊性，数的范围1~n*n，且任意两个数都不相同。
            如果把第一个数组对应成1,2,3,4...p+1。把第二个数组也对应起来，
            实际上问题就转化为了求第二个数组的LIS（可以用o(nlgn)的算法求解。问题就得到了解决。

    date : 2019.2.21
*/


#include<bits/stdc++.h>
using namespace std;
int b[100005],dp[100005],s[100005];
int main()
{
    int t,k;
    cin>>t;
    for(k=1 ;k<=t ;k++){
    int i,a,n,p,q;
    cin>>n>>p>>q;
    p++,q++;
    memset(dp,0,sizeof(dp));
    memset(s,0,sizeof(s));
    for(i=1 ;i<=p;i++)
    {
        cin>>a;
        s[a] = i ;
    }

    for(i=1 ;i<=q ;i++)
    {
        cin>>a;
        b[i] = s[a];
    }

    //dp[1] = b[1];
    int len=0;   //因为前面的也许为0;
    
    for(i=1 ;i<=q ;i++)
    {
        if(!b[i]) continue;
        if(!len)  //找第一个符合的
        {
            dp[++len] = b[i];
            continue;
        }
        if(b[i]>dp[len])
            dp[++len] = b[i];
        else
        {
            int add= lower_bound(dp+1,dp+len+1,b[i])-dp;
            dp[add] = b[i];    
        }
        
    }
    printf("Case %d: %d\n",k , len);
    }
    return 0;


}