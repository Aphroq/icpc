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
}n[MAX];
struct pos{
    char c ;
    int len ;
};
int cnt=0;
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int v[MAX];
int xx[4] = {0,0,1,-1} ,yy[4]={1,-1,0,0};
pos path[362885][100];
char dir[4] = { 'r','l','d','u'};

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
void count_path(Node end)
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
}
int bfs()
{
    memset(v,0,sizeof(v));
    Node next;
    int head , tail ;
    head= tail =0;
    n[0].status = cantor(n[0].s);
    v[n[0].status] = 1;

    while(head<=tail)
    {
        /*if(n[head].status == AIM)
        {
             return 1;
        }*/
        count_path(n[head]);
        printf("cnt :%d  here1\n",cnt);
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
                if(next.status ==AIM)
                {
                    
                    count_path(next);
                    return 1;
                }
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
    for(int i=0 ; i<8 ;i++)
    {
        n[0].s[i] = i;
    }
    n[0].s[8] = 0;
    n[0].loc = 8 ;
    n[0].status = 46234 ;
    n[0].fa = -1;
    n[0].d = 'x';
    //cantor( n[0].s) ;
    bfs() ;
    printf("ok\n");
    for(int i=0 ;i<9 ;i++)
    {
        scanf("%s",ch);
        if(!strcmp(ch,"x"))
            n[1].s[i] = 0 , n[i].loc = i;
        else n[1].s[i] = ch[0] - '0';
        printf("%d ",n[1].s[i]);
        if((i+1)%3==0)
            printf("\n");
    }
    cantor(n[1].s);
    if( v[n[1].status] )
    {
        //printf("end bfs\n");
        int ttt=0;
        for( int i=0 ;i<9 ;i++)
        {
            ttt++;
            //int x= (n[1].s[i]) /3 ;
            //int y= (n[1].s[i]) %3 ;
            printf("%d ",n[1].s[i]);
            if(ttt%3==0) printf("\n");
        }

        int idx = mp[n[1].status];
        int len = path[idx][0].len;
        printf("len:%d\n",len);
        for( int i=1 ;i<len ;i++)
            printf("%c ",path[idx][i].c);
        printf("\n");
    }
    else printf("unsolvable\n");

    return 0;

}