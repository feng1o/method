#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
using namespace std;

void traverse(int dis[][5], bool *visited, int n, int pos, int res, int &min){
	for (int i = 1; i < n; i++){
		if (visited[i]){
			if (i < n - 1)
				continue;
			res += dis[pos][0];
			if (res < min)
				min = res;
			continue;
		}
		cout << ".." << endl;
		visited[i] = true;
		traverse(dis, visited, n, i, res + dis[pos][i], min);
		visited[i] = false;
	}
}
int main(){
	int n = 5;
	int **dis = new int*[n];
	
	bool *visited = new bool[n];
	for (int i = 0; i < n; i++)
		visited[i] = false;
	int graph[5][5] = { { 0, 2, 0, 6, 0 },
	{ 2, 0, 3, 8, 5 },
	{ 0, 3, 0, 0, 7 },
	{ 6, 8, 0, 0, 9 },
	{ 0, 5, 7, 9, 0 },
	};
	int min = 987654321;
	int res = 0;
	traverse(graph, visited, 5, 0, res, min);
	cout << min << endl;
	return min;
}
