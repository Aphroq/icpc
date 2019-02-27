/*
    title: 
           一排在一条献上的开关，要把所有开关全部按下的步骤，
           每移动一个单位距离需要一个单位时间，给出每个开关的位置，
           并且每个开关按下后经过一定的时间又会弹起来，求出步骤


    
    solution: 
            先贪心, 走端点 , 如果先走中间,必定会应两端点而 再经过中间

            dp[i][j][0]表示在区间i~j内先按左边端点能达到的最小的时间，
            dp[i][j][1]表示先按右端点能达到的最小时间。
            0和1 代表此状态它站在左还是右,即刚按下哪个点

            path[i][j][0] 此时站在0(左边), 前状态的位置即 它的值的意义
            若path[i][j][0] = 1  代表从j走到i,按下i

    date : 2019.2.26
*/



#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int s[1005];
int path[205][205][2],dp[205][205][205],t[205],di[205];

int main()
{
    int n;
    while(cin>>n){
    int i,j,k,m,len;
    
    for(i=1 ;i<= n ;i++)
        cin>>t[i];
    for(i=1 ;i<=n ;i++)
        cin>>di[i];
    memset(dp,0,sizeof(0));
    for(len=1 ;len<n ; len++)
    {
        for(i=1 ;i<=n-len  ; i++)
        {
            int j= i+len;

            if(dp[i+1][j][0] + di[i+1]-di[i] < dp[i+1][j][1]+di[j]-di[i] )
                dp[i][j][0] = dp[i+1][j][0] + di[i+1]-di[i] ,
                path[i][j][0] = 0; // 现在缺i ,从[i+1~j]左边来
            
            else 
                dp[i][j][0] = dp[i+1][j][1]+di[j]-di[i] ,
                path[i][j][0] = 1;   // 现在缺i ,从[i+1~j]右边来

            if(t[i]<=dp[i][j][0] || dp[i][j][0]>=INF)  //右边这个是判断 前两种状态是否都无效
                dp[i][j][0] = INF;  //此状态无效

                //第一个判断条件是由于 dp[i][j][x]的子结构 保证了之前的答案是最优的,
                //即没有弹起来的


            if(dp[i][j-1][1] + di[j]-di[j-1] < dp[i][j-1][0]+di[j]-di[i] )
                dp[i][j][1] = dp[i][j-1][1] + di[j]-di[j-1] ,
                path[i][j][1] = 1; // 现在缺j ,从[i~j-1]右边来
            
            else 
                dp[i][j][1] = dp[i][j-1][0]+di[j]-di[i] ,
                path[i][j][1] = 0; // 现在缺j ,从[i~j-1]左边来
            
            if(t[j]<=dp[i][j][1] || dp[i][j][1]>=INF)
                dp[i][j][1] = INF ;
            
        }
    }
    int l,r,va;
    if(dp[1][n][0]<INF)
    {
        printf("1 ") ;
        l=2 ; r=n;
        va = path[1][n][0] ;  //求前一个状态

    }
    else if(dp[1][n][1]<INF)
    {
        printf("%d ",n);
        l=1 ; r=n-1;
        va = path[1][n][1];
    }
    else 
        {
            printf("Mission Impossible\n");
            continue;
        }
    while(l<=r)
    {
        if(va==0)               
        {
            printf(" %d",l);
            va = path[l][r][0]; //此状态的前一个状态
            l++;                // 所以l++放在后面
        }
        else 
        {
            printf(" %d",r);
            va= path[l][r][1];
            r--;
        }
    }
    printf("\n");
    }
}







