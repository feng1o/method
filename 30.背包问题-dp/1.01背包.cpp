#if 0
//http://www.hawstein.com/posts/dp-knapsack.html

#define  _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include "iostream"
#include "fstream"
using namespace std;
#define MAXN 1000
#define MAXC 100000

int V[MAXN], W[MAXN], x[MAXN];
int d[MAXN][MAXC];

int main(){
	freopen("data.txt", "r", stdin);
	freopen("data.out", "w", stdout);
	int n, C;
	//while (scanf("%d %d", &n, &C) != EOF){
	while(cin >> n >> C){
		for (int i = 0; i<n; ++i)	scanf("%d %d", &V[i], &W[i]);
		for (int i = 0; i < n; ++i)	x[i] = 0; //��ʼ����ӡ����

		for (int i = 0; i <= n; ++i){
			for (int j = 0; j <= C; ++j){
				d[i][j] = i == 0 ? 0 : d[i - 1][j];
				if (i > 0 && j >= V[i - 1])	
				d[i][j] = (d[i][j] > d[i - 1][j - V[i - 1]] + W[i - 1] ? d[i][j] : (d[i - 1][j - V[i - 1]] + W[i - 1]));
			}
		}
		printf("%d\n", d[n][C]);
		/*
		//freaopen�ˣ�����ᵼ���뵽�ļ��ˣ�������������
		ifstream  of("data.out",ios::binary);
		if (of.is_open()){
		cout << "open ....\n";
		while (!of.eof()){
		cout << "open...\n";
		int tmp;
		of >> tmp;
		cout << tmp << endl;
		}
		}
		else
		cout << "not open" << endl;*/
		//�����ӡ����
		int j = C;
		for (int i = n; i > 0; --i){
			if (d[i][j] > d[i - 1][j]){
				x[i - 1] = 1;
				j = j - V[i - 1];
			}
		}
		for (int i = 0; i < n; ++i)	printf("%d ", x[i]);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#endif