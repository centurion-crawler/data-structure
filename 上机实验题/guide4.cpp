#include <iostream>//kruskral
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
 
struct Edge
{
	int u;//边连接的一个顶点编号
	int v; //边连接另一个顶点编号
	int w; //边的权值
	friend bool operator<(const Edge& E1, const Edge& E2)
	{
		return E1.w < E2.w;
	}
};
void MakeSet(vector<int>& uset, int n)
{
	uset.assign(n, 0);
	for (int i = 0; i < n; i++)
		uset[i] = i;
}
//查找当前元素所在集合的代表元
int FindSet(vector<int>& uset, int u)
{
	int i = u;
	while (uset[i] != i) i = uset[i];
	return i;
}
void Kruskal(const vector<Edge>& edges, int n)
{
	vector<int> uset;
	vector<Edge> SpanTree;
	int Cost = 0, e1, e2;
	MakeSet(uset, n);
	for (int i = 0; i < edges.size(); i++) //按权值从小到大的顺序取边
	{
		e1 = FindSet(uset, edges[i].u);
		e2 = FindSet(uset, edges[i].v);
		if (e1 != e2) //若当前边连接的两个结点在不同集合中，选取该边并合并这两个集合
		{
			SpanTree.push_back(edges[i]);
			Cost += edges[i].w;
			uset[e1] = e2; //合并当前边连接的两个顶点所在集合
		}
	}
	cout << "Result:\n";
	cout << "Cost: " << Cost << endl;
	cout << "Edges:\n";
	for (int j = 0; j < SpanTree.size(); j++)
		cout << SpanTree[j].u << " " << SpanTree[j].v << " " << SpanTree[j].w << endl;
	cout << endl;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vector<Edge> edges;
	edges.assign(m, Edge());
	for (int i = 0; i < m; i++)
		cin >> edges[i].u >> edges[i].v >> edges[i].w;
	sort(edges.begin(), edges.end()); //排序之后，可以以边权值从小到大的顺序选取边
	Kruskal(edges, n);
	return 0;
}
