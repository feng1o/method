#if 01

/**
分治法，循环赛事日程表
*/
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <math.h>

void Table(int k, int n, int **a);
void input(int &k);
void output(int **a, int n);

int main()
{
	int k;
	input(k);
	int n = 1; //n=2k(k>=1)个选手参加比赛
	for (int i = 1; i <= k; i++)
		n *= 2;
	int **a = new int *[n + 1];//根据n动态分配二维数组a
	for (int i = 0; i <= n; i++)
	{
		a[i] = new int[n + 1];
	}
	Table(k, n, a);
	printf("循环赛事日程表为：\n");
	output(a, n);
	for (int i = 0; i <= n; i++){
		delete[] a[i];
	}
	delete[] a;

	return 0;
}

void input(int &k)
{
	printf("请输入k值：\n");
	scanf("%d", &k);
}

void output(int **a, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void Table(int k, int n, int **a)
{
	for (int i = 1; i <= n; i++)
		a[1][i] = i;//设置日程表第一行

	int m = 1;//每次填充时，起始填充位置
	for (int s = 1; s <= k; s++)
	{
		n /= 2;
		for (int t = 1; t <= n; t++)  //从1-n/2,,1-n/4...
		{
			for (int i = m + 1; i <= 2 * m; i++)//控制行
			{
				for (int j = m + 1; j <= 2 * m; j++)//控制列
				{
					a[i][j + (t - 1)*m * 2] = a[i - m][j + (t - 1)*m * 2 - m];//右下角等于左上角的值
					a[i][j + (t - 1)*m * 2 - m] = a[i - m][j + (t - 1)*m * 2];//左下角等于右上角的值
				}

			}
		}
		m *= 2;
	}
}
#ifdef x
void gametable(int k)
{
	int a[100][100];
	int n, temp, i, j, p, t;
	n = 2;//k=0两个参赛选手日程可以直接求得
	a[1][1] = 1; a[1][2] = 2;
	a[2][1] = 2; a[2][2] = 1;
	for (t = 1; t < k; t++)//迭代处理，依次处理2^n....2^k个选手的比赛日程
	{
		temp = n; n = n * 2;//填左下角元素
		for (i = temp + 1; i <= n; i++)
			for (j = 1; j <= temp; j++)
				a[i][j] = a[i - temp][j] + temp;//左下角和左上角元素的对应关系
		for (i = 1; i <= temp; i++)//将左下角元素抄到右上角
			for (j = temp + 1; j <= n; j++)
				a[i][j] = a[i + temp][(j + temp) % n];
		for (i = temp + 1; i <= n; i++)//将左上角元素抄到右下角
			for (j = temp + 1; j <= n; j++)
				a[i][j] = a[i - temp][j - temp];

	}
#endif
#endif