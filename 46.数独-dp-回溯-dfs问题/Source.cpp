/*
TIP:
1.��ӡ�����������û�пո񡣡�������������������������tip���ո�ע����
2.���ݹ��̣�������øı�����������ɻ��ڣ�������ôֻ��return���ҵ���Ҫ�������ˣ�����return������
3.��ס���ø���vector,,,,,http://www.nowcoder.com/practice/78a1a4ebe8a34c93aac006c44f6bf8a1?tpId=37&tqId=21267&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking
4.ע��const��Ӧ��*/
#define _CRT_SECURE_NO_WARNINGS
#include "cstdlib"
#include "string"
#include "iostream"
#include "vector"

using namespace std;
bool check(const vector<vector<int> > vec, int n, int key);
void print(const vector<vector<int> > vec);
void DFS(vector<vector<int> > &vec, int n){ // 3.��ס���ø���vector,,,,, 
	//vec[0][0] = 5;
	if (n>80)
	{
		print(vec);
		return;
	}
	int row = n / 9;
	int col = n % 9;
	if (vec[row][col] != 0)
		DFS(vec, n + 1);
	else{
		for (int key = 1; key < 10; ++key)
		{
			if (check(vec, n, key) == true){
				vec[row][col] = key;
				DFS(vec, n + 1);
				vec[row][col] = 0;               //������ûreturn�ж���һֱ�ᵽ����ݹ�ָ�����������ӡ��������ԭֵһ����
			}
		}
	}
}

/*�Ƚ�dfs3��dfs2,,,,
1.dfs2���������if�ж�����һ��©���ж��ͻ������
2.dfs2�ķ�����ɿ������ڳɹ�n=81��ʱ���ӡ�������������������н������
3.����Ҵ�һ�־�ֹͣ��������return������ÿ�����ݵط���Ҫ�ã���������
4.ע�⣬��ȫ�ֱ�־����*/
bool DFS2(vector<vector<int> > &vec, int n){ // 3.��ס���ø���vector,,,,, 
	//vec[0][0] = 5;
	if (n > 80)
	{
		cout << "\n";
		//print(vec);
		return true;
	}
	int row = n / 9;
	int col = n % 9;
	int flag = false;
	if (vec[row][col] != 0)
		if (DFS2(vec, n + 1) == true)
		{
			return true;
		}
		else                //û����������������else���ṹ�ƻ�������if��üӴ����š�������
			return false;
	/*flag =DFS2(vec, n + 1);
	if (flag)
	return flag;*/
	else{
		for (int key = 1; key < 10; ++key)
		{
			if (check(vec, n, key) == true){
				vec[row][col] = key;
				if (DFS2(vec, n + 1))
					return true;
				else
					vec[row][col] = 0;    //������ûreturn�ж���һֱ�ᵽ����ݹ�ָ�����������ӡ��������ԭֵһ����
			}
		}
	}
	return false;
}
//������if��else�ṹ��������
bool DFS2_1(vector<vector<int> > &vec, int n){ // 3.��ס���ø���vector,,,,, 
	//vec[0][0] = 5;
	if (n > 80)
	{
		cout << "\n";
		//print(vec);
		return true;
	}
	int row = n / 9;
	int col = n % 9;
	int flag = false;
	if (vec[row][col] != 0)
		if (DFS2_1(vec, n + 1) == true)//������if��else�ṹ��������
		{
			return true;
		}  //�����ж�����û����һ����Ҫ/*flag =DFS2(vec, n + 1); ���ǣ�if��else�ṹ���ƻ��ˣ���
	//else
	//return false;
	/*flag =DFS2(vec, n + 1);
	if (flag)
	return flag;*/
		else{
			for (int key = 1; key < 10; ++key)
			{
				if (check(vec, n, key) == true){
					vec[row][col] = key;
					if (DFS2_1(vec, n + 1))
						return true;
					else
						vec[row][col] = 0;               //������ûreturn�ж���һֱ�ᵽ����ݹ�ָ�����������ӡ��������ԭֵһ����
				}
			}
		}
		return false;
}
//�����ڣ��л��ݹ���û�ж�����ֵ������������������������
bool DFS2_2(vector<vector<int> > &vec, int n){ // 3.��ס���ø���vector,,,,, 
	//vec[0][0] = 5;
	if (n > 80)
	{
		cout << "\n";
		//print(vec);
		return true;
	}
	int row = n / 9;
	int col = n % 9;
	int flag = false;
	if (vec[row][col] != 0)
		DFS2_2(vec, n + 1); //...error���������׼���� һ�ν�����ʵ��������ط����أ��ᵽ�����false������true
	/*if (DFS2_2(vec, n + 1) == true)//������if��else�ṹ��������
	{
	return true;
	}  //�����ж�����û����һ����Ҫflag =DFS2(vec, n + 1); ���ǣ�if��else�ṹ���ƻ��ˣ���*/
	//else
	//return false;
	/*flag =DFS2(vec, n + 1);
	if (flag)
	return flag;*/
	else{
		for (int key = 1; key < 10; ++key)
		{
			if (check(vec, n, key) == true){
				vec[row][col] = key;
				if (DFS2_2(vec, n + 1))
					return true;
				else
					vec[row][col] = 0;               //������ûreturn�ж���һֱ�ᵽ����ݹ�ָ�����������ӡ��������ԭֵһ����
			}
		}
	}
	return false;
}
bool sign;


