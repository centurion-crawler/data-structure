#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int d[1000][1000],path[1000][1000];
int main()
{
    int i,j,k,m,n;
    int x,y,z;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            d[i][j]=INF;
            path[i][j]=j;
        }
    for(i=1;i<=m;i++)
    {
            scanf("%d%d%d",&x,&y,&z);
            d[x][y]=z;
            d[y][x]=z;
    }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) {
                if(d[i][k]+d[k][j]<d[i][j]) {
                    d[i][j]=d[i][k]+d[k][j];
                    path[i][j]=path[i][k];
                }
            }
    for(i=1;i<=n;i++)
        for(j=i+1;j<=n;j++)
          if (i!=j) printf("%d->%d:%d\n",i,j,d[i][j]);
    int f, en;
    scanf("%d%d",&f,&en);
    while (f!=en)
    {
        printf("%d->",f);
        f=path[f][en];
    }
    printf("%d\n",en);
    return 0;
}
