//http://www.nowcoder.com/practice/365493766c514d0da0cd774d3d40fd49?tpId=8&tqId=11040&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking

class Flood {
public:
	int floodFill(vector<vector<int> > map, int n, int m) {
		// write code here
		int  min = INT_MAX;
		deal(map, 0, 0, n - 1, m - 1, 0, min);
		return min;
	}
	//此方法只能找到一个能走通，就结束，不会继续找后面的，，也就是判定能否走通应该用此法，主要是返回值bool
	bool deal(vector<vector<int> > map, int x, int y, int n, int m, int cnt, int& min){
		if (x <0 || y <0 || x >n || y>m || map[x][y] == 1)
			return false;
		if (x == n && y == m){
			if (cnt < min)
				min = cnt;
			return true;
		}
		map[x][y] = 1;
		bool flag = false;
		flag = deal(map, x + 1, y, n, m, cnt + 1, min) ||
			deal(map, x - 1, y, n, m, cnt + 1, min) ||
			deal(map, x, y + 1, n, m, cnt + 1, min) ||
			deal(map, x, y - 1, n, m, cnt + 1, min);
		if (!flag)
			map[x][y] = 0; //应有判定，如果走过去了，不应该恢复，，，
		else
			return true;
		return flag;
	}


	void deal222(vector<vector<int> > map, int x, int y, int n, int m, int cnt, int& min){
		if (x <0 || y <0 || x >n || y>m || map[x][y] == 1)
			return;
		if (x == n && y == m){
			if (cnt < min)
				min = cnt;
		//	return;  //加return找到的不是最优的，，，错误；；包含不，可不可走出去应该加return来避免多次走
		}
		map[x][y] = 1;
		deal(map, x + 1, y, n, m, cnt + 1, min);
		deal(map, x - 1, y, n, m, cnt + 1, min);
		deal(map, x, y + 1, n, m, cnt + 1, min);
		deal(map, x, y - 1, n, m, cnt + 1, min);
		//map[x][y] = 0; //应有判定，如果走过去了，不应该恢复，，，
	}

	//
	void deal(vector<vector<int> > map, int x, int y, int n, int m, int cnt, int& min){
		if (x <0 || y <0 || x >n || y>m || map[x][y] == 1)
			return;
		if (x == n && y == m){
			if (cnt < min)
				min = cnt;
			//	return;  //加return找到的不是最优的，，，错误；；包含不，可不可走出去应该加return来避免多次走
		}
		map[x][y] = 1;
		if (map[x + 1][y] == 0)  //这样也可以...
			deal(map, x + 1, y, n, m, cnt + 1, min);
		if (map[x - 1][y] == 0)
			deal(map, x - 1, y, n, m, cnt + 1, min);
		if (map[x ][y+1] == 0)
			deal(map, x, y + 1, n, m, cnt + 1, min);
		if (map[x ][y-1] == 0)
			deal(map, x, y - 1, n, m, cnt + 1, min);
		//map[x][y] = 0; //应有判定，如果走过去了，不应该恢复，，，
	}
};