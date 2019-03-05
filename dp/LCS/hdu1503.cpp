/*
    title: 将两个字符串结合起来，他们的公共子串只输出一次
 

    solution: 根据LCS的原理，将每个字符都进行标记，
            看两个字符串中对应的字符究竟处于什么状态
            然后输出，其标记为公共子串的字符只输出一次即可，

            输出路径: 通过回溯法带路, 在达到终点,返回的时候输出路径
    
    date : 2019.2.21
*/


#include<bits/stdc++.h>
using namespace std;
char a[1005],b[1005];
int dp[1005][1005],mark[1005][1005];

void print_lcs( int i , int j )
{
    if(!i&&!j)      //出口(返回条件a)
        return; 
    else
    {
        if(mark[i][j]==0)
        {
            print_lcs(i-1,j-1);
            printf("%c",a[i]);
        }
        else if(mark[i][j]==1)
        {
            print_lcs(i-1,j);
            printf("%c",a[i]); //之前没被选到的
        }
        else
        {
            print_lcs(i,j-1);
            printf("%c",b[j]); 
        }  
    }
}

int main()
{
    while(~scanf("%s%s",a+1,b+1))
    {
        int i,j;
        int lena= strlen(a+1) , lenb= strlen(b+1);
        //cout<<lena<<" "<<lenb<<endl;
        for(i=0 ;i<=lena ; i++)
            mark[i][0] = 1 ;//不能进dp[i][j-1]的口子, 不然j<0
        for(i=0 ;i<=lenb ;i++)
            mark[0][i] = -1;
        
        for(i=1 ;i<=lena ; i++)
        {
            for(j=1 ;j<=lenb ;j++)
            {
                if(a[i]==b[j])
                {
                    dp[i][j] = dp[i-1][j-1]+1,
                    mark[i][j] = 0;
                }
                else if(dp[i][j-1]>dp[i-1][j])
                {    dp[i][j] = dp[i][j-1],
                    mark[i][j] = -1;
                }
                else 
                {    dp[i][j] = dp[i-1][j],
                    mark[i][j] = 1;
                }
            }
        }
        print_lcs(lena,lenb);
        printf("\n");



    }
    return 0;
}