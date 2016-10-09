/*小B的目的很简单:控制服务器的内存区域，试图在内存中装入从1到n之间的n个自然数，以覆盖内存区域。可能是小B对编程理解上的问题，病毒似乎没有完全成功。可能是由于保护机制的原因，内存写入只接受二进制的形式，所以十进制表达中除0和1之外的其他值都没有成功写入内存。小B希望知道，究竟有多少数成功的写入了服务器的内存！
输入
输入中有多组测试数据。每组测试数据在单独的一行中，为整数n(1<=n <=10^9)。
输出
对每组测试数据，在单独的行中输出问题的答案。

样例输入
10
20
样例输出
2
3

Hint
对应n=10，成功写入的值为1和10。*/

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