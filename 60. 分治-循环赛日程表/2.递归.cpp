#ifdef a
#include<iostream>  
#include<vector>  
#include<iterator>  
#include<algorithm>  
using namespace std;

/*
*ѭ�����ճ̱��ݹ鷨��
*/

void Copy(int **map, int sr, int sl, int dr, int dl, int k)
{
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			map[dr + i][dl + j] = map[sr + i][sl + j];
		}
	}
}

void Table(int **map, int r, int l, int k)
{
	if (1 == k)return;
	//������Ͻ�  
	Table(map, r, l, k / 2);
	//������Ͻ�  
	Table(map, r, l + (k / 2), k / 2);
	//�����Ͻǿ��������½�  
	Copy(map, r, l, r + k / 2, l + k / 2, k / 2);
	//�����Ͻǿ��������½�  
	Copy(map, r, l + k / 2, r + k / 2, l, k / 2);
}

int main()
{
	int k;
	//�����˶�Ա������  
	cout << "�˶�Ա������2��N�η���4,8,..." << endl;
	cin >> k;
	int ** p = new int*[k];
	//���̱��ʼ��  
	for (int i = 0; i < k; i++)
	{
		p[i] = new int[k];
		p[0][i] = i + 1;
		p[i][0] = i + 1;
	}
	//���к���  
	Table(p, 0, 0, k);
	//������  
	cout << "ѭ�����ճ̱��ݹ鷨��:" << endl;
	for (int i = 0; i < k; i++)
	{
		copy(p[i], p[i] + k, ostream_iterator<int>(cout, " "));
		cout << endl;
	}
	return 0;
}
#endif