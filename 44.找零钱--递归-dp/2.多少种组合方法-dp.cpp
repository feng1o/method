#if 0
/*http://www.cnblogs.com/python27/archive/2013/09/05/3303721.html
http://www.nowcoder.com/practice/c0503ca0a12d4256af33fce2712d7b24?tpId=8&tqId=11041&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking
dp-找多少种方法组合，，，非最佳

* Filename :coins.cpp
* Description: solve coin combinations using dynamic programing
* Complier: g++
* Author: python27
*/
#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

/****************************************************************
[思路2] 从上面的分析中我们也可以这么考虑，我们希望用m种硬币构成sum，根据最后一个硬币Vm的系数的取值为无非有这么几种情况，xm分别取｛0, 1, 2, ..., sum/Vm｝，换句话说，上面分析中的等式和下面的几个等式的联合是等价的。
sum = x1 * V1 + x2 * V2 + ... + 0 * Vm
sum = x1 * V1 + x2 * V2 + ... + 1 * Vm
sum = x1 * V1 + x2 * V2 + ... + 2 * Vm
...
sum = x1 * V1 + x2 * V2 + ... + K * Vm  
　　其中K是该xm能取的最大数值K = sum / Vm。可是这又有什么用呢？不要急，我们先进行如下变量的定义：
  dp[i][sum] = 用前i种硬币构成sum 的所有组合数。
  　　那么题目的问题实际上就是求dp[m][sum]，即用前m种硬币（所有硬币）构成sum的所有组合数。
	在上面的联合等式中：当xn=0时，有 多少种组合呢？ 实际上就是前i-1种硬币组合sum，有dp[i-1][sum]种！ xn = 1 时呢，有多少种组合？ 实际上是用前i-1种硬币组合成(sum - Vm)的组合数，有dp[i-1][sum -Vm]种; xn =2呢， dp[i-1][sum - 2 * Vm]种，等等。所有的这些情况加起来就是我们的dp[i][sum]。所以：
	dp[i][sum] = dp[i-1][sum - 0*Vm] + dp[i-1][sum - 1*Vm]
	+ dp[i-1][sum - 2*Vm] + ... + dp[i-1][sum - K*Vm]; 其中K = sum / Vm
	　　换一种更抽象的数学描述就是：
* coin Combinations: using dynamic programming
*
* Basic idea:
* dp[i][j] = sum(dp[i-1][j-k*coins[i-1]]) for k = 1,2,..., j/coins[i-1]
* dp[0][j] = 1 for j = 0, 1, 2, ..., sum
*
* Input:
* coins[] - array store all values of the coins
* coinKinds - how many kinds of coins there are
* sum - the number you want to construct using coins
*
* Output:
* the number of combinations using coins construct sum
*
* Usage:
* c[3] = {1, 2, 5};
* int result = coinCombinations(c, 3, 10);
*
****************************************************************/
int coinCombinations(int coins[], int coinKinds, int sum)
{
	// 2-D array using vector: is equal to: dp[coinKinds+1][sum+1] = {0};
	vector<vector<int> > dp(coinKinds + 1);
	for (int i = 0; i <= coinKinds; ++i)
	{
		dp[i].resize(sum + 1);
	}
	for (int i = 0; i <= coinKinds; ++i)
	{
		for (int j = 0; j <= sum; ++j)
		{
			dp[i][j] = 0;
		}
	}

	//init: dp[i][0] = 1; i = 0, 1, 2 ..., coinKinds
	//Notice: dp[0][0] must be 1, althongh it make no sense that
	//using 0 kinds of coins construct 0 has one way. but it the foundation
	//of iteration. without it everything based on it goes wrong
	for (int i = 0; i <= coinKinds; ++i)
	{
		dp[i][0] = 1;
	}

	// iteration: dp[i][j] = sum(dp[i-1][j - k*coins[i-1]])
	// k = 0, 1, 2, ... , j / coins[i-1]
	for (int i = 1; i <= coinKinds; ++i)
	{
		for (int j = 1; j <= sum; ++j)
		{
			dp[i][j] = 0;
			for (int k = 0; k <= j / coins[i - 1]; ++k)
			{
				dp[i][j] += dp[i - 1][j - k * coins[i - 1]];
			}
		}
	}

	return dp[coinKinds][sum];
}
//优化的非递归，，上面是根本，，，01背包类似情况一样
#ifdef xx
int dealdp(int *a, int N, int sum){ //金典9。8题目；理解本质。。。。。实际从dealdp2哪里加 背包问题总结出的
	if (a == nullptr || N < 1 || sum < 0) return 0;
	vector<int> vec(sum+1, 0);
	vec[0] = 1;
	for (int i = 1; i <= N; ++i){
		for (int j = a[i-1] ; j <= sum; ++j){
			//vec[j] += vec[j - a[i - 1]] % 1000000007;
			vec[j] = (vec[j] + vec[j - a[i - 1]]) % 1000000007;
		}
		}
	return vec[sum];
}
#endif 
int main()
{
	int coins[8] = { 1, 2, 5, 10, 20, 50, 100, 200 };
	int sum = 200;
	int result = coinCombinations(coins, 8, 200);
	cout << "using 8 kinds of coins construct 200, combinations are: " << endl;
	cout << result << endl;
	return 0;
}
#endif