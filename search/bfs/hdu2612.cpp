/*
    title: 
            两人约好去同一家kfc , 求min( |A~kfc|+|B~kfc| ) 同一家kfc
            #不能走
    
    solution: 
            bfs 
            几个坑点:  不能提前相遇
                     有些kfc不能到达,最后求遍历时不能无脑相加

    date : 2019.3.7
*/


#include<bits/stdc++.h>
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
int vis[505][505];
char s[505][505];
int ans[505][505][2];

void bfs( int xs ,int ys , int p)
{
    queue<pos> q;
    memset(vis,0,sizeof(vis));
    pos headd(xs,ys,0);
    vis[xs][ys]=1;
    q.push(headd);
    while(!q.empty())
    {
        pos node = q.front() ; q.pop();
        if(s[node.x][node.y]=='@')
        {
            ans[node.x][node.y][p] = node.s;
        }
        int i;
        for(i=0 ;i<4 ;i++)
        {
            int x= node.x+xx[i];
            int y= node.y+yy[i];
            int ss= node.s+1;
            if(x<1||y<1||x>m||y>n)
                continue;

            if(p)       //不能提前遇到
                if(s[x][y]=='Y') continue;
            else if(s[x][y]=='M') continue;

            if(s[x][y]!='#')
            {
                if(!vis[x][y])
                {
                    pos node(x,y,ss);
                    q.push(node);
                    vis[x][y]=1;
                }
            }
        }
    }


}

int main()
{
    
    while(cin>>m>>n)
    {
        memset(ans,1,sizeof(ans)); //初始所有kfc都到不了
        int i,j,k,tx,ty,sx,sy;
        for(i=1 ;i<=m; i++)
        for(j=1 ;j<=n ;j++)
        {    cin>>s[i][j];
            if(s[i][j]=='Y')
                tx=i ,ty=j;
            if(s[i][j]=='M')
                sx=i ,sy=j;
        }

        bfs(tx,ty,0) ; bfs(sx,sy,1);
        int res = 99999999;
        for(i=1 ;i<=m; i++)
        for(j=1 ;j<=n ;j++)
        {
            if(s[i][j]=='@')
            {
                res = min ( res , ans[i][j][0]+ans[i][j][1]);
            }
        }
        cout<<res*11<<endl;

    }
}