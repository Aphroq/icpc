/*
    title:  给 a,b 满足 a,b都是四位素数
            从a到b可进行操作: 修改一位,且必须满足修改后仍为素数
            求最少操作次数
    solution: 
            bfs 
            注意千位不能为0 

    date : 2019.3.7
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
int cnt =0 , K ,N ;
long long int ans;
char s[100][100];
int book[100];
int vis[10005];
typedef class{
    public:
        int prime , step;
}num;

int prime( int x)
{
    if(x==1) return 0;
    if(x%2==0) return 0;
    int i,j,k;
    for(i=2 ; i*i<=x ; i++)
    {
        if(x%i==0) return 0;
    }
    return 1;

}
int main()
{
    num queue[1500];
    int n,i,j,k,a,b,head,tail;
    cin>>n;
    while(n--){
    int flag=1;
    cin>>a>>b;
    queue[head=tail=0].prime = a;
    queue[head].step = 0;
    vis[a] = 1;
    memset(vis,0,sizeof(vis));
    while(head<=tail)
    {
        num x = queue[head++];
        //printf("x: %d\nstep: %d\n",x.prime,x.step);
        if(x.prime==b){
            printf("%d\n",x.step); flag=0;
            break;
        }
        int x4 = x.prime%10 , x3=x.prime/10%10 , x2=x.prime/100%10 , x1=x.prime/1000%10;
        
        for(i=0 ; i<10 ;i++)
        {
            if(i==x4) continue;
            int xx=x1*1000+x2*100+x3*10+i ;
            if( prime(xx) && !vis[xx] )
            {
                num tmp = { xx, x.step+1};
                queue[++tail] = tmp;
                vis[xx]  = 1;
            }
        }

        for(i=0 ; i<10 ;i++)
        {
            if(i==x3) continue;
            int xx=x1*1000+x2*100+i*10+x4 ;
            if( prime(xx) && !vis[xx] )
            {
                num tmp = { xx, x.step+1};
                queue[++tail] = tmp;
                vis[xx]  = 1;
            }
        }

        for(i=0 ; i<10 ;i++)
        {
            if(i==x2) continue;
            int xx=x1*1000+i*100+x3*10+x4 ;
            if( prime(xx) && !vis[xx] )
            {
                num tmp = { xx, x.step+1};
                queue[++tail] = tmp;
                vis[xx]  = 1;
            }
        }

        for(i=1 ; i<10 ;i++)
        {
            if(i==x1) continue;
            int xx=i*1000+x2*100+x3*10+x4 ;
            if( prime(xx) && !vis[xx] )
            {
                num tmp = { xx, x.step+1};
                queue[++tail] = tmp;
                vis[xx]  = 1;
            }
        }

    }
    if(flag) printf("Impossible\n");
    
    
    
}


}
