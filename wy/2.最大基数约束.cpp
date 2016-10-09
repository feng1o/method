#if 0
//http://blog.tk-xiong.com/archives/1027
/*
题目描述:
大的奇约数
小易是一个数论爱好者，并且对于一个数的奇数约数十分感兴趣。一天小易遇到这样一个问题：定义函数 f(x) 为 x 最大的奇数约数，x为正整数。 例如:f(44) = 11.
现在给出一个N，需要求出 f(1) + f(2) + f(3)…….f(N)

例如： N = 7
f(1) + f(2) + f(3) + f(4) + f(5) + f(6) + f(7) = 1 + 1 + 3 + 1 + 5 + 3 + 7 = 21小易计算这个问题遇到了困难，需要你来设计一个算法帮助他。

输入描述:
输入一个整数N (1 ≤ N ≤ 1000000000)

输出描述：
输出一个整数，即为f(1) + f(2) + f(3)…….f(N)

输入样例：
7

输出样例：
21
*/
#include <iostream>
using namespace std;

int x = 4;

int f()
{
	static int x = 1;
	x *= x + 1;
	printf("%d", x);
	return 0;
}

int main()
{
	for (int i = 1; i < x; i++)
	{
		f();
	}
	return 0;
}
#endif

// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include "iostream"
#include "vector"

using namespace std;

int grid[2][5] ={
	{ 1, 0, 1, 0, 1 }, {1, 0, 1, 1, 1}};
int countHomes(int grid[][5], int n, int m)
{
	if (0 == n && m == 0)
		return 0;
	vector<vector<int> > dp(n + 1, (vector<int>(m + 1, 0)));
	if (grid[0][0] == 1)
		dp[0][0] = 1;
	for (int i = 0; i < n; ++i){
	
		for (int j = 0; j < m; ++j){
			if (grid[i][j] == 1){
				if (i == 0){
					if (j == 0)
						continue;
					else if (j == m - 1 && grid[i][j - 1] == 0 && grid[i + 1][j] == 0)
						dp[i][j] = dp[i][j - 1] + 1;
					else if (grid[i][j - 1] == 0 && grid[i + 1][j] == 0 && grid[i][j + 1] == 0)
						dp[i][j] = dp[i][j - 1] + 1;
					else
						dp[i][j] = dp[i][j - 1];
				}
				else if (i == n - 1){
					if (j == m - 1 && grid[i][j - 1] == 0 && grid[i - 1][j] == 0)
						dp[i][j] = dp[i][j - 1] + 1;
					else if (0 < j < m - 1 && grid[i][j - 1] == 0 && grid[i - 1][j] == 0 && grid[i][j + 1] == 0)
						dp[i][j] = dp[i][j - 1] + 1;
					else if (j == 0 && grid[i - 1][j] == 0 && grid[i][j + 1] == 0){
						dp[i][j] = dp[i - 1][m - 1] + 1;
					}
					else if (j == 0)
						dp[i][j] = dp[i - 1][m - 1];
					else
						dp[i][j] = dp[i][j - 1];
				}
				else{
					if (j == 0 && grid[i + 1][j] == 0 && grid[i - 1][j] == 0 && grid[i][j + 1] == 0)
						dp[i][j] = dp[i - 1][m - 1] + 1;
					else if (j == m - 1 && grid[i + 1][j] == 0 && grid[i - 1][j] == 0 && grid[i][j - 1] == 0)
						dp[i][j] = dp[i][j - 1] + 1;
					else if (grid[i + 1][j] == 0 && grid[i - 1][j] == 0 && grid[i][j + 1] == 0 && grid[i][j - 1] == 0)
						dp[i][j] = dp[i][j - 1] + 1;
					else if (j != 0)
						dp[i][j] = dp[i][j - 1];
					else dp[i][j] = dp[i - 1][m - 1];
				}
			}
			else if (j != 0)
				dp[i][j] = dp[i][j - 1];
			else if (j == 0 && i == 0)
				continue;
			else if (j == 0 && i != 0)
				dp[i][j] = dp[i - 1][m - 1];
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	return dp[n - 1][m - 1];
}
int countHomes2(int grid[][5], int n, int m)
{
	if (0 == n && m == 0)
		return 0;
	vector<vector<int> > dp(n + 1, (vector<int>(m + 1, 0)));
	if (grid[0][0] == 1)
		dp[0][0] = 1;
	for (int i = 0; i < n; ++i){

		for (int j = 0; j < m; ++j){
			if (grid[i][j] == 1){
				if (i == 0){
					if (j == 0)
						continue;
					else if (grid[i][j - 1] == 0)
						dp[i][j] = dp[i][j - 1] + 1;
					else
						dp[i][j] = dp[i][j - 1];
				}
				
				else{
					if (j == 0 &&  grid[i - 1][j] == 0)
						dp[i][j] = dp[i - 1][m - 1] + 1;
					else if ( grid[i - 1][j] == 0 &&  grid[i][j - 1] == 0)
						dp[i][j] = dp[i][j - 1] + 1;
					else if (j != 0)
						dp[i][j] = dp[i][j - 1];
					else dp[i][j] = dp[i - 1][m - 1];
				}
			}
			else if (j != 0)
				dp[i][j] = dp[i][j - 1];
			else if (j == 0 && i == 0)
				continue;
			else if (j == 0 && i != 0)
				dp[i][j] = dp[i - 1][m - 1];
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	return dp[n - 1][m - 1];
}
int main(){
	cout << countHomes2(grid, 2, 5) << endl;
	return 0;
}