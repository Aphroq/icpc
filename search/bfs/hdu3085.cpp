#include<bits/stdc++.h>
using namespace std;
struct pos
{
    int x,y , t;
    pos(int X ,int Y ){ x=X ;y=Y ;};
    pos(){}
};

int zx1,zx2,zy1,zy2,a,b,mx,my,gx,gy;
int step;
bool vis[2][810][810];
char s[810][810];
int xx[4] = { 0,0,1,-1} ,yy[4] ={1,-1,0,0};
queue<pos> q[2];
int  bfs(int x)
{
    int cnt = q[x].size();
    while( cnt-- )
    {
        pos tmp = q[x].front() ; q[x].pop();
        if( vis[0][tmp.x][tmp.y] && vis[1][tmp.x][tmp.y] )
            return 1;
        int dis1  =  (abs(zx1-tmp.x) + abs(zy1-tmp.y) ) ;
        int dis2  = (abs(zx2-tmp.x) + abs(zy2-tmp.y) ) ;
        if( dis1<= 2*step || dis2<=2*step )
                continue;

        for( int j=0 ;j<4 ;j++)
        {
            int nx= tmp.x+xx[j] , ny=tmp.y+yy[j];
            if(nx<0||ny<0||nx>=a||ny>=b||s[nx][ny]=='X')
                continue;
            int dis1  =  (abs(zx1-nx) + abs(zy1-ny) ) ;
            int dis2  = (abs(zx2-nx) + abs(zy2-ny) ) ;
            if( dis1<= 2*step || dis2<=2*step )
                continue;
            if(!vis[x][nx][ny])
            {
                vis[x][nx][ny]=1;
                if( vis[0][nx][ny] && vis[1][nx][ny])
                	return 1;
                pos node(nx,ny);
                q[x].push(node);
                
            }
        }
    }
    return 0;
}


int solve()
{
    memset(vis,0,sizeof(vis));
	while(!q[0].empty()) q[0].pop();
	while(!q[1].empty()) q[1].pop();
    pos mnode( mx,my ) ; pos gnode( gx,gy );
    vis[0][mx][my] = 1 ; vis[1][gx][gy] =1;
    q[0].push(mnode) ; q[1].push(gnode);
    step =0;
    while( ( !q[0].empty()) || (!q[1].empty()) ) {
        step++;
        if( bfs(1) ) return step;
        if( bfs(0) ) return step;
        if( bfs(0) ) return step;
        if( bfs(0) ) return step;
        
    }
    return -1;
}
int main()
{

    int t;scanf("%d",&t);
    while(t--)
    {
        zx1=9999;
        scanf("%d%d",&a,&b);

        for(int i=0; i<a ;i++)
        {   
            scanf("%s",s[i]);
            for(int j=0 ; j<b ;j++)
            {   
    			if(s[i][j]=='M')
                    mx=i ,my= j;
             	else if(s[i][j]=='G')
                    gx=i ,gy =j;
             	else if(s[i][j]=='Z' )
                    if(zx1!=9999)
                        zx2=i ,zy2=j;
             		else zx1=i ,zy1=j;
            }
        }
        int ans = solve();
        printf( "%d\n",ans );
    }
    return 0;
}