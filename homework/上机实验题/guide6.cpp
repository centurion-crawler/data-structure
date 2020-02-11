#include <bits/stdc++.h>//dijkstra关键点路径
#define INF 0x3f3f3f3f
using namespace std;
int map_[110][110];
bool visited[10010];
int dis[10010];

int n,m;
void dijstra(int u)
{
    int i,j;
    int start=u;
    memset(visited,false,sizeof(visited));
    visited[start]=true;
    memset(dis,INF,sizeof(dis));
    for (i=1;i<=n;++i)
    {
        dis[i]=min(dis[i],map_[start][i]);
    }
    for (i=1;i<=n-1;++i)
    {
        int minn=INF;
        for (j=1;j<=n;++j)
        if (!visited[j]&&minn>dis[j]) {minn=dis[j];start=j;}
        visited[start]=1;
        for (int j=1;j<=n;++j)
            dis[j]=min(dis[j],dis[start]+map_[start][j]);
    }
}
int main()
{
    int a,b,c;
    int i,st,en,im;
    cout<<"Please input the point number and edge number:"<<endl;
    cin>>n>>m;
    cout<<"input the (v,w) and the value of the edge:"<<endl;
    memset(map_,88,sizeof(map_));
    for (i=1;i<=m;++i)
        {
            cin>>a>>b>>c;
            map_[a][b]=c;
            map_[b][a]=c;
        }
    for (i=1;i<n;++i)
        map_[i][i]=0;
    cout<<"please input the start and target point:"<<endl;
    cin>>st>>en;    
    cout<<"please input the important point:"<<endl;
    cin>>im;
    dijstra(st);
    int d1=im,d2;
    cout<<st<<"-"<<im<<":"<<dis[im]<<endl;
    d1=dis[im];
    dijstra(im);
    cout<<im<<"-"<<en<<":"<<dis[en]<<endl;
    d2=dis[en];
    cout<<"total:"<<d1+d2;
    return 0;
}
