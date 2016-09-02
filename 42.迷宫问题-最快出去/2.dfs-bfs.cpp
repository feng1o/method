//此方法应该是 BFS，，，dfs看树找路径，，40
http://www.nowcoder.com/practice/365493766c514d0da0cd774d3d40fd49?tpId=8&tqId=11040&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking
//这个能保证最后的是最快到达的，，，因为第一次从00出发，更新了，然后后面发现点不熟0，不再走了，肯定是最近的
//但是，如果是走出去如何非递归？


//如果是让打印所有路径呢？如何非递归，看迷宫问题  43
int floodFill(vector<vector<int> > map, int n, int m) {//如果是让打印所有路径呢？如何非递归，看迷宫问题
	// write code here
	if (map[0][0] == 1 || m <= 1 || n <= 1 || map[n - 1][m - 1] == 1)
		return 0;
	vector<vector<int>> cnt(n, vector<int>(m, 0));//加入单独记录也是可以的
	vector<vector<int>> visited(n, vector<int>(m, 0)); //加入单独的访问记录也ok
	queue<int> que;
	que.push(0);
	int x = 0;
	int y = 0;
	while (!que.empty()){
		int point = que.front();
		que.pop();
		x = point / m;
		y = point%m;
		if (x == n - 1 && y == m - 1)
			return cnt[x][y];
		//return map[x][y];   //map,,cnt 任意一个也是ok的。。。
		if (x + 1 < n && map[x + 1][y] == 0){
			que.push((x + 1)*m + y);
			map[x + 1][y] = map[x][y] + 1;
			cnt[x + 1][y] = cnt[x][y] + 1;
		}
		if (x - 1 > 0 && map[x - 1][y] == 0){
			que.push((x - 1)*m + y);
			map[x - 1][y] = map[x][y] + 1;
			cnt[x - 1][y] = cnt[x][y] + 1;
		}
		if (y + 1 < m && map[x][y + 1] == 0){
			que.push(x*m + y + 1);
			map[x][y + 1] = map[x][y] + 1;
			cnt[x][y + 1] = cnt[x][y] + 1;
		}
		if (y - 1 > 0 && map[x][y - 1] == 0){
			que.push(x*m + y - 1);
			map[x][y - 1] = map[x][y] + 1;
			cnt[x][y - 1] = cnt[x][y] + 1;
		}
	}
	return 0;
}
//广搜，map记录step+1的负数    所有结构自己保存到临时空间了
import java.util.*;
public class Flood {
	public int floodFill(int[][] map, int n, int m) {
		int[][] dir = { { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 } };
		int[][] visited = new int[n][m];
		int[][] path = new int[n][m];
		Queue<Integer> queue = new ArrayDeque<>();
		queue.add(0);
		while (!queue.isEmpty()){
			int node = queue.poll();
			int i = node / m;
			int j = node%m;
			for (int p = 0; p < dir.length; p++) {
				int newi = i + dir[p][0];
				int newj = j + dir[p][1];
				if (newi >= 0 && newi < n&&newj >= 0 && newj < m&&map[newi][newj] != 1 && visited[newi][newj] != 1){
					path[newi][newj] = path[i][j] + 1;
					visited[newi][newj] = 1;
					queue.add(m*newi + newj);
				}
			}
		}
		return path[n - 1][m - 1];
		// write code here
	}
}

class Flood {
public:
	int floodFill(vector<vector<int> > map, int n, int m) {
		// write code here
		if (n == 0 || m == 0 || map[0][0]) return 0;
		queue<int> qRecord;
		int direction[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, { -1, 0 } };
		int x, y, next_x, next_y;
		int point;
		int k;
		qRecord.push(0);
		while (!qRecord.empty()){
			point = qRecord.front();
			qRecord.pop();
			x = point / m;
			y = point%m;
			if ((x + 1) == n && (y + 1) == m){
				return map[n - 1][m - 1];
			}
			for (k = 0; k < 4; k++){
				next_x = x + direction[k][0];
				next_y = y + direction[k][1];
				if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && map[next_x][next_y] == 0){
					qRecord.push(next_x*m + next_y);
					map[next_x][next_y] = map[x][y] + 1;
				}
			}
		}
	}
};