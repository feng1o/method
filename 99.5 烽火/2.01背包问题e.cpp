/*题目描述：
给定一个无向图，包含n个点、m条边，每条边是白色或者黑色，是否可以找到该图的一颗生成树，使得其中的白边条数恰好等于某一斐波纳契数(斐波纳契数列: 1, 2, 3, 5, 8, ...)?
输入
第一行一个正整数T(T<=20)，表示测试数据组数，接下来包含T组测试数据。每组测试数据第一行包含两个整数n(1<=n<=10^5)和m(0<=m<=10^5)，分别表示图中节点数和边数，接下来m行每行包含三个整数u, v, w, (1 <= u <= n, 1 <= v <= n, u不等于v, 0 <= w <= 1)表示结点u和结点v之间存在一条，w=0表示这条边为黑边，w=1表示这条边为白边。
输出
对于每一组测试数据，输出一行"Case #x: s"，x表示第x组数据，x从1开始递增，s为"Yes"或者"No"，"Yes"表示可以找到一棵符合要求的生成树，否则输出"No"，详细参见给定样例。

样例输入
2
4 4
1 2 1
2 3 1
3 4 1
1 4 0
5 6
1 2 1
1 3 1
1 4 1
1 5 1
3 5 1
4 2 1
样例输出
Case #1: Yes
Case #2: No*/

#if 0
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

int getMax(vector<pair<int, int>> vec, int n, int money){
	vector<int> dp(money + 1, 0);
	for (int i = 0; i < n; ++i)
	{
		for (int j = money; j >= vec[i].second; --j)
		{
			if (dp[j] < dp[j - vec[i].second] + vec[i].first)
				dp[j] = dp[j - vec[i].second] + vec[i].first;
		}
	}
	return dp[money];
}
int main(){
	int n;
	int money;
	while (cin >> n >> money){
		vector<pair<int, int>> vec;
		int vi;
		int wi;
		for (int i = 0; i < n; ++i)
		{
			cin >> vi >> wi;
			vec.push_back(make_pair(vi, wi));
		}
		int max = getMax(vec, n, money);
		cout << max << endl;
	}
	return 0;
}
#endif