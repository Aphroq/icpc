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
#define MAX 1000100
using namespace std;
int q[MAX] , q2[MAX] , a[MAX];
int n,k;
void getmin()
{
    int head, tail ; head = tail= 0;
    int i;
    for(i=1 ;i<k ;i++)
    {
        while(head<=tail && a[q[tail]]>= a[i]) tail--;
        q[++tail] = i;
    }

    for(i=k ;i<=n ;i++)
    {
        while(head<=tail && a[q[tail]]>= a[i]) tail--;
        q[++tail] = i;

        while(q[head]<= i-k) head++;
        printf("%d ",a[q[head]]);
    }
    printf("\n");
}

void getmax()
{
    int head, tail ; head = tail=0;
    int i;
    for(i=1 ;i<k ;i++)
    {
        while(head<=tail && a[q2[tail]]<= a[i]) tail--;
        q2[++tail] = i;
    }
    for(i=k ;i<=n ;i++)
    {
        while(head<=tail && a[q2[tail]]<= a[i]) tail--;
        q2[++tail] = i;

        while(q2[head]<= i-k) head++;
        printf("%d ",a[q2[head]]);
    }
    printf("\n");
}


int main()
{
    int i,j,m;
    cin>>n>>k;
    //q[0] = 1e9 ; q2[0] = -(1e9);
    for(i=1 ; i<=n ;i++)
        scanf("%d",&a[i]);
    getmin();
    getmax();
    return 0;

}