//http://www.nowcoder.com/practice/365493766c514d0da0cd774d3d40fd49?tpId=8&tqId=11040&rp=3&ru=/ta/cracking-the-coding-interview&qru=/ta/cracking-the-coding-interview/question-ranking

class Flood {
public:
	int floodFill(vector<vector<int> > map, int n, int m) {
		// write code here
		int  min = INT_MAX;
		deal(map, 0, 0, n - 1, m - 1, 0, min);
		return min;
	}
	//�˷���ֻ���ҵ�һ������ͨ���ͽ�������������Һ���ģ���Ҳ�����ж��ܷ���ͨӦ���ô˷�����Ҫ�Ƿ���ֵbool
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
			map[x][y] = 0; //Ӧ���ж�������߹�ȥ�ˣ���Ӧ�ûָ�������
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
		//	return;  //��return�ҵ��Ĳ������ŵģ��������󣻣����������ɲ����߳�ȥӦ�ü�return����������
		}
		map[x][y] = 1;
		deal(map, x + 1, y, n, m, cnt + 1, min);
		deal(map, x - 1, y, n, m, cnt + 1, min);
		deal(map, x, y + 1, n, m, cnt + 1, min);
		deal(map, x, y - 1, n, m, cnt + 1, min);
		//map[x][y] = 0; //Ӧ���ж�������߹�ȥ�ˣ���Ӧ�ûָ�������
	}

	//
	void deal(vector<vector<int> > map, int x, int y, int n, int m, int cnt, int& min){
		if (x <0 || y <0 || x >n || y>m || map[x][y] == 1)
			return;
		if (x == n && y == m){
			if (cnt < min)
				min = cnt;
			//	return;  //��return�ҵ��Ĳ������ŵģ��������󣻣����������ɲ����߳�ȥӦ�ü�return����������
		}
		map[x][y] = 1;
		if (map[x + 1][y] == 0)  //����Ҳ����...
			deal(map, x + 1, y, n, m, cnt + 1, min);
		if (map[x - 1][y] == 0)
			deal(map, x - 1, y, n, m, cnt + 1, min);
		if (map[x ][y+1] == 0)
			deal(map, x, y + 1, n, m, cnt + 1, min);
		if (map[x ][y-1] == 0)
			deal(map, x, y - 1, n, m, cnt + 1, min);
		//map[x][y] = 0; //Ӧ���ж�������߹�ȥ�ˣ���Ӧ�ûָ�������
	}
};