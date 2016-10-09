/*//http://www.acmerblog.com/prims-minimum-spanning-tree-mst-5786.html

void MiniSpanTree_prim(Mgraph G){
	int min, i, j, k;
	int adjvex[MAXVEX];  //相关顶点下标【1,0,1,0，0】表示0和1，，2和1有关系
	int lowcost[MAXVEX];  //最小代价数组

	lowcost[0] = 0;  //
	adjvex[0] = 0;

	for (int i = 0; i < G.numVertex; ++i)
	{
		lowcost[i] = G.arc[0][i];  //从0点开始...
		adjvex[i] = 0;    //都默认与0点有关初始化，，，，
	}

	for (int i = 0; i < G.numVertex; ++i)
	{
		min = INFINITY;
		j = 1;
		k = 0;
		while (j < G.numVertex){  //找出所有与这个顶点i距离最近的那个dian,存在k里面
			if (lowcost[j] != 0 && lowcost[j] < min){  //==0是自己和自己
				min = lowcost[j];
				k = j;
			}
			++j;
		}

		cout << adjvex[k] << k << endl;
		lowcost[k] = 0;   //表示这个点后面不用再找了，，，

		for (int j = 0; j < G.numVertex; ++j)  //更新以k为起点的所有与k相邻的点的代价，，lowcost是没一个k就变一次
		{
			if (lowcost[j] != 0 && G.arc[k][j] < lowcost[j])
			{
				lowcost[j] = g.arc[k][j];
				adjvex[j] = k;
			}
		}
	}
}
*/
#include <stdio.h>
#include <limits.h>

//图中顶点个数
#define V 5

//未在mstSet中的点的集合中，找出最小key的点
int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// 打印MST
int printMST(int parent[], int n, int graph[V][V])
{
	printf("Edge   Weight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
	return 0;
}

// Prim算法
void primMST(int graph[V][V])
{
	int parent[V]; // 保持MST信息
	int key[V];   // 所有顶点的代价值
	bool mstSet[V];  //当前包含在MST中点的集合

	// 初始为无穷大
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;     //
	parent[0] = -1; // 第一个作为树的根。

	//  MST 有V的顶点
	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey(key, mstSet);
		// 添加u到 MST Set
		mstSet[u] = true;
		//更新和u相连的顶点的代价
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// 打印生成的MST
	printMST(parent, V, graph);
}

int main()
{
	/* 创建以下的图
	2    3
	(0)--(1)--(2)
	|   / \   |
	6| 8/   \5 |7
	| /     \ |
	(3)-------(4)
	9          */
	int graph[V][V] = { { 0, 2, 0, 6, 0 },
	{ 2, 0, 3, 8, 5 },
	{ 0, 3, 0, 0, 7 },
	{ 6, 8, 0, 0, 9 },
	{ 0, 5, 7, 9, 0 },
	};

	// Print the solution
	primMST(graph);

	return 0;
}

