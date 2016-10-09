#define  _CRT_SECURE_NO_WARNINGS
#include<string>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<algorithm>
#include<ctime>
#include<unordered_map>
#include<map>
#include<typeinfo>
#include<cmath>
#include<ctime>
#include<climits>
#include "cassert"
#include "cmath"
using namespace std;

vector<int> fbnq(100001, 1);
void doFbnq(){
	fbnq[1] = 2;
	for (int i = 2; i < 100001; ++i)
	{
		fbnq[i] = fbnq[i - 1] + fbnq[i - 2];
	}
}
bool deal(vector<vector<int>> graph, int s, int i, int n, vector<bool>& visited, int sum){
	if (i >= n-1){
		cout << "-----" << sum << endl << endl;
		if (find(fbnq.begin(), fbnq.end(), sum) == fbnq.end())
		{
			return false;
		}
		else
			return true;
	}
	int pos = s % n;
	visited[pos] = true;
	//int flag;
	for (int j = 0; j < n && j != pos; ++j){
		//cout << "j =" << j << endl;
		if ((graph[pos][j] == 1 || graph[pos][j] == 0) && visited[j] == false)
		{
			int flag = false;
			if (graph[pos][j] == 1)
				sum++, flag = true;
			//cout << " sum=" << sum << endl;
			if (deal(graph, j, i+1, n, visited, sum))
				return true;
			if (flag)
			{
				//visited[pos] = false;
				--sum;
			}
		}
	}
	visited[pos] = false;
	return false;
}
int main2()
{
	int grp;
	doFbnq();
	while (cin >> grp){
		for (int i = 1; i <= grp; ++i)
		{

			int vetex, edge;
			cin >> vetex >> edge;
			vector<vector<int>> graph(vetex, vector<int>(vetex, -1));
			int x, y;
			for (int i = 0; i < edge; ++i)
			{
				cin >> x >> y;
				cin >> graph[x-1][y-1];
			}
			bool flag = false;
			for (int j = 0; j < vetex; ++j){
				vector<bool> visited(vetex, false);
				flag = deal(graph, j, 0, vetex, visited, 0);
				if (flag){
					cout << "Case #" << i << ":" << " Yes" << endl;
					break;
				}
			}
			if (flag == false)
			{
				cout << "Case #" << i << ":" << " No" << endl;
			}
			else
				cout << "Case #" << i << ":" << " Yes" << endl;
		}

	}
	return 0;
}
class  a{
	a(){};
	int fun(){};
	
};

int fun(int n){
	static int  m;
	m += n;
	return m;
}
int main(){
	int n = 0;
	cout << fun(++n) << endl;
	cout << fun(n++) << endl;
}
