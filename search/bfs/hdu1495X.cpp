#include<bits/stdc++.h>
using namespace std;
struct pos
{
    int s , a , b ,step ;
    pos( int S ,int V ,int C ,int ss)
    {
        s=S ,a= V ;b=C ;step=ss;
    }
    pos(){}
};
int S,A,B;
int vis[200][200][200],flag=1;;
void bfs()
{
    memset(vis,0,sizeof(vis));
    flag=1;
    queue<pos> q;
    pos headd( S ,0,0 , 0 );
    vis[S][0][0] =1;
    q.push(headd);
    while(!q.empty())
    {
        pos node = q.front() ; q.pop();
        if( node.a==S/2 && node.b==S/2 )
        {
            printf("%d\n",node.step);flag=0;
            break;
        }

        // s->a and b->a
        if(node.a<A)
        {
            pos tmp;
            if(node.s >= A-node.a)
                tmp.a = A , tmp.s = node.s - (A-node.a);
            else 
                tmp.a = node.a+node.s , tmp.s = 0;
            tmp.step = node.step+1;
            tmp.b = node.b;
            if(!vis[tmp.s][tmp.a][tmp.b])
            {
                q.push(tmp);
                vis[tmp.s][tmp.a][tmp.b] = 1;
            } 

            if(node.b >= A-node.a)
                tmp.a = A , tmp.b = node.b - (A-node.a);
            else 
                tmp.a = node.a+node.b , tmp.b = 0;
            tmp.step = node.step+1;
            tmp.s = node.s;
            if(!vis[tmp.s][tmp.a][tmp.b])
            {
                q.push(tmp);
                vis[tmp.s][tmp.a][tmp.b] = 1;
            } 
        }

        // s->b and a->b
        if(node.b<B)
        {
            pos tmp;
            if(node.s >= B-node.b)
                tmp.b = B , tmp.s = node.s - (B-node.b);
            else 
                tmp.b = node.b+node.s , tmp.s = 0;
            tmp.step = node.step+1;
            tmp.a = node.a;
            if(!vis[tmp.s][tmp.a][tmp.b])
            {
                q.push(tmp);
                vis[tmp.s][tmp.a][tmp.b] = 1;
            } 

            if(node.a >= B-node.b)
                tmp.b = B , tmp.a = node.a - (B-node.b);
            else 
                tmp.b = node.b+node.a , tmp.a = 0;
            tmp.step = node.step+1;
            tmp.s = node.s;
            if(!vis[tmp.s][tmp.a][tmp.b])
            {
                q.push(tmp);
                vis[tmp.s][tmp.a][tmp.b] = 1;
            } 
        }

         // a->s and b->s
        if(node.s<S)
        {
            pos tmp;
            if(node.a >= S-node.s)
                tmp.s = S , tmp.a = node.a - (S-node.s);
            else 
                tmp.s = node.s+node.a , tmp.a = 0;
            tmp.step = node.step+1;
            tmp.b = node.b;
            if(!vis[tmp.s][tmp.a][tmp.b])
            {
                q.push(tmp);
                vis[tmp.s][tmp.a][tmp.b] = 1;
            } 

            if(node.b >= S-node.s)
                tmp.s = S , tmp.b = node.b - (S-node.s);
            else 
                tmp.s = node.s+node.b , tmp.b = 0;
            tmp.step = node.step+1;
            tmp.a = node.a;
            if(!vis[tmp.s][tmp.a][tmp.b])
            {
                q.push(tmp);
                vis[tmp.s][tmp.a][tmp.b] = 1;
            } 
        }
    }
    if(flag) printf("NO\n");


}

int main()
{
    while(cin>>S>>A>>B && S)
    {
        bfs( );
    }


}