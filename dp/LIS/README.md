1. 注意dp[1]的赋值情况,由dp的含义决定
   但不是所有时候都能一开始赋值,根据题意 如uva10635

2. 
    upper_bound 第一个> 最长不下降 (a[i]>=dp[len])
    lower_bound 第一个>= 最长上升 (a[i]>dp[len])
    a[1-n]
    xxxer_bound(a+1,a+n+1 , key) - a;
