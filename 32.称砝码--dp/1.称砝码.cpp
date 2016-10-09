/*现有一组砝码，重量互不相等，分别为m1,m2,m3…mn；
每种砝码对应的数量为x1,x2,x3...xn。现在要用这些砝码去称物体的重量，问能称出多少中不同的重量。
http://www.nowcoder.com/practice/f9a4c19050fc477e9e27eb75f3bfd49c?tpId=37&tqId=21264&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
参考：
/*从砝码1开始分析，假设前i个砝码能称出的不同重量为Q[i],那么Q[i]一定是这样计算出来的：在Q[i-1]的基础上，对Q[i-1]个不同的重量，分别添加k个砝码i，再添加的过程中除去重复情况。
//假设：w[N]表示N个不同重量的砝码（例子中N=6），w[0~N-1]。
//      c[N]表示N个不同砝码相应的数量，c[1~N]。
//则：Q[i] = (Q[i-1] + k*w[i])-添加过程中重复的个数。其中0=<k<=c[i]。网上博客搜的解题思路*/

* /

#define  _CRT_SECURE_NO_WARNINGS
#include "cstdlib"
#include "string"
#include "iostream"
#include "vector"
#include "algorithm"
#include "numeric"
#include "functional"

using namespace std;

int main(){
	freopen("data.in", "r", stdin);
	int n = 0;
	while (cin >> n){
		//cout << n << endl;
		vector<int>  m(n, 0);
		vector<int>  c(n, 0);
		for (int i = 0; i < n; ++i)
			cin >> m[i];
		for (int i = 0; i < n; ++i)
			cin >> c[i];
		vector<int> w;
		//w.push_back(0);
		for (int i = 0; i <= c[0]; ++i) //取等。。。。。。。。。
		{
			w.push_back(i*m[0]);
		}
		for (int j = 1; j < n; ++j)
		{
			int size = w.size();
			for (int k = 1; k <= c[j]; ++k)   //取等。。。。。。。。。
			{
				for (int i = 0; i < size; ++i)
				{
					if (find(w.begin(), w.end(), w[i] + k*m[j]) == w.end())
					{
						w.push_back(w[i] + k*m[j]);
					}
				}
			}
		}
		//w.push_back(0);
		cout << w.size() << endl;
	}
	return 0;
}