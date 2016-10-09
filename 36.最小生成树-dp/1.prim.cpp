/*//http://www.acmerblog.com/prims-minimum-spanning-tree-mst-5786.html

void MiniSpanTree_prim(Mgraph G){
	int min, i, j, k;
	int adjvex[MAXVEX];  //��ض����±꡾1,0,1,0��0����ʾ0��1����2��1�й�ϵ
	int lowcost[MAXVEX];  //��С��������

	lowcost[0] = 0;  //
	adjvex[0] = 0;

	for (int i = 0; i < G.numVertex; ++i)
	{
		lowcost[i] = G.arc[0][i];  //��0�㿪ʼ...
		adjvex[i] = 0;    //��Ĭ����0���йس�ʼ����������
	}

	for (int i = 0; i < G.numVertex; ++i)
	{
		min = INFINITY;
		j = 1;
		k = 0;
		while (j < G.numVertex){  //�ҳ��������������i����������Ǹ�dian,����k����
			if (lowcost[j] != 0 && lowcost[j] < min){  //==0���Լ����Լ�
				min = lowcost[j];
				k = j;
			}
			++j;
		}

		cout << adjvex[k] << k << endl;
		lowcost[k] = 0;   //��ʾ�������治�������ˣ�����

		for (int j = 0; j < G.numVertex; ++j)  //������kΪ����������k���ڵĵ�Ĵ��ۣ���lowcost��ûһ��k�ͱ�һ��
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

//ͼ�ж������
#define V 5

//δ��mstSet�еĵ�ļ����У��ҳ���Сkey�ĵ�
int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// ��ӡMST
int printMST(int parent[], int n, int graph[V][V])
{
	printf("Edge   Weight\n");
	for (int i = 1; i < V; i++)
		printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
	return 0;
}

// Prim�㷨
void primMST(int graph[V][V])
{
	int parent[V]; // ����MST��Ϣ
	int key[V];   // ���ж���Ĵ���ֵ
	bool mstSet[V];  //��ǰ������MST�е�ļ���

	// ��ʼΪ�����
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;     //
	parent[0] = -1; // ��һ����Ϊ���ĸ���

	//  MST ��V�Ķ���
	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey(key, mstSet);
		// ���u�� MST Set
		mstSet[u] = true;
		//���º�u�����Ķ���Ĵ���
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// ��ӡ���ɵ�MST
	printMST(parent, V, graph);
}

int main()
{
	/* �������µ�ͼ
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

