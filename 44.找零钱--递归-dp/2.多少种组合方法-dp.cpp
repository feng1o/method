#if 0
/*http://www.cnblogs.com/python27/archive/2013/09/05/3303721.html
http://www.nowcoder.com/practice/c0503ca0a12d4256af33fce2712d7b24?tpId=8&tqId=11041&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking
dp-�Ҷ����ַ�����ϣ����������

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
[˼·2] ������ķ���������Ҳ������ô���ǣ�����ϣ����m��Ӳ�ҹ���sum���������һ��Ӳ��Vm��ϵ����ȡֵΪ�޷�����ô���������xm�ֱ�ȡ��0, 1, 2, ..., sum/Vm�������仰˵����������еĵ�ʽ������ļ�����ʽ�������ǵȼ۵ġ�
sum = x1 * V1 + x2 * V2 + ... + 0 * Vm
sum = x1 * V1 + x2 * V2 + ... + 1 * Vm
sum = x1 * V1 + x2 * V2 + ... + 2 * Vm
...
sum = x1 * V1 + x2 * V2 + ... + K * Vm  
��������K�Ǹ�xm��ȡ�������ֵK = sum / Vm������������ʲô���أ���Ҫ���������Ƚ������±����Ķ��壺
  dp[i][sum] = ��ǰi��Ӳ�ҹ���sum �������������
  ������ô��Ŀ������ʵ���Ͼ�����dp[m][sum]������ǰm��Ӳ�ң�����Ӳ�ң�����sum�������������
	����������ϵ�ʽ�У���xn=0ʱ���� ����������أ� ʵ���Ͼ���ǰi-1��Ӳ�����sum����dp[i-1][sum]�֣� xn = 1 ʱ�أ��ж�������ϣ� ʵ��������ǰi-1��Ӳ����ϳ�(sum - Vm)�����������dp[i-1][sum -Vm]��; xn =2�أ� dp[i-1][sum - 2 * Vm]�֣��ȵȡ����е���Щ����������������ǵ�dp[i][sum]�����ԣ�
	dp[i][sum] = dp[i-1][sum - 0*Vm] + dp[i-1][sum - 1*Vm]
	+ dp[i-1][sum - 2*Vm] + ... + dp[i-1][sum - K*Vm]; ����K = sum / Vm
	������һ�ָ��������ѧ�������ǣ�
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
//�Ż��ķǵݹ飬�������Ǹ���������01�����������һ��
#ifdef xx
int dealdp(int *a, int N, int sum){ //���9��8��Ŀ����Ȿ�ʡ���������ʵ�ʴ�dealdp2����� ���������ܽ����
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