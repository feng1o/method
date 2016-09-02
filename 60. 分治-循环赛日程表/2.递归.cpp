#ifdef a
#include<iostream>  
#include<vector>  
#include<iterator>  
#include<algorithm>  
using namespace std;

/*
*循环赛日程表（递归法）
*/

void Copy(int **map, int sr, int sl, int dr, int dl, int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			map[dr + i][dl + j] = map[sr + i][sl + j];
		}
	}
}

void Table(int **map, int r, int l, int k)
{
	if (1 == k)return;
	//填充左上角  
	Table(map, r, l, k / 2);
	//填充右上角  
	Table(map, r, l + (k / 2), k / 2);
	//从左上角拷贝到右下角  
	Copy(map, r, l, r + k / 2, l + k / 2, k / 2);
	//从右上角拷贝到左下角  
	Copy(map, r, l + k / 2, r + k / 2, l, k / 2);
}

int main()
{
	int k;
	//输入运动员的人数  
	cout << "运动员人数，2的N次方：4,8,..." << endl;
	cin >> k;
	int ** p = new int*[k];
	//赛程表初始化  
	for (int i = 0; i < k; i++)
	{
		p[i] = new int[k];
		p[0][i] = i + 1;
		p[i][0] = i + 1;
	}
	//运行函数  
	Table(p, 0, 0, k);
	//输出结果  
	cout << "循环赛日程表（递归法）:" << endl;
	for (int i = 0; i < k; i++)
	{
		copy(p[i], p[i] + k, ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}
#endif