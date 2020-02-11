#include <stdio.h>
#define MAX 256 
typedef struct
{
	int x;
	int y;
	int value;
}Node;
typedef Node SNode;
bool Algo_5_19(int a[MAX][MAX], int row, int col, SNode p[MAX]);
void Min_row(int a[MAX][MAX], int col, int i, Node min[MAX]);
bool IsMax_col(int a[MAX][MAX], int row, Node v);
int main(int argc, char *argv[])
{
	SNode p[MAX];	
	int row,col
	int a[MAX][MAX] ；
	int i, j, k;
	cin>>row,col;
	for(i=0; i<row; i++)
	{
		for(j=0; j<col; j++)
			scanf("%3d ",&a[i][j]);
	}
	
	
	if(Algo_5_19(a, row, col, p))
	{
		printf("此矩阵中存在马鞍点...\n");
		for(k=1; k<=p[0].value; k++)
			printf("第 %d 行第 %d 列的马鞍点 %d\n", p[k].x, p[k].y, p[k].value);
	}
	else
		printf("此矩阵中不存在马鞍点...\n");
	
	printf("\n");
	
	return 0;
}
bool Algo_5_19(int a[MAX][MAX], int row, int col, SNode p[MAX])
{
	int i, k;
	Node min[MAX];
	
	p[0].value = 0;
	
	for(i=0; i<row; i++)
	{
		Min_row(a, col, i, min);
		for(k=1; k<=min[0].value; k++)
		{
			if(IsMax_col(a, row, min[k]))
			{
				p[0].value++;
				p[p[0].value] = min[k];
			}
		}
	}
	
	if(p[0].value)
		return true;
	else
		return false;	
}
void Min_row(int a[MAX][MAX], int col, int i, Node min[MAX])
{
	int j;
	
	min[0].value = 0;
	
	for(j=0; j<col; j++)
	{
		if(!j || a[i][j]==min[j-1].value)
			min[0].value++;
		else
		{
			if(a[i][j]<min[j-1].value)
				min[0].value = 1;
			else
				continue;
		}
			
		min[min[0].value].x = i;
		min[min[0].value].y = j;
		min[min[0].value].value = a[i][j];			
	}
}

bool IsMax_col(int a[MAX][MAX], int row, Node v)
{
	int i;
	
	for(i=0; i<row; i++)
	{
		if(a[i][v.y]>v.value)
			return false;
	}
	
	return true;
}
