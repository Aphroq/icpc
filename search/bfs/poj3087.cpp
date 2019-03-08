/*
    title:  
            已知两堆牌s1和s2的初始状态， 其牌数均为c，
            按给定规则能将他们相互交叉组合成一堆牌s12，再将s12的最底下的c块牌归为s1，
            最顶的c块牌归为s2，依此循环下去。
            现在输入s1和s2的初始状态 以及 预想的最终状态s12
            问s1 s2经过多少次洗牌之后，最终能达到状态s12，
            若永远不可能相同，则输出"-1"。

    solution: 
            模拟 , map判重

    date : 2019.3.7
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
int cnt =0 , K ,N ;
long long int ans;
int book[100];
int vis[10005];

char s1[205],s2[205],s[500],s12[500];
int main()
{
    int n,i,j,k,len,nn;
    cin>>n; nn= n;
    while(n--){
        map< string , bool > ma ;
        cin>>len;
        cin>>s1>>s2>>s;
        ma[s] =true;
        int step =0 , h=0;
        while(1){

            h =0;
            for(i=0 ; i<len ;i++)
            {
                s12[h++] = s2[i];
                s12[h++] = s1[i];
            }
            s12[h] = '\0';
            step++;
            if(!strcmp(s12,s))
            {
                printf("%d %d\n",nn-n ,step);
                break;
            }

            else if( ma[s12] && strcmp(s,s12))
            {
                printf("%d -1\n",nn-n );
                break;
            }

            ma[s12] = true;
            for(i=0 ; i<len ; i++)
                s1[i] = s12[i];
            s1[i] = '\0';

           for(k=0;i<2*len;i++,k++)
                s2[k]=s12[i];
            s2[i] = '\0';

        }        
    }
    return 0;
}