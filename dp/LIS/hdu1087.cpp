/*
    title: 求最大_子序列和
    input: 多组数据,第一个数为N,后接N个数
    output: 如题

    solution: dp[i]表示以i为结尾的解 , 最后找max(dp[1~n]);

    date : 2019.2.21
*/


#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],dp[1005];
int main()
{
    
    int n,i,j;
    while(~scanf("%d",&n)&&n){
    
    memset(dp,0,sizeof(dp));
    for(i=1 ;i<=n ;i++)
        cin>>a[i];
    
    dp[1] = a[1] ;
    int ans = a[1];
    for(i=2 ;i<=n ;i++)
    {
        dp[i] = a[i] ; // "要给他最基本的值___"
        for(j=1 ;j<=i ;j++)
        {
           if(a[j]<a[i])
           {
                dp[i] = max(dp[j]+a[i] , dp[i]);
           }
        }
        ans = max ( ans , dp[i]);
    }
    cout<<ans<<endl;
    }

}