/*��Ŀ������
����һ������ͼ������n���㡢m���ߣ�ÿ�����ǰ�ɫ���ߺ�ɫ���Ƿ�����ҵ���ͼ��һ����������ʹ�����еİױ�����ǡ�õ���ĳһ쳲�������(쳲���������: 1, 2, 3, 5, 8, ...)?
����
��һ��һ��������T(T<=20)����ʾ������������������������T��������ݡ�ÿ��������ݵ�һ�а�����������n(1<=n<=10^5)��m(0<=m<=10^5)���ֱ��ʾͼ�нڵ����ͱ�����������m��ÿ�а�����������u, v, w, (1 <= u <= n, 1 <= v <= n, u������v, 0 <= w <= 1)��ʾ���u�ͽ��v֮�����һ����w=0��ʾ������Ϊ�ڱߣ�w=1��ʾ������Ϊ�ױߡ�
���
����ÿһ��������ݣ����һ��"Case #x: s"��x��ʾ��x�����ݣ�x��1��ʼ������sΪ"Yes"����"No"��"Yes"��ʾ�����ҵ�һ�÷���Ҫ������������������"No"����ϸ�μ�����������

��������
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
�������
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