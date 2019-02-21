/*
    title: 求最大_子串和
    Given a sequence a[1],a[2],a[3]......a[n], 
    your job is to calculate the max sum of a sub-sequence. 
    For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.

    date : 2019.2.21
*/

#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],dp[100005];
int main()
{
    int t,tt,cnt=0;
    cin>>t;
    tt=t;
    while(t--){
        cnt++;
        memset(dp,0,sizeof(dp));
        int n,i,j;
        cin>>n;
        for(i=1 ;i<=n ; i++)
            cin>>a[i];
        
        //dp[i]表示 到i截止的最优解_最大子串和(连续)
        dp[1]=a[1];
        int ans = dp[1];
        int start =1 ,end,fst=1,lst=1;
        for(i=1 ;i<=n ;i++){
            dp[i] = a[i] ; // 如果没有这句, 当dp[i-1]<0时,dp[i]不被赋值
            if(dp[i-1]<0)
                start = i;
            else
                dp[i] = max(dp[i-1]+a[i] , dp[i]);
                
            if(dp[i]>ans)
            {
                ans = dp[i];
                fst = start;
                lst = i;
            }
        }
        printf("Case %d:\n",cnt);
        cout<<ans<<" "<<fst<<" "<<lst<<"\n";
        if(cnt!=tt) printf("\n");
    }

}