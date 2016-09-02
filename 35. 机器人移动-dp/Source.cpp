/*基本动态规划
有一个XxY的网格，一个机器人只能走格点且只能向右或向下走，要从左上角走到右下角。请设计一个算法，计算机器人有多少种走法。

给定两个正整数int x,int y，请返回机器人的走法数目。保证x＋y小于等于12。
测试样例：

2,2

返回：2http://www.nowcoder.com/practice/e8bb8e68434e42acbcdff0341f2a32c5?tpId=8&tqId=11033&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking
*/
//递归回溯
class Robot {
public:
	int countWays(int x, int y) {
		// write code here
		if (x < 1 || y < 1)
			return 0;
		if (x == 1 || y == 1)
			return 1;
		return countWays(x - 1, y) + countWays(x, y - 1);
	}


};

//非递归
public int countWays(int x, int y) {
	// write code here
	int[][] dp = new int[x][y];
	dp[0][0] = 1;
	for (int i = 1; i < x; i++){
		dp[i][0] = dp[i - 1][0];
	}
	for (int i = 1; i < y; i++){
		dp[0][i] = dp[0][i - 1];
	}
	for (int i = 1; i < x; i++){
		for (int j = 1; j < y; j++){
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	return dp[x - 1][y - 1];
}