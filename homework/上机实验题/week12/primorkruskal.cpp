#include<bits/stdc++.h>
using namespace std;
const int maxn=50;
const int INF=0x3f3f3f3f;
struct node{int from,to,cost;}edge[maxn];
int par[maxn];
int gr[maxn][maxn];
bool visp[maxn];
bool acte[maxn][maxn];
bool vise[maxn][maxn];
int st,tot,n,m;
int find(int num)
{
    return par[num]==num?num:par[num]=find(par[num]);
}
int cmp(const void *a,const void *b)
{
    return(((node*)a)->cost-((node*)b)->cost);
}

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
void prim()
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
}
int main()
{
    cin>>n>>m;
    if (n*n>m*log(m))
    {
        cout<<"Use kruskal algorithm"<<endl;
        for(int i=0;i<=n;i++)
            par[i]=i;
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].cost);
        qsort(edge,m,sizeof(node),cmp);
        int cnt=0,res=0;
        for(int i=0;i<m;i++)
        {
            int sa=find(edge[i].from),sb=find(edge[i].to);
            if(sa==sb)
                continue;
            res+=edge[i].cost;
            par[sa]=sb;
            cnt++;
            if(cnt==n-1)
                break;
        }
        if(cnt>=n-1)
            printf("%d\n",res);
        else
            printf("?\n");
    }
    else {
        cout<<"Use prim algorithm"<<endl;
        prim();
    }
    return 0;
}
/*
input:
6 9
1 2 6
1 3 3
2 3 2
2 4 5
3 4 3
4 6 3
4 5 2
3 5 4
5 6 5
*/