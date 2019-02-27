/*
    title: 
           求一个环中，非连续最长回文子序列的长度。

    
    solution: 
            首先它是环,常规dp求LPS会错解,比如下面的数列:    
            1 5 6 9 6 2 4 2 

            正常答案是dp[1][n]=3, 但由于它是环, 正解dp[1][n]=6;
            从9或4(两段回文串的中心) 分别往左和右(可不连续),
            9: 往左 9 6 (环,跳到右边)2 4 2 6
               往右 9 6 2 4 2 6
            得到的序列是相同的,即环的回文子序列
            

            那么怎么解决环的问题 两种: 
            1:  倍增为链, 1 5 6 9 6 2 4 2 *** 1 5 6 9 6 2 4 2 
                数组s[1~n]变为s[1~2n] , 环的各种情况有n种
                for(i=1 ;i<=n ;i++)
                    s[i]~s[i+n-1]

                照常区间dp,然后查找各种dp[i][i+n-1]中的最值
                但是 , 要注意
                1 5 6 9 6 
                上面的方法得到的答案为3: 6 9 6
                但正解是4:  5 6 9 6 (以5为起点)
                这个起点在环回文序列的外面,所以还要找(长度减一) dp[i][i+n-2]+1中的最值

                什么意思?
                1 5 6 9 6 1 5 6 9 6
                dp[3][6]是一个环回文序列,6 9 6 
                它把5排出来了,作为起点,变为 5 6 9 6 长度为4 (dp[i][i+n-2]+1)   
                而dp[3][7]只有6 9 6 
                
            2:  不倍增,拆为两部分,对于数据 2 1 1 2 1 3可以看成 
                回文环 2 1 1 2 和 回文环 1or3 组成的
                两个回文环放一起 还是回文环

            文尾注释里的是第一种方法
            

    date : 2019.2.22
*/
// 

#include<bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int s[1005];
int path[105][105],dp[1005][1005];

int main()
{
    int i,j,k,m,n,len;
    while(cin>>n&&n){
    for(i=1 ;i<=n ;i++)
        cin>>s[i],
        dp[i][i]=1;     //基础值,根据dp[i][j]的意义来

    for(len=1 ;len<n ;len++)
    {
        for(i=1; i<=n-len ; i++)
        {
            int j = i+len;
            if(s[i]==s[j]) 
                    dp[i][j]=dp[i+1][j-1]+2;

            else dp[i][j]=dp[i+1][j-1]; //上面虽然不满足,还是要给dp[i][j]
                                            //赋值的,因为下面用它自己比较
            dp[i][j] = max(dp[i][j],max(dp[i+1][j],dp[i][j-1]));

        }
    }
    int ans =0;
    for(i=1 ;i<=n;i++)
        ans = max(ans , dp[1][i]+dp[i+1][n] ); 
    
    cout<<ans<<endl;
    }

}

/*
    for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			a[n + i] = a[i];
		}
 
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= 2 * n; i++)
			dp[i][i] = 1;
 
		for (int len = 1; len < 2 * n; len++) {
			for (int i = 1; i + len <= 2 * n; i++) {
				int j = i + len;
				dp[i][j] = max(dp[i + 1][j], max(dp[i][j - 1], (a[i] == a[j] ? dp[i + 1][j - 1] + 2 : 0)));
			}
		}
 
		int ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, dp[i][i + n - 1]);
		for (int i = 1; i <= n; i++)
			ans = max(ans, dp[i][i + n - 2] + 1);
		printf("%d\n", ans);
	}

*/