/*
    title: 
            两人烧草(可在同一点出发), 求烧完草的最短花费时间
            '#'草 ,'.'地  只能从草出发  
            火上下左右蔓延

    
    solution: 
            枚举两个点进队首 , 找bfs后最小值

            理解bfs 最后一层的含义 (满足最优)

            有dfs的写法, 在dfs文件夹图片
           
    date : 2019.3.9
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
using namespace std;
int m,n;
struct pos
{
    int x,y,s;
    pos(int X , int Y ,int S)
    { x= X ; y=Y ; s= S ;};
    pos(){}
};
int xx[4]={0,0,1,-1} , yy[4]={1,-1,0,0};
int vis[15][15] , k;
char s[15][15];
// 枚举两点, 作队首
int ans=9999999,tmp=0;
int judge()
{
    int i,j;
    for(i=1 ;i<=m ;i++)
    for(j=1 ;j<=n ;j++)
        if( !vis[i][j] && s[i][j]=='#') 
            return 0;
    return 1;
}
void bfs( int sx , int sy , int sxx, int syy)
{
    queue<pos> q;
    int zz,z;
    for(zz=0 ;zz<=14 ; zz++)
    for(z=0 ; z<=14 ;z++)
        vis[zz][z]=0;
    pos head1 (sx,sy,0) , head2(sxx,syy,0);
    vis[sx][sy]=1 , vis[sxx][syy]=1;
    q.push(head1) , q.push(head2);

    while(!q.empty())
    {
        pos node = q.front() ; q.pop();
        //tmp = max( node.s , tmp ) ;
        tmp = node.s;
        //printf("tmp: %d\n",node.s);
        int i;
        for(i=0 ;i<4 ;i++)
        {
            int x= node.x+xx[i] ;
            int y = node.y+yy[i];
            int step = node.s+1;

            if(x<1||y<1||x>m||y>n)
                continue;
            // bfs能不能直接改地图
            if(s[x][y]=='#')
            {
                if(!vis[x][y])
                {
                    //printf("ndoe.s: %d\n",step);
                    pos node (x,y,step);
                    q.push(node);
                    vis[x][y]=1;
                    //s[x][y]='.';
                }
            }
        }
    }
    //return ans;

}
int main()
{
    int casee,i,j,h,p;
    cin>>casee;
    for(k=1 ;k<=casee ;k++)
    {
        cin>>m>>n;
        for(i=1 ;i<=m ;i++)
        for(j=1 ;j<=n ;j++)
            cin>>s[i][j];
        int ff=1;
        ans=9999999;
        for(i=1 ;i<=m ;i++)
        for(j=1 ;j<=n ;j++)
        {
            for(h=1 ;h<=m ;h++)
            for(p=1 ;p<=n ;p++)
            {
                //tmp=0;
                if(s[i][j]!='#' || s[h][p]!='#')
                    continue;
                bfs(i,j,h,p);
                if(judge())
                {
                    ff= 0;
                    ans = min(ans,tmp);
                }

            }
        }
        printf("Case %d: %d\n",k,ff?-1:ans);
    }
    return 0;
}