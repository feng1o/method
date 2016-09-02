/*
tip��
1.�ݹ���̶���ĳЩֵ��ǧ��Ҫ�������ã��������緵�ؽ���������ã���ʹ�õڶ��ε�������ڵ�һ��δ��յġ�������*/

#define  _CRT_SECURE_NO_WARNINGS

#include "string"
#include<iostream>
#include<vector>
#include "utility"
#include "ctime"

using namespace std;
//void deal(vector<vector<int> >& vec, int x, int y, int row, int  col, vector<pair<int, int>> &pvec){ 
void deal(vector<vector<int> >& vec, int x, int y, int row, int  col, vector<pair<int, int>> &pvec){ //�м� ���pvec���ﲻҪ��&�������ҵ��ĺ�������ǰ��ı�ǣ�������������������������������
	if (x<0 || y < 0 || x > row || y > col || vec[x][y] == 1 || vec[row][col] == 1) return;
	vec[x][y] = 1;//fang���ʱ�Ƿŵ�λ�ò�һ�����ᵼ�½���Ǽ����Ĳ��.................................................;
	pvec.push_back(make_pair(x, y));//�����λ�ú���Ҫ������������������������ˣ�if����Ĳ���push��
	if (x == row && y == col)
	{
		//pvec.push_back(make_pair(row, col));
		cout << "new.....paht.......\n\n";
		for (auto& it : pvec)
		{
			cout << '(' << it.first << ',' << it.second << ')' << endl;
		}
		//return; //return ������Ӱ��ݹ鼸�Σ�����ʵ�ʻ���Ҫ����ģ��������ֻ��һ���⣬��ôӦ���ж��ˣ�ֻҪ�ҵ���ֹͣ������return��ÿ��Ŷ��return
	}
	//pvec.push_back(make_pair(x, y));
	//vec[x][y] = 1; //fang���ʱ�Ƿŵ�λ�ò�һ�����ᵼ�½���Ǽ����Ĳ��.................................................
	deal(vec, x + 1, y, row, col, pvec);
	deal(vec, x, y+1, row, col, pvec);
	cout << ">>>>>\n";
	pvec.pop_back();
	vec[x][y] = 0;
}

//tip�����ֻ�ᱣ��һ�����������ǿ��������õġ�������������������
bool  deal2(vector<vector<int> >& vec, int x, int y, int row, int  col, vector<pair<int, int>> &pvec){ //����ķ�������ٺܶ�εݹ�
	if (x<0 || y < 0 || x > row || y > col || vec[x][y] == 1 || vec[row][col] == 1) return false;
	if (x == row && y == col)
	{
		pvec.push_back(make_pair(row, col));
		cout << "new.....paht.......\n\n";
		for (auto& it : pvec)
		{
			cout << '(' << it.first << ',' << it.second << ')' << endl;
		}
		return true; //return ������Ӱ��ݹ鼸�Σ�����ʵ�ʻ���Ҫ����ģ��������ֻ��һ���⣬��ôӦ���ж��ˣ�ֻҪ�ҵ���ֹͣ������return��ÿ��Ŷ��reture
	}
	pvec.push_back(make_pair(x, y));
	vec[x][y] = 1;
	bool flag = false;
	if (deal2(vec, x + 1, y, row, col, pvec) || deal2(vec, x, y + 1, row, col, pvec))
		return true;
	else {
		cout << ">>>>>>>>>>>>>>>>>22222222222222\n";
		pvec.pop_back();
		vec[x][y] = 0;
		return false;
	}
}

/*����汾������
1.�˴����ã�pvec����
2.vec[x][y] = 1�ŵ�λ�ò��ԣ���
3.ѹ����Ҳ��Ӧ������
*/
void deal3(vector<vector<int> >& vec, int x, int y, int row, int  col, vector<pair<int, int>> &pvec){ //1..................
	if (x<0 || y < 0 || x > row || y > col || vec[x][y] == 1 || vec[row][col] == 1) return;
	if (x == row && y == col)
	{
		pvec.push_back(make_pair(row, col));
		cout << "new.....paht.......\n\n";
		for (auto& it : pvec)
			cout << '(' << it.first << ',' << it.second << ')' << endl;
		return;
	}
	pvec.push_back(make_pair(x, y)); //3/////////////////
	vec[x][y] = 1; //2.................................................
	deal3(vec, x + 1, y, row, col, pvec);
	deal3(vec, x, y + 1, row, col, pvec);
	cout << ">>>>>\n";
	pvec.pop_back();
	vec[x][y] = 0;
}

int main(){
	cin.ignore(10, '\n');
	string str;
	getline(cin, str);
	cout << str << endl;

	int row;
	int col;
	freopen("data.in", "r", stdin);
	while (cin >> row >> col){
		vector<vector<int> >  vec(row, vector<int>(col, 0));
		for (int i = 0; i < row; ++i)
			for (int j = 0; j < col; ++j)
				cin >> vec[i][j];
		clock_t start = clock();
		vector<pair<int, int>> pvec;
		deal(vec, 0, 0, row-1, col-1, pvec);
		cout << "ֵһ�Σ��ҵ���ֱ�ӷ��صķ���......\n";
		//deal2(vec, 0, 0, row-1, col-1, pvec);
		clock_t stop = clock();
		cout << "time = " << stop - start << endl;
		//�˴���ӡ�Ĳ�����ȷ�ģ���������
	/*	for (auto& it : pvec)
		{
			cout << '(' << it.first << ',' << it.second << ')' << endl;
		}*/
	}
	return 0;
}



