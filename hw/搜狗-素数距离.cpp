#define  _CRT_SECURE_NO_WARNINGS

#if 01
//http://blog.tk-xiong.com/archives/1017
/*
������������2��ż��֮��ľ��룬Ϊ��������֮�������ĸ�����
��С��������n������2��ż�����������������֮�������ܺͣ�Ӧ����n*(n-1)/2�����룬����ܺ;ͺ�)��
����
��һ��������ż���ĸ�������СΪ2�������ܵ�����
֮��ÿ��Ϊһ��ż������С��4���������Ǽ����򣬲��ظ����������С�
���
�������������������ܺͣ���Ӧ����һ����С��0��������
��������
3
4
6
12
�������
6
*/

#include <iostream>
#include <iomanip>        
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <cassert>
#include <climits>
#include <ctime>
#include <vector> 
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <numeric>
#include <sstream>
#include <set>
#include <utility>
#include <deque>
#include <functional>
#include <iterator>
using namespace std;

typedef long long LL;
typedef unsigned int UInt;
typedef unsigned long long ULL;
typedef long double LD;

int HashSu[10000010];    //1000W
vector <int> su;
vector <int> V;
vector <int> Num;

//��� 
int CalSu(int n)
{
	for(int i=0;i<=n;i++)
	{
		HashSu[i] = -1;
	}
	HashSu[0] = 0;
	HashSu[1] = 0;
	HashSu[2] = 1;    //2�ǵ�һ������
	for(int i = 2; i <= n; i++)
	{
		if(HashSu[i] != 0)
		{
			HashSu[i] = 1;
			su.push_back(i);
			for(int j = 2; i * j<= n; j++)
			{
				HashSu[i*j] = 0;
			}
		}
	}
	return 0;
}

vector<bool> isPrim(int len){
	vector<bool> flag(len, true);
	for (int i = 2; i < len ; ++i)
	{
		if (flag[i] == true)
		for (int j = i + i; j < len; j=j+i)
		{
			flag[j] = false;
		}
	}
	return flag;
}

int main(){
	int n;
	while (cin >> n){
		vector<int> vec;
		int max = 0;			
		
		V.clear();
		Num.clear();
		su.clear();

		for (int i = 0; i < n; ++i){
			int tmp;
			cin >> tmp;
			if (tmp > max)
				max = tmp;
			vec.push_back(tmp);


			V.push_back(tmp);
			Num.push_back(0);
		}
		//sort(vec.begin(), vec.end());

		vector<bool> flag = isPrim(max+1);
		int result = 0;
		CalSu(max + 1);
		for (int i = 0; i < n-1; ++i)
		{
			for (int lhs = vec[i]; lhs < vec[i + 1]; ++lhs)
			{
				if (flag[lhs])
				{
					//cout << "lhs =" << lhs << flag[lhs] << endl;
					result += (n - i - 1) + i*(n - i - 1);
					cout << "resul= " << result << "   " << lhs << endl;
				}
			}
		}
		cout << result << endl;
		

		//�жϴ� Num[i-1] �� Num[i] ���ж������� - ��¼�� Num[i] �� 
		int key = 1;
		for(int i = 1; i < su.size() && su[i] <= max; i++)
		{
			//���ֵ�Ƚ�С
			if(su[i] < V[key] && su[i] > V[key-1])
			{
				Num[key] += 1;
			}
			else if(su[i] > V[key])
			{
				key++;
				i--;
			}
		}

		//����ǰ׺��  
		for (int i = 1; i < Num.size(); i++)
		{
			Num[i] += Num[i - 1];
		}

		//������ - ���ᳬʱŶ 
		LL ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				ans += (Num[j] - Num[i]);
			}
		}
		cout << "ans= " << ans << endl;
	}
}
#endif

/*
#include "iostream"
#include "algorithm"
#include "string"

using namespace  std;

	bool match(char* str, char* pattern){
		if (*str == '\0' && '\0' == *pattern)
			return true;
		if (*str != '\0' && '\0' == *pattern)
			return false;
		// if(*str == *pattern || (*str != '\0' && *pattern == '?' ))
		//     return match2(str+1, pattern + 1);
		if (*pattern == '*' && *++pattern == '\0'){
			//cout << "xx\n";
			return true;
		}
		if (*(pattern + 1) == '*'){
			if (*str == *pattern || (*pattern == '?' && *str != '\0')){
				if (*(pattern + 2) == '\0')
					return true;
				return match(str + 1, pattern + 2) || match(str, pattern + 2) || match(str + 1, pattern) || match(str+1, pattern);
			}
			else
				return match(str, pattern + 2);
		}
		if (*str == *pattern || (*str != '\0' && *pattern == '?'))
			return match(str + 1, pattern + 1);
		return false;
	}
int main()
{
	string str;
	string pattern;
	while (cin >> str >> pattern){
		string::iterator it = pattern.begin();
		int  pos = 0;
		do{
			pos = pattern.find("?*");
			if (pos != string::npos)
				pattern.erase(it+pos);
			else
				break;
			*(it + pos) = '?';
			//cout << pattern << endl;
		} while (1);
		
		do{
			pos = pattern.find("*?");
			if (pos != string::npos)
				pattern.erase(it + pos );
			else
				break;
			*(it + pos ) = '?';
			//cout << pattern << endl;
		} while (1);

		cout << match(const_cast<char*>(str.c_str()), const_cast<char*>(pattern.c_str())) << endl;
	}
	return 0;
}
*/

