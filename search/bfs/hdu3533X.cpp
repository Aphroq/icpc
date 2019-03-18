#include<bits/stdc++.h>
using namespace std;
#define MAX 105
int m,n,d,k;
int xx[5]={0,0,0,1,-1} , yy[5]={0,1,-1,0,0};
struct cus
{
    char c;
    int t, v,x, y;
    cus( char C ,int T, int V , int X ,int Y)
    {
        c =C ; t=T ; v=V ; x=X ;y= Y;
	}
    cus(){}
}pao[105];
struct pos
{
 
    int x, y,t;
    pos( int X ,int Y , int T)
    {
       x=X ;y= Y; t=T;
	}
    pos(){}
}node;

int cnt=1;
bool ss[1005][MAX][MAX],vis[1005][MAX][MAX];
int s[MAX][MAX];

void bfs()
{
    vis[0][0][0] = 1 ;
    queue<pos> q;
    pos node(0,0,0);
    q.push(node);
    
    while(!q.empty())
    {
        pos tmp = q.front(); q.pop();
        if(tmp.x==m && tmp.y==n)
        {
            printf("%d\n",tmp.t);
            return ;
        }    
        for(int i=0 ;i<=4 ;i++)
        {
            int x = tmp.x + xx[i] ;
            int y = tmp.y + yy[i];
            if(x<0||y<0||x>m||y>n)
                continue;
            if(ss[tmp.t][x][y])
                continue;
            if(tmp.t>d)	continue;
            if(!vis[tmp.t][x][y])
            {
                pos tmp2(x,y,(tmp.t)+1);
                q.push(tmp2);
                vis[tmp.t][x][y]=1;
            }  
        }       
    }
    printf("Bad luck!\n");
}
void deal()
{
    for(int h=1 ; h<=k ; h++){
    if(pao[h].c=='W')
    {
        int stop=-1 ;
        int xx = pao[h].x ; int yy=pao[h].y;
        for(int y=yy-1 ; y>=0 ;y--)
        {
            if(s[xx][y]==1)
            {
                stop = y;
                break;
            }
        }
        for(int t =1 ; t<=d ;t+=pao[h].t)
        {
            int rx =xx ,ry;
            for( int j=1 ;j<=t ;j++)
            {   ry = yy - pao[h].v * j; 
                if( ry > stop )
                ss[t][rx][ry] = 1 ;
            }
        }
    }
    if(pao[h].c=='E')
    {
        int stop=n+1 ;
        int xx = pao[h].x ; int yy=pao[h].y;
        for(int y=yy+1 ; y<=n ;y++)
        {
            if(s[xx][y]==1)
            {
                stop = y;
                break;
            }
        }
        for(int t =1 ; t<=d ;t+=pao[h].t)
        {
            int rx =xx ,ry;
            for( int j=1 ;j<=t ;j++)
            {   ry = yy + pao[h].v * j; 
                if( ry < stop )
                ss[t][rx][ry] = 1 ;
            }
        }
    }
    if(pao[h].c=='S')
    {
        int stop = m+1 ;
        int xx = pao[h].x ; int yy=pao[h].y;
        for(int x=xx+1 ; x<=m ; x++ )
        {
            if(s[x][yy]==1)
            {
                stop = x;
                break;
            }
        }
        for(int t =1 ; t<=d ;t+=pao[h].t)
        {
           int rx  ,ry=yy;
            for( int j=1 ;j<=t ;j++)
            {   rx = xx + pao[h].v * j; 
                if( rx < stop )
                ss[t][rx][ry] = 1 ;
            }
        }
    }
    if(pao[h].c=='N')
    {
        int stop=-1 ;
        int xx = pao[h].x ; int yy=pao[h].y;
        for(int x=xx-1 ; x>=0 ;x--)
        {
            if(s[x][yy]==1)
            {
                stop = x;
                break;
            }
        }
        for(int t =1 ; t<=d ;t+=pao[h].t)
        {
           int rx  ,ry=yy;
            for( int j=1 ;j<=t ;j++)
            {   rx = xx - pao[h].v * j; 
                if( rx > stop )
                ss[t][rx][ry] = 1 ;
            }
        }
    }
 
    for(int i=0;i<=m ;i++)
    {   for(int j=0 ; j<=n ;j++)
            printf("%d ",ss[2][i][j]);
    	printf("\n");
	}

    }
}
int main()
{
    int i,j;

    while( cin>>m>>n>>k>>d)
    {
        //ss[1005][MAX][MAX],vis[1005][MAX][MAX],s[MAX][MAX]
        memset(ss,0,sizeof(ss));
        memset(s,0,sizeof(s));
        memset(vis,0,sizeof(vis));
        for(int i=1 ;i<=k ;i++)
    	{
        	cin>>pao[i].c>>pao[i].t>>pao[i].v>>pao[i].x>>pao[i].y;
        	s[pao[i].x][pao[i].y] = 1 ;
    	}
        deal();
  		bfs();
    }
    
}