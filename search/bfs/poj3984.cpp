/*
    title: 
            逃离迷宫 , 输出路径

    
    solution: 
            bfs 
            回溯 输出路径sad

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
struct pos
{
    int x,y,s;
    pos( int X , int Y , int S)
    { 
        x=X , y= Y , s=S;
    }
    pos(){}
};
pos path[100][100];
int s[100][100];
void print( int xx, int yy)
{
    if( path[xx][yy].x==-1 && path[xx][yy].y==-1)
        return ;
    print( path[xx][yy].x , path[xx][yy].y);
    printf("(%d, %d)\n",path[xx][yy].x , path[xx][yy].y);
    //return;
}

int vis[100][100];
int xx[4]={0,0,1,-1} , yy[4]={1,-1,0,0};
int main()
{
    int i,j,k;
    int flag=1;
    for(i=0 ;i<5 ;i++)
    for(j=0 ;j<5 ;j++)
        cin>>s[i][j];
    queue<pos> q;
    pos headd(0,0,0);
    q.push(headd);
    vis[0][0] = 1;
    path[0][0] = { -1,-1 , 0};
    while(!q.empty())
    {
        pos node = q.front() ; q.pop();
        if(node.x==4 && node.y ==4)
        {
            //printf("%d\n",node.s);
            flag=0;
            break;
        }
        for(i=0 ;i<4 ;i++)
        {
            int x= node.x+xx[i];
            int y = node.y + yy[i];
            int ss = node.s+1;

            if(x<0||y<0||x>4 ||y>4)
                continue;

            if(s[x][y]==0)
            if( !vis[x][y] )
            {
                
                //printf("x:%d\ny:%d\nnodex: %d\nnodey: %d\n\n",x,y,node.x,node.y);
                path[x][y] = { node.x , node.y ,ss };
                node = { x,y,ss};
                q.push(node);
                vis[x][y] =1;
            }
        } 
    }
    print(4,4);
    printf("(4, 4)\n");

}