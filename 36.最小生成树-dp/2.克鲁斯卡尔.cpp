int find(int *parent, int f){
	while(parent[f] > 0)
	{
		f = parent[f];
	}
	return f;
}

void MiniSapnTree_kruskal(Mgrap G){
	int i, n, m;
	Edge edges[MAXEDGE]; //边的个数，已经按照有序排列了
	int parent[MAXVEX]; //顶点个数

	for (int i = 0; i < G.numVertex; ++i)
	{
		parent[i] = 0;
	}
	for (int i = 0; i < G.numVertex; ++i)
	{
		n = find(parent, edges[i].begin);
		m = find(parent, edges[i].end);

		if(n != m){
			parent[n] = m;
			cout << edges[i].begin << edges[i].end <<endl;
		}
	}
}

/* lizi
#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<set>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<deque>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<ctime>
#include<functional>
using namespace std;

#define N 50000+10
int n, m, r;
struct Edge
{
	int x, y, d;
	bool operator <(const Edge&r)const
	{
		return d < r.d;
	}
	void read()
	{
		scanf("%d%d%d", &x, &y, &d);
		y += n, d = -d;
	}
}c[N];
int p[N];
int find(int x)
{
	return p[x] == x ? x : p[x] = find(p[x]);
}
int Kruskal()
{
	for (int i = 0; i < N; i++)
		p[i] = i;
	sort(c, c + r);
	int res = 0;
	for (int i = 0; i < r; i++)
	{
		int x = find(c[i].x), y = find(c[i].y);
		if (x != y)
		{
			res += c[i].d;
			p[x] = y;
		}
	}
	return res;
}
int main()
{
	//freopen("t.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d", &n, &m, &r);
		memset(c, 0, sizeof(c));
		for (int i = 0; i < r; i++)
			c[i].read();
		printf("%d\n", 10000 * (n + m) + Kruskal());
	}
	return 0;
}*/