/*�Ƚ�dfs3��dfs2,,,,
1.dfs2���������if�ж�����һ��©���ж��ͻ������
2.dfs2�ķ�����ɿ������ڳɹ�n=81��ʱ���ӡ�������������������н������
3.����Ҵ�һ�־�ֹͣ��������return������ÿ�����ݵط���Ҫ�ã���������
4.ע�⣬��ȫ�ֱ�־����*/
int DFS3(vector<vector<int>>& num, int n)
{
	/* ���еĶ����ϣ��˳�����,n�������������81�����ӣ�0~80 */
	if (n > 80){
		sign = true;
		return 1;
	}

	if (num[n / 9][n % 9] != 0)
		DFS3(num, n + 1);
	else{
		/* ����Ե�ǰλһ������1~9���в��� */
		for (int i = 1; i <= 9; i++){
			if (check(num, n, i)){
				num[n / 9][n % 9] = i;
				/* ��������������λҲ��1~9���ԣ�ֱ�����һλ��ͨ���Ļ���true */
				DFS3(num, n + 1);
				/* ����ʱ�������ɹ�����ֱ���˳� */
				if (sign)
					return 0;
				/* ������첻�ɹ�����ԭ��ǰλ */
				num[n / 9][n % 9] = 0;
			}

		}
	}
	return 0;
}
int main(){
	freopen("data.in", "r", stdin);
	vector<vector<int> > vec(9, vector<int>(9, 0));
	for (int i = 0; i < 81; ++i)
	{
		cin >> vec[i / 9][i % 9];
	}

	print(vec);
	//cout << "ch-" << check(vec, 0, 5) << endl;
	DFS2(vec, 0);
	cout << "....\n\n";
	print(vec);  //tip...............tip...............������ط���ӡ����ô�����ǵĻ����ҵ���Ҫ�ָ�״̬��������ȥ������ֻ��ȥ�ж�����ӡ�ˣ���������
	return 0;
}

bool check(const vector<vector<int> > vec, int n, int key){
	int x = n / 9;
	int y = n % 9;
	for (int i = 0; i < 9; ++i)
		if (vec[x][i] == key || vec[i][y] == key)
			return false;
	int ix = n / 9 / 3 * 3;
	int iy = n % 9 / 3 * 3;
	for (int i = ix; i < ix + 3; ++i)
	{
		for (int j = iy; j < iy + 3; ++j)
		{
			if (vec[i][j] == key)
				return false;
		}
	}
	return true;
}

void print(const vector<vector<int> > vec){
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			//1.��ӡ�����������û�пո񡣡�������������������������tip���ո�ע����
			//cout << vec[i][j] << " ";//
			cout << vec[i][j] << " ";
		}
		cout << vec[i][8]; //.....................
		cout << endl;
	}
}