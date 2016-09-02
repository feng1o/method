#if 01
#include <stdio.h>  
#include "iostream"
#include "vector"
using namespace std;
#define M   10  
#define N   10  
int maze[M][N] = {
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
	0, 0, 1, 0, 1, 0, 1, 0, 0, 1,
	1, 0, 0, 0, 1, 0, 1, 0, 1, 1,
	1, 1, 0, 1, 0, 0, 1, 0, 0, 1,
	1, 1, 0, 0, 0, 1, 1, 0, 1, 1,
	1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
	1, 1, 0, 0, 0, 0, 0, 0, 0, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
};
int StartX = 1, StartY = 1;
int EndX = 8, EndY = 8;
void print();
void travel(int, int);
void travel2(int i, int j, int cnt, int& n);
void travel3(int i, int j, int cnt, int& n);
int main()
{
	print();
	//travel(StartX, StartY);
	int n = INT_MAX;
	int cnt = 0;
	//travel2(StartX, StartY, cnt, n);
	travel3(StartX, StartY, cnt, n);
	cout << "nnnn...=" << n << endl;
	return 0;
}
void print()
{
	printf("·��.........^_^\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (maze[i][j] == 1)
				printf("�}");
			else if (maze[i][j] == 0)
				printf("  ");
			else if (maze[i][j] == 2)
				printf("��");
		}
		printf("\n");
	}
}
void travel(int i, int j)
{
	maze[i][j] = 2;
	if ((i == EndX) && (j == EndY)){
		print();
		return;
	}
	if (maze[i - 1][j] == 0)
		travel(i - 1, j);	
	if (maze[i][j - 1] == 0)
		travel(i, j - 1);	
	if (maze[i + 1][j] == 0)
		travel(i + 1, j);
	if (maze[i][j + 1] == 0)
		travel(i, j + 1);
	maze[i][j] = 0;
}

void travel2(int i, int j, int cnt, int& n){
	if (i > EndX || i <0 || j > EndY || j < 0)
		return;
	maze[i][j] = 2;
	if ((i == EndX) && (j == EndY)){
		print();
		if (cnt < n) n = cnt;
		return; //һ���߳�ȥ�ͽ�����,,,,,,,,��һ������õ� ������������õı�������
		//��Ϊ�˴��б�ǣ����ԣ�return�ˣ���������߹���Ǿ� ֻ�ܷ���һ�����
	}
	if (maze[i + 1][j] == 0)
		travel2(i + 1, j, cnt + 1, n);
	if (maze[i - 1][j] == 0)
		travel2(i - 1, j, cnt + 1, n);
	if (maze[i][j + 1] == 0)
		travel2(i, j + 1, cnt + 1, n);
	if (maze[i][j - 1] == 0)
		travel2(i, j - 1, cnt + 1, n);
	maze[i][j] = 0; //�ָ�  �����������ͨ��·�����ᱻ�������ͨ�˲Żᱣ�� 
	//���޲�Ӱ������ͨ����·������������Ϊcnt���Զ��ع��ģ���

}

void travel3(int i, int j, int cnt, int& n){
	if (i > EndX || i <0 || j > EndY || j < 0 || maze[i][j] != 0)//Ӧ�ø��˷�ʱ��
		return;
	maze[i][j] = 2;
	if ((i == EndX) && (j == EndY)){
		print();
		if (cnt < n) n = cnt;
		cout << "...n====" << cnt<< endl;
		return;    //�������С�ģ������return�����У����ҵ��ͽ����ˣ������������Թ�������ȥ���������           //�����Ž����ʾ������������
		//���return����ֻ��һ������Ϊ��return�ˣ�û�취�������Ļָ���ǰ��Ϊ���ʷ�����⣬���¿϶������ߵ��յ��ˣ�����
		/*void recur(int n){  //���������������û��return����һ���ģ���û������Ϊû�з��ʱ��
			static int i = 0;
			if (n < 1)
				return;
			if (n == 1)
			{
				cout << "n=" << n << endl;
				return;
			}
			cout << "nn===" << n << endl;
			recur(n - 1);
			recur(n - 2);
			//cout << "nn===" << n << endl;
			++i;
			cout << "iiiiiiiiii = " << i << endl;
		}*/
		
	}

	//if (maze[i][j + 1] == 0)
		travel3(i, j + 1, cnt + 1, n);
	//if (maze[i][j - 1] == 0)
		travel3(i, j - 1, cnt + 1, n);
		//if (maze[i + 1][j] == 0)  //Ҳ��ok��.........................
		travel3(i + 1, j, cnt + 1, n);
		//if (maze[i - 1][j] == 0)
		travel3(i - 1, j, cnt + 1, n);
	//maze[i][j] = 0; //�ָ�  �����������ͨ��·�����ᱻ�������ͨ�˲Żᱣ�� 
		//û�����Ҳ����һ�ξͽ����ˣ����������ͨ·�Ƿ�ͨ��Ӧ�ü��Ϸ����ж�������ߵ��ǶԵģ��Ͳ��ܣ�û��ͨ��ʱ�����Ҫ�ָ��Ļ��������ȽϷ���һ��bool������sto 66�����һ��˼·
	//���޲�Ӱ������ͨ����·������������Ϊcnt���Զ��ع��ģ���

}

//����ֻ��Ҫ�ж���һ���Ƿ���ͨ�����������ߵ�·���ǲ����Դ�Ϊ0 1 1 0 1  1������˳�򣬣�sto 66�⣬
//�Ƚ����ṹ�е�ĳ��·���͵���n��·���ж� str="011011"
bool travel4(int i, int j, int cnt, int& n, string str, int index, vector<vector<int>> visited){
	if (i > EndX || i <0 || j > EndY || j < 0 || visited[i][j] !=0 || maze[i][j] != str[index])//Ӧ�ø��˷�ʱ��
		return false;
	visited[i][j] = 1;  //�߹����
	if (str[index]= '\0'){
		return true;  //�ҵ�һ���ǵģ�����Ӧ��ֹͣ���е���
	}
	bool flag = false;
	//if (maze[i][j + 1] == 0)
	flag = travel4(i, j + 1, cnt, n ,str, index + 1, visited) || 
		travel4(i, j - 1, cnt,n, str, index + 1, visited) ||
		travel4(i + 1, j, cnt,n, str, index + 1, visited) ||
		travel4(i - 1, j, cnt, n, str, index + 1, visited);
	if (!flag)
	{
		visited[i][j] = 0;  //ֻ���߲�ͨ �����Ե�ʱ��Żظ�������Ϊ����Ҫ��ͨ��Σ�����sto 66
	}
	return flag;
}
//�����ڣ����������������û��һ��string "aadkgnsd"����ͨ�����������������ʱ��Ӧ�ü��뷵��ֵ�ж���
//���磬ȫ���еݹ����⣬��Ӧ��ע��
#endif