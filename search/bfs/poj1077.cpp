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

struct Node{
    int s[9];
    int loc;
    int status ;
    int fa;
    char d;
}n[MAX];
int len;
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };
int v[MAX];
int xx[4] = {0,0,1,-1} ,yy[4]={1,-1,0,0};
char path[MAX];
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
    len =0;
    path[len++] = end.d;
    while(f)
    {
        path[len++] = n[f].d;
        f = n[f].fa;
    }
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
        if(n[head].status == AIM)
        {
            
            count_path(n[head]);
            return 1;
        }

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
    for(int i=0 ; i<9 ;i++)
    {
        scanf("%s",ch);
        if(!strcmp(ch,"x"))
        {
            n[0].s[i]=0;
            n[0].loc = i;
        }
        else 
            n[0].s[i] = ch[0] -'0';
    }

    if(bfs())
    {
        //printf("end bfs\n");
        for( int i=len-1 ;i>=0 ;i--)
            printf("%c ",path[i]);
        printf("\n");
    }
    else printf("unsolvable\n");

    return 0;

}