#if 0

//http://blog.tk-xiong.com/archives/1027
/*
[�����|20��] ��ƻ��
ʱ�����ƣ�1��
�ռ����ƣ�32768K

��Ŀ������
С��ȥ�������̵���ƻ������թ���̷�ʹ���������ף�ֻ�ṩ6��ÿ����8��ÿ���İ�װ(��װ���ɲ��)��
����С������ֻ�빺��ǡ��n��ƻ����С���빺�����ٵĴ�������Я����
������ܹ���ǡ��n��ƻ����С�׽����Ṻ��

��������:
����һ������n����ʾС���빺��n(1 �� n �� 100)��ƻ��

���������
���һ��������ʾ������Ҫ����Ĵ��������������ǡ��n��ƻ�������-1

����������
20

���������
3
*/
#include "iostream"
#include "vector"

using namespace std;

int deal(int n, int cnt){
	
	if (n == 0)
		return cnt;
	if (n < 0)
		return -1;
	int tmp = 0;
	//cout << n << endl;
	tmp = deal(n - 8, cnt + 1);
	//cout << "     " << n << endl;
	if (tmp > 0)
		return  tmp;
	return deal(n - 6, cnt + 1);
	//cout <<">>"<< n << endl;

}
int Ans[101];

//Ԥ����
//tip������һ������N,������a1<a2����a1��a2����������������N����ô��ô�죿
void Begin()
{
	//�������е�ֵ
	for (int i = 1; i <= 100; i++)
	{
		Ans[i] = 32768;
		//����6��ƻ��װ�� - �ж�8��ƻ��װ������
		for (int j6 = 0; j6 <= i / 6; j6++)  //��һ����⡣������������
		{
			int others = i - j6 * 6;
			if (others % 8 == 0)
			{
				int all = j6 + others / 8;
				if (Ans[i] > all)
				{
					Ans[i] = all;
				}
			}
		}
		if (Ans[i] == 32768)
		{
			Ans[i] = -1;
		}
	}
}
int main(){
	Begin();
	int n; 
	while (cin >> n){
		cout << "...." << Ans[n] << endl;
		if (n % 2 == 1)
		{
			cout << -1 << endl;
			continue;
		}
		cout << deal(n, 0) << endl;
	}
	return 0;
}
#endif