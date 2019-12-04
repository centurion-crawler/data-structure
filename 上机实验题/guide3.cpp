#include<bits/stdc++.h>//一笔画
#define for(i,x,p) for(int i=x;i<=p;++i) 
#define maxn 100
using namespace std;
int gr[maxn][maxn];
int a[maxn]={0},tot=0,e=0,n;
void init()
{
	cin>>n;
    cout<<"please input the matrix:"<<endl;
	for(i,1,n)
	 for(j,1,n)
	  cin>>gr[i][j];
}
int draw(int v)
{
	int i,k=0;
	if (tot==e) return 1;
	for(i,1,n)
	{
		if (gr[v][i]==1)
		{
			k=1;
			gr[v][i]=0;
			gr[i][v]=0;
			e+=2;
			if (draw(i))
			{
				printf("%d->",i);
				return 1;
			}
			else 
			{
				gr[v][i]=1;
				gr[i][v]=1;
	            e-=2;
				k=0;		 
			 } 
		}
	}
	if (k==0) return 0;
}
int main()
{
	int k=0,v;
	init();
	for(i,1,n)
	 {
	  for (j,1,n)
	  if (gr[i][j]==1) a[i]++;
	  
	  tot+=a[i];
      if (a[i]%2==1)
	  {
	    k++;v=i;	
      }
     }
	 if (k>2) printf("No solution\n");
	 else 
	 {
	 	printf("%d->",v);
		 draw(v);//从v点开始一笔画
		printf("%d",v);
	 }
	 return 0;
 } 