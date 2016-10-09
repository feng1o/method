#if 0
#include <stdio.h>
#include <limits.h>
#include "iostream"
#include "vector"
using namespace std;

//int minKey(int key[], bool mstSet[])
int minKey(vector<int> key, vector<int> mstSet, int V)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;

	return min_index;
}

// ��ӡMST
int printMST(vector<int> parent, int n, vector< vector<int> > &graph, int V)
{
	//printf("Edge   Weight\n");
	int sum = 0;
	for (int i = 1; i < V; i++)
		//printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
		sum += graph[i][parent[i]];
	cout << sum << endl;
	return 0;
}

// Prim�㷨
void primMST(vector< vector<int> > &graph, int V)
{
	//int parent[V]; // ����MST��Ϣ
	vector<int> parent(V, 0);
	//int key[V];   // ���ж���Ĵ���ֵ
	vector<int> key(V, 0);
	//bool mstSet[V];  //��ǰ������MST�е�ļ���

	vector<int> mstSet(V, 0);
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	key[0] = 0;     //
	parent[0] = -1; // ��һ����Ϊ���ĸ���

	//  MST ��V�Ķ���
	for (int count = 0; count < V - 1; count++)
	{
		int u = minKey(key, mstSet, V);
		// ���u�� MST Set
		mstSet[u] = true;
		//���º�u�����Ķ���Ĵ���
		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// ��ӡ���ɵ�MST
	printMST(parent, V, graph, V);
}

int main()
{
	int n;
	while (cin >> n){
		if (n <=0 )
			continue;
		vector <vector<int> > vec(n, vector<int>(n, 0));
		for (int i = 0; i < n; ++i)
		{
			int j = 0;
			for (; j <= n-2; ++j)
			{
				cin >> vec[i][j];
				char ch;
				cin >> ch;
			}
			cin >> vec[i][j];
		}

		primMST(vec, n);
	}


	return 0;
}

#endif