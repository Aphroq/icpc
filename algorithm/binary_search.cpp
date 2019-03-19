#include<bits/stdc++.h>
using namespace std;
int s[10] = {10,21,32,41,50,68,77,801,994,1035};
int n=10;
int binary_search(int x)
{
    int l,r,m;
    l=0; r=n-1;   
    while(l<=r)
    {
        m = l+(r-l)/2;   
        if(x==s[m])
            return m;
        else if(x>s[m])
            l = m+1;
        else
            r = m-1;
    }
    return -1;
}

int main()
{
    int x ;
    printf("输入要查找的值: ");
    while(cin>>x){

    if( (x=binary_search(x))!=-1)
        printf("该值的下标为: %d\n",x+1);
    else 
        printf("未找到该值\n");
    
    printf("输入要查找的值: ");
    }
}