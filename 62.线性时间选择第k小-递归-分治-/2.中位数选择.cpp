//2d9-2 ��λ������ʱ��ѡ��  
#include <ctime>  
#include <iostream>   
using namespace std;

template <class Type>
void Swap(Type &x, Type &y);

inline int Random(int x, int y);

template <class Type>
void BubbleSort(Type a[], int p, int r);

template <class Type>
int Partition(Type a[], int p, int r, Type x);

template <class Type>
Type Select(Type a[], int p, int r, int k);

int main()
{
	//��ʼ������  
	int a[100];

	//�������ѭ��������  
	srand((unsigned)time(0));

	for (int i = 0; i < 100; i++)
	{
		a[i] = Random(0, 500);
		cout << "a[" << i << "]:" << a[i] << " ";
	}
	cout << endl;

	cout << "��83СԪ����" << Select(a, 0, 99, 83) << endl;

	//�������򣬶ԱȽ��  
	BubbleSort(a, 0, 99);

	for (int i = 0; i < 100; i++)
	{
		cout << "a[" << i << "]:" << a[i] << " ";
	}
	cout << endl;
}

template <class Type>
void Swap(Type &x, Type &y)
{
	Type temp = x;
	x = y;
	y = temp;
}

inline int Random(int x, int y)
{
	int ran_num = rand() % (y - x) + x;
	return ran_num;
}

//ð������  
template <class Type>
void BubbleSort(Type a[], int p, int r)
{
	//��¼һ�α������Ƿ���Ԫ�صĽ���     
	bool exchange;
	for (int i = p; i <= r - 1; i++)
	{
		exchange = false;
		for (int j = i + 1; j <= r; j++)
		{
			if (a[j] < a[j - 1])
			{
				Swap(a[j], a[j - 1]);
				exchange = true;
			}
		}
		//�����α���û��Ԫ�صĽ���,��ô�������     
		if (false == exchange)
		{
			break;
		}
	}
}

template <class Type>
int Partition(Type a[], int p, int r, Type x)
{
	int i = p - 1, j = r + 1;

	while (true)
	{
		while (a[++i] < x && i < r);
		while (a[--j] > x);
		if (i >= j)
		{
			break;
		}
		Swap(a[i], a[j]);
	}
	return j;
}


template <class Type>
Type Select(Type a[], int p, int r, int k)
{
	if (r - p < 75)
	{
		BubbleSort(a, p, r);
		return a[p + k - 1];
	}
	//(r-p-4)/5�൱��n-5  
	for (int i = 0; i <= (r - p - 4) / 5; i++)
	{
		//��Ԫ��ÿ5���ֳ�һ�飬�ֱ����򣬲���������λ����a[p+i]����λ��  
		//ʹ������λ������������������࣬�Ա��һ��������λ������λ��  
		BubbleSort(a, p + 5 * i, p + 5 * i + 4);
		Swap(a[p + 5 * i + 2], a[p + i]);
	}
	//����λ������λ��  
	Type x = Select(a, p, p + (r - p - 4) / 5, (r - p - 4) / 10);
	int i = Partition(a, p, r, x);
	int j = i - p + 1;
	if (k <= j)
	{
		return Select(a, p, i, k);
	}
	else
	{
		return Select(a, i + 1, r, k - j);
	}
}