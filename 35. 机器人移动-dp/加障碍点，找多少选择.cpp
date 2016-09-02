public int countWays(int[][] map, int x, int y) {
	// write code here
	/*http://www.nowcoder.com/questionTerminal/b3ae8b9782af4cf29253afb2f6d6907d
	* 1.�ж����½ǵĵ��Լ���������Ƿ�Ϊ�ϰ��㣬���Ƿ���0��
	* 2.�����½ǵĵ���ϰ��㣬�ж����������Ƿ�Ϊ�ϰ���
	*  1.��ȫ��Ϊ�ϰ��㣬����0
	*  2.��һ��Ϊ�ϰ��㣬һ�����ǣ��򵽸õ��·����������һ�����·���������ǵݹ��˼·��
	* ��2���ֿ��Բ��õݹ飬����ѭ����
	*  dp[i-1][j-1]��ʾ��(0,0)��(i,j)�ķ����������(i,j)��1����Ϊ�ϰ��㣬��Ӧdp[i-1][j-1]Ϊ0
	*  ���������һ��dp��ͬ
	*/
	if (map == null || map.length != x || map[0].length != y){
		return 0;
	}
	if (map[x - 1][y - 1] != 1 || map[0][0] != 1){//���һ����Ϊ�ϰ���
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