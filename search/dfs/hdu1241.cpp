/*
    title: 求联通块

    
    solution: 
            dfs

    date : 2019.3.7
*/


#include<bits/stdc++.h>
using namespace std;
int m,n;
char s[200][200];
int xx[8]={0,0,1,-1,1,1,-1,-1},yy[8]={1,-1,0,0,1,-1,1,-1};
void dfs ( int x , int y)
{
    s[x][y] = '*';
    int i;
    for(i=0 ;i<8 ;i++)
    {    int nx = x+xx[i] , ny = y+yy[i];
         if(nx<1||ny<1||nx>m||ny>n)
            continue;
         if(s[nx][ny]=='@')
            dfs(nx,ny);
    }
}

int main()
{

    while(cin>>m>>n && (m+n))
    {
        int i,j,k,cnt=0;
        for(i=1 ;i<=m ;i++)
        for(j=1 ;j<=n ;j++)
            cin>>s[i][j];
        
        for(i=1 ;i<=m ;i++)
        for(j=1 ;j<=n ;j++)
        {
            if(s[i][j]=='@')
            {
                dfs(i,j);
                cnt++;
            }
        }
        cout<<cnt<<endl;

    }


}