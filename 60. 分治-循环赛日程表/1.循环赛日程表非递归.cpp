#if 01

/**
���η���ѭ�������ճ̱�
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
	int n = 1; //n=2k(k>=1)��ѡ�ֲμӱ���
	for (int i = 1; i <= k; i++)
		n *= 2;
	int **a = new int *[n + 1];//����n��̬�����ά����a
	for (int i = 0; i <= n; i++)
	{
		a[i] = new int[n + 1];
	}
	Table(k, n, a);
	printf("ѭ�������ճ̱�Ϊ��\n");
	output(a, n);
	for (int i = 0; i <= n; i++){
		delete[] a[i];
	}
	delete[] a;

	return 0;
}

void input(int &k)
{
	printf("������kֵ��\n");
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
		a[1][i] = i;//�����ճ̱��һ��

	int m = 1;//ÿ�����ʱ����ʼ���λ��
	for (int s = 1; s <= k; s++)
	{
		n /= 2;
		for (int t = 1; t <= n; t++)  //��1-n/2,,1-n/4...
		{
			for (int i = m + 1; i <= 2 * m; i++)//������
			{
				for (int j = m + 1; j <= 2 * m; j++)//������
				{
					a[i][j + (t - 1)*m * 2] = a[i - m][j + (t - 1)*m * 2 - m];//���½ǵ������Ͻǵ�ֵ
					a[i][j + (t - 1)*m * 2 - m] = a[i - m][j + (t - 1)*m * 2];//���½ǵ������Ͻǵ�ֵ
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
	n = 2;//k=0��������ѡ���ճ̿���ֱ�����
	a[1][1] = 1; a[1][2] = 2;
	a[2][1] = 2; a[2][2] = 1;
	for (t = 1; t < k; t++)//�����������δ���2^n....2^k��ѡ�ֵı����ճ�
	{
		temp = n; n = n * 2;//�����½�Ԫ��
		for (i = temp + 1; i <= n; i++)
			for (j = 1; j <= temp; j++)
				a[i][j] = a[i - temp][j] + temp;//���½Ǻ����Ͻ�Ԫ�صĶ�Ӧ��ϵ
		for (i = 1; i <= temp; i++)//�����½�Ԫ�س������Ͻ�
			for (j = temp + 1; j <= n; j++)
				a[i][j] = a[i + temp][(j + temp) % n];
		for (i = temp + 1; i <= n; i++)//�����Ͻ�Ԫ�س������½�
			for (j = temp + 1; j <= n; j++)
				a[i][j] = a[i - temp][j - temp];

	}
#endif
#endif