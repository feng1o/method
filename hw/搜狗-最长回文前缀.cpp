#if 0

//http://blog.tk-xiong.com/archives/1017
/*

��һ���ַ�����������ǰ׺���ȡ�������ָ���������������һ�����ַ��������硰abcdcba������һ�����ġ�
����
һ���ı��ļ������ٰ���һ���ֽڡ�ÿ���ֽ���һ���ַ�����󳤶ȿ����м�ʮ���ֽڡ�
���
������ǰ׺�ĳ��ȡ�
��������
sogou
�������
1
���������
��ĿҪ�ʵ��� ��� ���� ǰ׺ ����
����������� �ַ���������ǰ׺������Ļ���
��ô����Щ��ǰ׺�أ�������Ϊ��������5��ǰ׺
sogou
sogo
sog
so
s

*/
#include <iostream>
#include <string>
#include <algorithm>
#include "vector"

using namespace std;

string findLongestPalindrome(string &s)
{
	const int length = s.size();
	int maxlength = 0;
	int start;
	//bool P[50][50] = { false };
	vector<vector<bool> > P(length + 1,vector<bool>(length+1, false));
	for (int i = 0; i < length; i++)//��ʼ��׼��  
	{
		//cout << "test.. :" << i << "\n";
		P[i][i] = true;
		if (i < length - 1 && s.at(i) == s.at(i + 1))
		{
			P[i][i + 1] = true;
			start = i;
			maxlength = 2;
		}
	}
	for (int len = 3; len < length; len++)//�Ӵ�����  
		for (int i = 0; i <= length - len; i++)//�Ӵ���ʼ��ַ  
		{
			int j = i + len - 1;//�Ӵ�������ַ  
			if (P[i + 1][j - 1] && s.at(i) == s.at(j))
			{
				P[i][j] = true;
				maxlength = len;
				start = i;
			}
		}
	if (maxlength >= 2)
		return s.substr(start, maxlength);
	return NULL;
}
int main()
{

	string str;
	int maxlength = 1;
	while (getline(cin, str)){
		
		string str1;
		string str2;
		string maxstring;
		for (int i = 0; i < str.size() - 1; i++)
		{
			for (int j = 2; j <= str.size() - i; j++)
			{
				str1 = str.substr(i, j);
				str2 = str1;
				reverse(str1.begin(), str1.end());
				if (str1 == str2)
				{
					if (str2.size() > maxlength)
					{
						maxlength = str2.size();
						maxstring = str2;
					}

				}
			}
		}
		//cout << maxstring << endl;
		cout << str.find(maxstring) << endl;
		
		//cout << findLongestPalindrome(str) << endl;
	}
	return 0;

}




#endif 


#if 0
string search(vector<int>& vec, int n, int index, string str){
	int pos = 90;
	int lhs = 0;
	int rhs = 180;
	while (index < 7){
		pos = (lhs + rhs) / 2;
		if (n < vec[pos]){
			str = str + "0";
			rhs = pos;
		}
		else {
			str = str + "1";
			lhs = pos;
		}
		++index;
	}
	return str;
}
int main()
{
	vector<int> vec(181, 0);
	int begin = -90;
	for (int i = 0; i < 181; ++i)
	{
		vec[i] = begin + i;
	}
	int n;
	while (cin >> n){
		string str = "";
		cout << search(vec, n, 1, str) << endl;
	}
}
#endif