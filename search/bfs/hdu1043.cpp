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
#define MAX 400000
#define AIM 46234
using namespace std;
map<int , int> mp ;
struct Node{
    int s[9]; //九格子状态
    int loc; //空位
    int status ; //hash值
    int fa;  //父亲
    char d;  //方向
}n[MAX],node,t;
struct pos{
    char c ;
    int from;
};
int cnt=0;
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int v[MAX];
int xx[4] = {0,0,1,-1} ,yy[4]={1,-1,0,0};
pos path[362885];
char dir[4] = { 'l','r','u','d'};  //反过来
void print( )
{

}
int cantor( int s[9])
{
    int sum=0;
    for(int i=0 ;i<9 ;i++)
    {
        int num=0 ;
        for(int j=i+1; j<9 ;j++)
            if(s[j]<s[i])
                num++;
        sum += num*fac[9-i-1];
    }

    return sum+1;
}
/*void count_path(Node end)
{
    int f = end.fa;
    int len = 1 ;
    path[cnt][len++].c = end.d;
    while(f)
    {
        path[cnt][len++].c = n[f].d;
        f = n[f].fa;
    }
    path[cnt][0].len = len;
    mp[end.status] = cnt;
    cnt++; 
    //printf("cp\n");
}*/
int bfs()
{
    memset(v,0,sizeof(v));
    Node next;
    int head , tail ;
    head= tail =0;
    t.status = cantor(t.s);
    path[t.status].from = -1;
    v[t.status] = 1;

    while(head<=tail)
    {
        /*if(n[head].status == AIM)
        {
             return 1;
        }*/
        //count_path(n[head]);
        //printf("cnt :%d  here1\n",cnt);
        int x=n[head].loc/3;
        int y=n[head].loc%3;

        for(int i=0 ;i<4 ;i++)
        {
            int tx =  x+xx[i];
            int ty =  y+yy[i];
            if(tx<0||ty<0||tx>2||ty>2)
                continue;
            
            next = n[head];
            next.loc = tx*3 +ty;
            next.s[n[head].loc] = next.s[next.loc]; 
            next.s[next.loc] = 0;
            next.fa = head ;
            next.d = dir[i];
            next.status = cantor(next.s);

            if(!v[next.status])
            {
                v[next.status] = 1;
                path[next.status].from = n[head].status;
                path[next.status].c = dir[i];
                n[++tail] = next;
            }
            
        }
        head++;
        //printf("bfs\n");
    }

    return 0;
}

int main()
{
    char ch[3];
    int cntt=0;
    for(int i=0 ; i<8 ;i++)
    {
        t.s[i] = i+1;
    }
    t.s[8] = 0;
    t.loc = 8 ;
    t.status = 46234 ;
    t.fa = -1;
    t.d = 'x';
    //cantor( t.s) ;
    bfs() ;
    //printf("ok\n");
    while(~scanf("%s",ch)){
    Node node;
    if(cntt)
        printf("\n");
    cnt++;
    if(!strcmp(ch,"x"))
            node.s[0] = 0 , node.loc = 0;
        else node.s[0] = ch[0] - '0';

    for(int i=1 ;i<9 ;i++)
    {
        scanf("%s",ch);
        if(!strcmp(ch,"x"))
            node.s[i] = 0 , node.loc = i;
        else node.s[i] = ch[0] - '0';
        /*printf("%d ",n[1].s[i]);
        if((i+1)%3==0)
            printf("\n");*/
    }
    node.status = cantor(node.s);
    if( v[node.status] )
    {
        //printf("end bfs\n");
        int ttt=0;
        int s = node.status;
        while(path[s].from!=-1)
        {
            printf("%c",path[s].c);
            s = path[s].from;
        }

    }
    else printf("unsolvable");
    }
    return 0;

}