/*
    title:  逃离三维迷宫

    solution: 
            bfs 

    date : 2019.3.6
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
int cnt =0 , K ,N , ans,sz,sy,sx;
struct pos
{
    int z,x,y,step;
    //pos( int z , int x, int y)
};

int book[50][50][50];
char s[50][50][50];
int zz[6]={0,0,0,0,1,-1} , xx[6]={0,0,1,-1,0,0} , yy[6]={1,-1,0,0,0,0} ;
int main()
{
    int Z,X,Y,i,j,k;
    while(cin>>Z>>X>>Y){
    queue<pos> q ;    
    if(Z+X+Y==0) return 0;
    for(i=1 ;i<=Z ; i++)
    for(j=1 ;j<=X ;j++)
    {   for(k=1 ;k<=Y ; k++)
        {
            cin>>s[i][j][k];
            if(s[i][j][k]=='S')
                sz = i ,sx=j ,sy=k;
        }
    }
    memset(book,0,sizeof(book));
    int flag=1;
    book[sz][sx][sy] = 1;
    pos head = { sz,sx,sy,0};
    //printf("%d %d %d %d\n",head.z,head.x,head.y ,head.step);

    q.push( head );
    while(!q.empty())
    {
        pos p = q.front(); q.pop();
        if(s[p.z][p.x][p.y]=='E')
        {
            printf("Escaped in %d minute(s).\n",p.step);flag=0;
            break;
        }
        for(k=0 ; k<6 ;k++)
        {
            for(i=0 ; i<6 ;i++)
                for(j=0 ;j<6 ;j++)
                {
                    int z = p.z+ zz[k] ;
                    int x = p.x+ xx[k] ;
                    int y = p.y+ yy[k] ;
                    int step = p.step+1;
                    if( book[z][x][y]||s[z][x][y]=='#'||z<1||z>Z || x<1||x>X||y<1||y>Y)
                        continue;
                    //printf("%d %d %d %d\n",p.z,p.x,p.y ,p.step);
                    pos p={z,x,y,step};
                    q.push(p);
                    book[z][x][y]=1;
                }
        }
    }
    if(flag)printf("Trapped!\n");
    }

}