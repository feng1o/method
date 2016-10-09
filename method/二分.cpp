#if 0
/*时间限制：C/C++语言 1000MS；其他语言 3000MS
内存限制：C/C++语言 65536KB；其他语言 589824KB
题目描述：
假如一个数组中存储了一个股票，在一天交易窗口内各时间点的股票价格（正整数）。只允许一次买入和一次卖出，请提供一个算法，计算出通过卖出和买入可以得到的最大利润
输入
价格序列，用,号隔开
输出
最大的可能利润

样例输入
2,3,2,4
样例输出
2

*/

#include "iostream"
#include "string"
#include "vector"
using namespace std;

int deal(vector<int> vec, int x, int n)
{
	int lhs = 0; 
	int rhs = n - 1;
	while (lhs < rhs){
		int mid = (lhs + rhs) / 2;
		if (vec[mid] == x)
			return mid;
		if (x > vec[mid]){
			lhs = mid + 1;
		}
		else if (x < vec[mid]){
			rhs = mid - 1;
		}
	}
	if (lhs == 0){
		int i = 0;
		for (; i < n && vec[i] < x; ++i);
		return -1 - i;
	}

	else {
		int i = lhs-1;
		while (i < n && vec[i] < x)
			++i;
		return -1 - i;
	}

}
int main(){
	int x;
	int n;
	vector<int> vec;
	while (cin >> x >> n){
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			vec.push_back(tmp);
		}
		int result = deal(vec, x, n);
		cout << result << endl;
	}
	return 0;
}
#endif