public int countWays(int[][] map, int x, int y) {
	// write code here
	/*http://www.nowcoder.com/questionTerminal/b3ae8b9782af4cf29253afb2f6d6907d
	* 1.判断右下角的点以及起点自身是否为障碍点，若是返回0；
	* 2.若右下角的点非障碍点，判断上面和左边是否为障碍点
	*  1.若全都为障碍点，返回0
	*  2.若一个为障碍点，一个不是，则到该点的路径数等于上一个点的路径数（这是递归的思路）
	* 第2部分可以不用递归，而用循环：
	*  dp[i-1][j-1]表示从(0,0)到(i,j)的方法数，如果(i,j)非1，则为障碍点，对应dp[i-1][j-1]为0
	*  其余情况与一般dp相同
	*/
	if (map == null || map.length != x || map[0].length != y){
		return 0;
	}
	if (map[x - 1][y - 1] != 1 || map[0][0] != 1){//最后一个点为障碍点
		return 0;
	}
	int dp[][] = new int[x][y];
	dp[0][0] = 1;
	for (int i = 1; i < x; i++){
		if (map[i][0] != 1){
			dp[i][0] = 0;
		}
		else{
			dp[i][0] = dp[i - 1][0];
		}
	}
	for (int i = 1; i < y; i++){
		if (map[0][i] != 1){
			dp[0][i] = 0;
		}
		else{
			dp[0][i] = dp[0][i - 1];
		}
	}
	for (int i = 1; i < x; i++){
		for (int j = 1; j < y; j++){
			if (map[i][j] != 1){
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = dp[i - 1][j] % 1000000007 + dp[i][j - 1] % 1000000007;
			}
		}
	}
	return (dp[x - 1][y - 1] % 1000000007);
}