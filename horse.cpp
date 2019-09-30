#include <bits/stdc++.h>
#define N 8
#define INF 999999999
using namespace std;

int dx[9]={0,2,2,-2,-2,1,1,-1,-1};
int dy[9]={0,-1,1,1,-1,-2,2,-2,2};
bool MAP[N+1][N+1];
int sign[N+1][N+1]={0};
void print()
{
    for (int i=1;i<=N;i++)
        {
            for (int j=1;j<=N;j++)
                cout<<sign[i][j]<<" ";
        cout<<endl;
        }
}
bool judge(int i,int j)
{
    if (!MAP[i][j]&&i>0&&i<N+1&&j>0&&j<N+1)
    return true;
    else return false;
}
int judgepath(int x_,int y_)
{
	int c;
	int tag=0;
	for (c = 0; c < 8; c++)
	{
		if (judge(x_ + dx[c], y_ + dy[c]))
		{
			tag++;
		}
	}
	return tag;
}
void walk(int x,int y,int cnt)
{
    cout<<x<<" "<<y<<endl;
    if (cnt==N*N)
        {
            print();
            exit(0);
        }
    int MIN=INF,rec=-1,rec2=0;
    for (int i=1;i<=8;i++)
    {
        if (!judge(x+dx[i],y+dy[i]))
              continue;
        int path=judgepath(x+dx[i],y+dy[i]);  
            if (MIN>path)
            {
                MIN=path;
                if (rec) rec2=rec;
                rec=i;
            }
    }
    if (MIN!=INF)
    {
                sign[x+dx[rec]][y+dy[rec]]=cnt+1;
                MAP[x+dx[rec]][y+dy[rec]]=true;
                walk(x+dx[rec],y+dy[rec],cnt+1);
                MAP[x+dx[rec]][y+dy[rec]]=false;
                sign[x+dx[rec]][y+dy[rec]]=0;
    } 
        return;
}
void init()
{
    int x0,y0;
    memset(MAP,sizeof(MAP),false);
    cin>>x0>>y0;
    sign[x0][y0]=1;
    MAP[x0][y0]=true;
    walk(x0,y0,1);
}
int main()
{
    init();
    return 0;
}