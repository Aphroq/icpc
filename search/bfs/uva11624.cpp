/*
    title:  
           在迷宫内，J表示人，F表示火，火可能不止一处，但是人只有一个，
           火会向上下左右蔓延，蔓延速度和人移动速度一至（每次一格，但是可以同时向四个方向）
           问是否可以成功逃出迷宫，不能输出IMPOSSIBLE，能的画话输出最短步数。

    

    solution: 
            bfs  将火和人放进队列, 区分--扩展 , 
            
            扩展时直接改变地图 可省略vis数组

    date : 2019.3.7
*/



#include<bits/stdc++.h>
using namespace std;

int xx[4]={0,0,1,-1},yy[4] = {1,-1,0,0};
int visf[300][300] ,vism[300][300];
char s[1005][1005];
struct pos
{
    int x, y , fire, step;
    pos( int X, int Y, int Fire , int Step)
    {
        x=X ; y =Y ; fire = Fire ; step = Step;
    }
    pos(){}
};
int main()
{
    int i,j,k,n;
    cin>>n;
    pos node;
    while(n--){
        int flag=1;
        queue<pos> q;
        //memset(s,0,sizeof(s));
        int a,b,fx,fy,mx,my;
        cin>>a>>b;
        for(i=1 ;i<=a ;i++)
        for(j=1 ;j<=b; j++)
        {    
            cin>>s[i][j];
            if(s[i][j]=='J')
                mx=i ,my = j;
            if(s[i][j]=='F')
            {
                pos nodee(i,j,1,0) ; 
                q.push( nodee );
                s[i][j] = '#';  //这样就可以不用vis数组了
            }
        }
        node = { mx, my , 0 , 0};
        q.push(node);
        s[mx][my] = '#';
        while(!q.empty())
        {
            pos tmp = q.front(); q.pop();
            if(!tmp.fire)  //是人
            if( tmp.x==1 || tmp.x==a || tmp.y==1 || tmp.y==b)
            {
                printf("%d\n",tmp.step+1); flag=0;
                break;
            }
            if(tmp.fire)
            {
                int x , y,step;
                for(i=0 ;i<4 ;i++)
                {   
                    x= tmp.x+xx[i] ; 
                    y= tmp.y+yy[i] ;
                    step = tmp.step+1;
                    if( x<1||x>a||y<1||y>b)
                        continue;
                    if(s[x][y]=='#')
                        continue;
                    pos tmp(x,y,1 , step);
                    q.push(tmp);
                    s[x][y] = '#';
                }
            }
            else 
            {
                int x , y,step;
                for(i=0 ;i<4 ;i++)
                {   
                    x= tmp.x+xx[i] ; 
                    y= tmp.y+yy[i] ;
                    step = tmp.step+1;
                    if( x<0||y<0||x>a+1||y>b+1)
                        continue;
                    if(s[x][y]=='#')
                    {    continue;}
                    pos tmp(x,y,0,step);
                    q.push(tmp);
                    s[x][y]='#';
                }
            }
        } 
        if(flag) printf("IMPOSSIBLE\n");


    }




}