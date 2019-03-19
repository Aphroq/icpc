#include<bits/stdc++.h>
using namespace std;
int s[10] = {10,21,32,41,50,68,77,801,994,1035};
int n=10;
int ternary_search(int l, int r, int x)
{
    if(l <= r)
    {
        int m1 = l+(r-l)/3;
        int m2 = l+2*(r-l)/3;
        if(s[m1]==x)
            return m1;
        if(s[m2]==x)
            return m2;
        if(s[m1] > x)
            return ternary_search( l , m1-1, x);
        else if(s[m2] < x)
            return ternary_search( m2+1 , r ,x  );
        else 
            return ternary_search( m1+1 ,m2-1 , x);
        }
    return -1;
}
 
int main()
{
    int x;
    printf("输入要查找的值: ");
    while(cin>>x){

    if( (x=ternary_search(0,n-1,x))!=-1)
        printf("该值的下标为: %d\n",x+1);
    else 
        printf("未找到该值\n");
    
    printf("输入要查找的值: ");
    }
}