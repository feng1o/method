/*������̬�滮
��һ��XxY������һ��������ֻ���߸����ֻ�����һ������ߣ�Ҫ�����Ͻ��ߵ����½ǡ������һ���㷨������������ж������߷���

��������������int x,int y���뷵�ػ����˵��߷���Ŀ����֤x��yС�ڵ���12��
����������

2,2

���أ�2http://www.nowcoder.com/practice/e8bb8e68434e42acbcdff0341f2a32c5?tpId=8&tqId=11033&rp=2&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking
*/
//�ݹ����
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

//�ǵݹ�
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