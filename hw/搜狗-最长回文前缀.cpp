#if 0

//http://blog.tk-xiong.com/archives/1017
/*

求一个字符串的最大回文前缀长度。回文是指正反方向读起来都一样的字符串，比如“abcdcba”就是一个回文。
输入
一个文本文件，至少包含一个字节。每个字节是一个字符。最大长度可能有几十万字节。
输出
最大回文前缀的长度。
样例输入
sogou
样例输出
1
题意解析：
题目要问的是 最大 回文 前缀 长度
翻译过来就是 字符串的所有前缀里面最长的回文
那么，哪些是前缀呢，以样例为例，它有5个前缀
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
	for (int i = 0; i < length; i++)//初始化准备  
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
	for (int len = 3; len < length; len++)//子串长度  
		for (int i = 0; i <= length - len; i++)//子串起始地址  
		{
			int j = i + len - 1;//子串结束地址  
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