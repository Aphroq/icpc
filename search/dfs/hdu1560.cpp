#include<bits/stdc++.h>
using namespace std; 
char c[4] = {'A','C','G','T'};
struct str
{
    string s;
    int len;
}a[15];

int pos[15] , depth , n ;
int get()
{
    int maxx= 0;
    for(int i=0 ;i<n ;i++)
    {
        maxx = max( maxx , a[i].len-pos[i]);
    }
    return maxx;
}
int dfs( int step )
{
    if(step+get()>depth) return 0;
    if(!get()) return 1;
    int temp[15];
    for(int i=0 ;i<n;i++)
        temp[i] = pos[i];
    for( int i=0 ; i<4 ;i++)
    {
        int flag =0;
        for( int j=0 ; j<n ;j++)
        {
            if(a[j].s[pos[j]] == c[i])
            {
                flag =1;
                pos[j]++;
            }
        }
        if(flag) 
        {
            if( dfs(step+1) )
                return 1;
            for( int i=0 ; i<n ;i++)
                pos[i] = temp[i];
        }
    }
    return 0;
    
}
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        cin>>n ;
        int maxx =0 ;
        depth =0;
        for(int i=0 ;i<n ;i++)
        {
            cin>>a[i].s;
            a[i].len = a[i].s.length();
            maxx = max( maxx , a[i].len);
            pos[i] = 0;

        }
        depth = maxx;
        while(1)
        {
            if(dfs(0)) break;
            depth++;
        }
        cout<<depth<<endl;

    }
    return 0;


}