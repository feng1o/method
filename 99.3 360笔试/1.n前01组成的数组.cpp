/*СB��Ŀ�ĺܼ�:���Ʒ��������ڴ�������ͼ���ڴ���װ���1��n֮���n����Ȼ�����Ը����ڴ����򡣿�����СB�Ա������ϵ����⣬�����ƺ�û����ȫ�ɹ������������ڱ������Ƶ�ԭ���ڴ�д��ֻ���ܶ����Ƶ���ʽ������ʮ���Ʊ���г�0��1֮�������ֵ��û�гɹ�д���ڴ档СBϣ��֪���������ж������ɹ���д���˷��������ڴ棡
����
�������ж���������ݡ�ÿ����������ڵ�����һ���У�Ϊ����n(1<=n <=10^9)��
���
��ÿ��������ݣ��ڵ����������������Ĵ𰸡�

��������
10
20
�������
2
3

Hint
��Ӧn=10���ɹ�д���ֵΪ1��10��*/

#if 0

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "climits"


using namespace std;

int main(){
	char in[11];
	char dataTmp[11];
	for (int i = 0; i < 10; i++)
	{
		in[i] = '0';
	}

	in[10] = '\0';

	dataTmp[10] = '\0';
	vector<int> ivec;
	ivec.push_back(0);
	while (1)
	{
		if (in[0] == '0')
		{
			in[0] = '1';
			for (int i = 0; i < 10; i++)
				dataTmp[i] = in[9 - i];
			ivec.push_back(atoi(dataTmp));
		}
		else
		{
			in[0] = '0';
			int i;
			for (i = 1; i < 11; i++){
				if (in[i] == '0')
					break;
				in[i] = '0';
			}
			if (i == 11)
				break;
			in[i] = '1';
			for (int j = 0;  j< 10; j++){
				dataTmp[j] = in[9 - j];
			}
			ivec.push_back(atoi(dataTmp));
		}
	}
	vector<int> input;
	int tmp;
	while (cin >> tmp){
		input.push_back(tmp);
	}
	for (auto it = input.begin(); it != input.end(); it++){
		auto it2 = upper_bound(ivec.begin(), ivec.end(), *it);
		cout << it2 - ivec.begin() - 1 << endl;
	}
	return 0;
}
#endif