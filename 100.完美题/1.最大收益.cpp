/*计算最大获益时机
时间限制：C/C++语言 10MS；其他语言 2010MS
内存限制：C/C++语言 1KB；其他语言 524289KB
题目描述：
假设你能重返过去，现在让你回到2015年，你能选择一支股票进行投资，你拥有这支股票未来n天的价格走势图，为了躲避证监会的监控，你只有一次买入卖出机会。现在要求实现一个程序计算哪天买入哪天卖出能获得最大收益。
输入
第一行为天数n
接下来n行 为数组的n个整数元素，代表第n天该股票的价格
输出
输出为b，s      #代表第b天买入，第s天卖出

天数从0开始
如果没有适合的买入卖出 输出 -1,-1
同样收益时越晚买入越早卖出更符合需要

样例输入
5
2
1
4
5
3
样例输出
1, 3

*/

#if 0
#include "iostream"
#include "string"
#include "vector"
#include "climits"

using namespace std;

int main(){
	int n;
	while (cin >> n){
		vector<int> vec;
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		int max = 0;
		int min = INT_MAX;
		int lhs = -1;
		int rhs = -1;
		for (int i = 0; i < n; ++i)
		{
			if(vec[i] < min){
				min = vec[i];
				lhs = i;
			}
			if(vec[i] - min > max){
				rhs = i;
			}
			/*for (int j = i + 1; j < n; ++j)
			{
				if (vec[j] - vec[i] > max){
					max = vec[j] - vec[i];
					lhs = i;
					rhs = j;
				}
			}*/
		}
		cout << lhs << "," << rhs << endl;
	}
	return 0;
}
#endif