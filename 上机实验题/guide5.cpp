#include<bits/stdc++.h>//Prim
#define INF 0x3f3f3f3f
#define maxn 100
using namespace std;
int n,m,st,tot;
int gr[maxn][maxn];
bool visp[maxn];
bool acte[maxn][maxn];
bool vise[maxn][maxn];
void init()
{
    int a,b,c;
    memset(visp,sizeof(visp),false);
    memset(acte,sizeof(acte),false);
    memset(vise,sizeof(vise),false);
    cin>>n>>m;
    for (int i=0;i<maxn;i++)
     for (int j=0;j<maxn;j++)
        gr[i][j]=INF;
    cout<<"please input the (v,w) and value:"<<endl;
    for (int i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        gr[a][b]=c;
        gr[b][a]=c;
    }
    cout<<"please input the start point:"<<endl;
    cin>>st;
    visp[st]=true;
    for (int i=1;i<=n;i++)
        if (visp[i]==false&&gr[st][i]!=INF)  acte[st][i]=true;
    tot=1;
}
void merge()
{
    while (tot<n)
    {
        int l=INF,p,v,w;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
            if (gr[i][j]!=INF&& acte[i][j] && !(visp[i]&&visp[j]))
             if (l>gr[i][j]) 
                { if (visp[i]&&!visp[j]) {p=j;l=gr[i][j];v=i;w=j;} if (!visp[i]&&visp[j]) {p=i;l=gr[i][j];v=i;w=j;}}
        visp[p]=true;
        cout<<p;
        vise[v][w]=true;
        tot++;
        for (int i=1;i<=n;i++)
            if (visp[i]==false&&gr[p][i]!=INF) acte[p][i]=true;
    }
}
int main()
{
    init();
    int ans=0;
    merge();
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (vise[i][j]) 
            {
                cout<<i<<'-'<<j<<endl;
                ans+=gr[i][j];
            }
    cout<<"total value:"<<ans;
    return 0;
}