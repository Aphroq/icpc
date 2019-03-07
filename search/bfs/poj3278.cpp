/*
    title:  原点N ,目标点K , 3种操作: x+1 ,x-1 ,x*2 ;
            求最少操作次数 

    solution: 
            bfs
            
            注意一下, N<=K<=100000 , 但有  2*N 
            所以 book 要开[200000+];
    date : 2019.3.6
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
int cnt =0 , K ,N , ans;
char s[100][100];
int book[300008];
struct pos
{
    int x; int step;
};
int main()
{
    int N , K;
    while(cin>>N>>K){
    int i,j,k,flag=1;
    queue<pos> q;
    memset(book,0,sizeof(book));
    pos head = { N , 0};
    book[N] =1;
    q.push(head);
    while(!q.empty())
    {
        pos p= q.front() ; q.pop();
        if(p.x==K){ 
            printf("%d\n",p.step);flag=0;
            break;
        }
        int step = p.step+1 ,xx;

         xx=p.x+1;
        if( !book[xx] &&xx<=100000 && xx>=0 )
        {    pos pp = { xx ,step };
            q.push( pp );
            book[xx]=1;
        }

         xx=p.x-1;
        if( !book[xx] &&xx<=100000 && xx>=0 )
        {    pos pp = { xx ,step };
            q.push( pp );
            book[xx]=1;
        }

         xx=(p.x)*2;
        if( !book[xx] &&xx<=100000 && xx>=0 )
        {    pos pp = { xx ,step };
            q.push( pp );
            book[xx]=1;
        }
    } 
    }
}
