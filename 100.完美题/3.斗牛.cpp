/*ֽ����Ϸ-��ţ
ʱ�����ƣ�C/C++���� 1000MS���������� 3000MS
�ڴ����ƣ�C/C++���� 65536KB���������� 589824KB
��Ŀ������
ֽ����Ϸ��ţ��ÿ�˷�5���ƣ�����ѡ���ż�������ʮ�ı�������Ϊ��ţ(J,Q,K��Ϊʮ)��Ȼ��Ƚ�ʣ�����ż�������λ���Ĵ�С����Ϊţ���������Ϊ10������������Ϊţ10��
���磺����ΪA��5,6��9��K��A+9+K=20����Ϊ��ţ����5+6=11����λ��Ϊ1����ţ��Ϊ1����
����Ϊ2,3,5,7,3��2+3+5=10��ţ����7+3=10��ţ10����
����Ϊ2,4,3,6,7,A���κ�3������Ӳ�Ϊ10������������Ϊ��ţ��
����
����5�����֣�A��J��Q��K����ĸ��ʾ��ע�⣺��������֮���á�,������
���
���ţ����ע�⣺��ţ�ʹ������none

��������
A��5,6��9��K
�������
1

Hint
����ѭ���жϼ��ɡ��ؼ���Ҫ�����쳣���������ͬ�������ֻ��4������������Ϸ��Լ��
*/
#include "iostream"
#include "string"
#include "vector"
#include "sstream"
#include "algorithm"

using namespace std;

int deal(vector<int> vec){
	sort(vec.begin(), vec.end());
	if (vec[0] == vec[1] && vec[1] == vec[2] && vec[2] == vec[3] && vec[3] == vec[4])
		return 0;
	int n = 4;
	while (vec[n] == 10) --n;
	for (int i = 0; i <= n ; ++i)
	{
	}
}
int main(){
	string str;
	while (getline(cin, str)){
		vector<int> vec;
		stringstream ss;
		ss.str("");
		ss << str;
		char ch;
		int flag = 1;
		while (ss >> ch){
			if (flag == 1){
				if (isdigit(ch))
					vec.push_back(ch - '0');
				else if (ch == 'A')
					vec.push_back(1);
				else 
					vec.push_back(10);
				flag = -1;
			}
			else{
				flag = 1;
				continue;
			}
		}
	/*	for (auto it : vec)
		{
			cout << ".." << it << endl;
		}*/
		int tn = deal(vec);
		if (tn == 0)
			cout << "none" << endl;
		else
			cout << tn << endl;
	}
	return 0;
}



#include<iostream>
using namespace std;
int isNiu(int* arr){
	int i = 0, j = 0, k = 0;
	bool flag = 1;
	for (i = 0; i < 3; i++){
		for (j = i + 1; j < 4; j++){
			for (k = j + 1; k < 5; k++){
				if ((arr[i] + arr[j] + arr[k]) % 10 == 0){
					flag = 0;
					break;
				}
			}
			if (!flag) break;
		}
		if (!flag) break;
	}
	if (flag) return -1;
	int res = 0;
	for (int z = 0; z < 5; z++){
		if (z != i&&z != j&&z != k)
			res += arr[z];
	}
	if (res % 10 == 0) return 10;
	else return res % 10;
}
int main(){
	char c;
	int a[5];
	int i = 0;
	while (cin >> c)
	{
		if (c == 'A')
		{
			a[i++] = 1;
		}
		else if (c == 'J')
		{
			a[i++] = 10;
		}
		else if (c == 'Q')
		{
			a[i++] = 10;
		}
		else if (c == 'K')
		{
			a[i++] = 10;
		}
		else if (c == '1')
		{
			if (cin.get() != '0')
			{
				cout << "none" << endl;
				return 0;
			}
			a[i++] = 10;
		}
		else if (c >= '2'&&c <= '9')
		{
			a[i++] = c - '0';
		}
		else
		{
			cout << "none" << endl;
			return 0;
		}
		if (cin.get() == '\n')
			break;
	}
	int res = isNiu(a);
	if (res == -1)cout << "none" << endl;
	else cout << res << endl;
	return 0;
}

